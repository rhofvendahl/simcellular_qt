#include "headers/widget.h"
#include "ui_widget.h"
#include "headers/game.h"
#include "headers/color.h"

#include <QFile>
#include <QDebug>
#include <QFontDatabase>
#include <QIcon>
#include <QColor>
#include <QTableWidgetItem>
#include <QString>
#include <QModelIndex>
#include <QDesktopServices>
#include <QUrl>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    QFile file("../resources/stylesheet.qss");
    file.open(QIODevice::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    this->setStyleSheet(stylesheet);

    int id = QFontDatabase::addApplicationFont("../resources/open_sans_condensed_light.ttf");
    QString openSansCondensed = QFontDatabase::applicationFontFamilies(id).at(0);

    game = new Game(boardRows, boardColumns);
    library = new Library();

     transitionTimer = new QTimer(this);
    connect(transitionTimer, SIGNAL(timeout()), this, SLOT(transitionHandler()));

//     title
    QFont titleFont = QFont(openSansCondensed);
    titleFont.setPixelSize(60);
    ui->title->setFont(titleFont);
    ui->title->setAlignment(Qt::AlignRight);

    // sidebar
    ui->sidebar->layout()->setAlignment(Qt::AlignRight);
    ui->sidebar->layout()->setSpacing(12);
    ui->sidebar->layout()->setContentsMargins(0, 0, 10, 0);

    // colors
    ui->colors->setFixedSize(64, 64);
    ui->colors->setRowCount(2);
    ui->colors->setColumnCount(2);
    ui->colors->horizontalHeader()->setVisible(false);
    ui->colors->verticalHeader()->setVisible(false);
    ui->colors->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->colors->setFocusPolicy(Qt::NoFocus);
    ui->colors->setSelectionMode(QAbstractItemView::NoSelection);
    ui->colors->setShowGrid(false);
    ui->colors->horizontalHeader()->setMinimumSectionSize(0);
    ui->colors->verticalHeader()->setMinimumSectionSize(0);
    ui->colors->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->colors->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //    ui->colors->setFrameStyle(QFrame::Box | QFrame::Plain);
    //    ui->colors->setFrameStyle(QFrame::NoFrame);
    ui->colors->setStyleSheet("border: none;");

    QTableWidgetItem *greenSquare = new QTableWidgetItem;
    ui->colors->setItem(0, 0, greenSquare);
    greenSquare->setBackgroundColor(Color::green->qColor());
    QTableWidgetItem *blueSquare = new QTableWidgetItem;
    ui->colors->setItem(0, 1, blueSquare);
    blueSquare->setBackgroundColor(Color::blue->qColor());
    QTableWidgetItem *redSquare = new QTableWidgetItem;
    ui->colors->setItem(1, 0, redSquare);
    redSquare->setBackgroundColor(Color::red->qColor());
    QTableWidgetItem *yellowSquare = new QTableWidgetItem;
    ui->colors->setItem(1, 1, yellowSquare);
    yellowSquare->setBackgroundColor(Color::yellow->qColor());
//    on_colors_cellPressed(0, 1); (trouble, as shapeTables not yet defined
    selectedColor = Color::blue;

        // shapes
        shapeTables += ui->shape0;
        shapeTables += ui->shape1;
        shapeTables += ui->shape2;
        shapeTables += ui->shape3;
        shapeTables += ui->shape4;
        shapeTables += ui->shape5;
        shapeTables += ui->shape6;

        for (int i = 0; i < library->shapes.size(); i++) {
            QList<QList<bool>> shape = library->shapes[i];
            shapeTables[i]->setFixedSize(64, 64);
            shapeTables[i]->setRowCount(shape.size());
            shapeTables[i]->setColumnCount(shape[0].size());
            shapeTables[i]->horizontalHeader()->setVisible(false);
            shapeTables[i]->verticalHeader()->setVisible(false);
            shapeTables[i]->setEditTriggers(QAbstractItemView::NoEditTriggers);
            shapeTables[i]->setFocusPolicy(Qt::NoFocus);
            shapeTables[i]->setSelectionMode(QAbstractItemView::NoSelection);
            shapeTables[i]->setShowGrid(false);
            shapeTables[i]->horizontalHeader()->setMinimumSectionSize(0);
            shapeTables[i]->verticalHeader()->setMinimumSectionSize(0);
            shapeTables[i]->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            shapeTables[i]->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
            for (int row = 0; row < shape.size(); row++) {
                for (int column = 0; column < shape[0].size(); column++) {
                    QTableWidgetItem *item = new QTableWidgetItem();

                    if (shape[row][column]) {
                       item->setBackgroundColor(selectedColor->qColor());
                   } else {
                       item->setBackgroundColor(Color::white->qColor());
                   }

                   shapeTables[i]->setItem(row, column, item);
               }
           }
       }
    // board
    ui->board->setFixedSize(600, 600);
    ui->board->setRowCount(boardRows);
    ui->board->setColumnCount(boardColumns);
    ui->board->horizontalHeader()->setVisible(false);
    ui->board->verticalHeader()->setVisible(false);
    ui->board->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->board->setFocusPolicy(Qt::NoFocus);
    ui->board->setSelectionMode(QAbstractItemView::NoSelection);
    ui->board->setShowGrid(false);
    ui->board->horizontalHeader()->setMinimumSectionSize(0);
    ui->board->verticalHeader()->setMinimumSectionSize(0);
    ui->board->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->board->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int row = 0; row < ui->board->rowCount(); row++) {
       for (int column = 0; column < ui->board->columnCount(); column++) {
           QTableWidgetItem *item = new QTableWidgetItem();
           ui->board->setItem(row, column, item);
       }
    }
    ui->board->setStyleSheet("border: 1px solid #808080; padding: 1px;");

    // controls
    ui->controls->layout()->setContentsMargins(0, 0, 0, 0);
    ui->controls->layout()->setSpacing(0);

    // about
    QFont aboutFont = QFont(openSansCondensed);
    aboutFont.setPixelSize(50);
    ui->about->setFont(aboutFont);

    on_random_pressed();
    prevCellPressed = nullptr;

    QTimer::singleShot(0, this, SLOT(on_shape0_pressed())); // workaround for ui issue
}

Widget::~Widget()
{
    delete ui;
}

QModelIndex Widget::tempIndex = *(new QModelIndex());

void Widget::render() {
    for (int row = 0; row < game->board.size(); row++) {
        for (int column = 0; column < game->board[0].size(); column++) {
            QColor color = game->board[row][column]->color->qColor();
            ui->board->item(row, column)->setBackgroundColor(color);
        }
    }
}

void Widget::on_step_forward_pressed()
{
    transitionTimer->stop();
    game->transition();
    render();
    const QModelIndex index; // not actually used, so ok blank
    on_shape0_pressed(index);
}

void Widget::on_pause_pressed()
{
    transitionTimer->stop();
}

void Widget::on_play_pressed()
{
    transitionTimer->start(playInterval);
}

void Widget::on_fast_forward_pressed()
{
    transitionTimer->start(fastForwardInterval);
}


void Widget::on_clear_pressed()
{
    transitionTimer->stop();
    game->clear();
    render();
}

void Widget::on_random_pressed()
{
    game->random();
    render();
}

void Widget::on_board_cellEntered(int row, int column)
{
    if (QApplication::mouseButtons() == Qt::LeftButton) {
        Cell *cell = game->board[row][column];
        if (cell != prevCellPressed) {
            on_board_cellPressed(row, column);
        }
    }
}

void Widget::on_board_cellPressed(int row, int column)
{
    Cell *cell = game->board[row][column];
    prevCellPressed = cell;
    if (selectedShapeIndex == 0) {
        if (cell->state) {
            cell->setNext(false);
        } else {
            cell->setNext(true, selectedColor);
        }
        cell->transition();
    } else {
        game->insert(cell, library->shapes[selectedShapeIndex], selectedColor);
    }
    render();
}

void Widget::transitionHandler() {
    game->transition();
    render();
}

void Widget::on_colors_cellPressed(int row, int column)
{
    if (row == 0 && column == 0) {
        selectedColor = Color::green;
    } else if (row == 0 && column == 1) {
        selectedColor = Color::blue;
    } else if (row == 1 && column == 0) {
        selectedColor = Color::red;
    } else {
        selectedColor = Color::yellow;
    }
    renderShapes();
}

void Widget::on_shape0_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 0;
    deSelectShapes();
    ui->shape0->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape1_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 1;
    deSelectShapes();
    ui->shape1->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape2_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 2;
    deSelectShapes();
    ui->shape2->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape3_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 3;
    deSelectShapes();
    ui->shape3->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape4_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 4;
    deSelectShapes();
    ui->shape4->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape5_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 5;
    deSelectShapes();
    ui->shape5->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::on_shape6_pressed(const QModelIndex &index)
{
    selectedShapeIndex = 6;
    deSelectShapes();
    ui->shape6->setStyleSheet("border: 1px solid #808080; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
}

void Widget::deSelectShapes() {
    QString deSelectedStyleSheet = QString("border: 1px solid white; padding-left: 1px; padding-top: 1px; padding-right: -2px; padding-bottom: -2px;");
    for (int i = 0; i < shapeTables.size(); i++) {
        shapeTables[i]->setStyleSheet(deSelectedStyleSheet);
    }
}

void Widget::renderShapes() {
    for (int i = 0; i < library->shapes.size(); i++) {
        QList<QList<bool>> shape = library->shapes[i];
        for (int row = 0; row < shape.size(); row++) {
            for (int column = 0; column < shape[0].size(); column++) {
                QTableWidgetItem *item = shapeTables[i]->item(row, column);
                qDebug() << i << row << column << shape[row][column];
                if (shape[row][column]) {
                   item->setBackgroundColor(selectedColor->qColor());
               }
           }
       }
   }
}

void Widget::on_about_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
    qDebug() << "about link activated";
}
