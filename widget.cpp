//#include "widget.h"
//#include "ui_widget.h"

//#include <QTableWidget>
//#include <QFile>
//#include <QDebug>
//#include <QGridLayout>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QLabel>
//#include <QFontDatabase>
//#include <QHeaderView>
//<<<<<<< Updated upstream
//=======
//#include <QSpacerItem>
//#include <QSizePolicy>
//#include <QIcon>
//#include <QBrush>
//#include <QColor>
//#include <QTableWidgetItem>
//#include <QTimer>
//>>>>>>> Stashed changes

//Widget::Widget(QWidget *parent)
//    : QWidget(parent)
//    , ui(new Ui::Widget)
//{
//    ui->setupUi(this);

//    QFile file("stylesheet.qss");
//    file.open(QIODevice::ReadOnly);
//    QString stylesheet = QLatin1String(file.readAll());
//    setStyleSheet(stylesheet);

//    // set font, as this (unfortunately) cannot be done with stylesheets
//    int id = QFontDatabase::addApplicationFont("open_sans_condensed_light.ttf");
//    QString openSansCondensed = QFontDatabase::applicationFontFamilies(id).at(0);

//<<<<<<< Updated upstream
//    simcellular = new QGridLayout(this);
//=======
//    game = new Game(boardRows, boardColumns);
//    library = new Library();
////    qDebug() << library->shapes[0][0][0];

//    transitionTimer = new QTimer(this);
//    connect(transitionTimer, SIGNAL(timeout()), this, SLOT(transitionHandler()));
//>>>>>>> Stashed changes

//    title = new QLabel("simcellular");
//    QFont titleFont = QFont(openSansCondensed);
//    titleFont.setPixelSize(60);
//<<<<<<< Updated upstream
//    title->setFont(titleFont);
//    title->setStyleSheet("background-color: red;");
//    simcellular->addWidget(title, 0, 1, 4, 2);

//    board = new QTableWidget(10, 10);
////    board->setFixedSize(600, 600);
//    board->horizontalHeader()->setDefaultSectionSize(3);
//    board->horizontalHeader()->hide();
//    board->verticalHeader()->setDefaultSectionSize(3);
//    board->verticalHeader()->hide();
//    simcellular->addWidget(board, 1, 1, 4, 2);


//    about = new QLabel("about");
//=======
//    ui->title->setFont(titleFont);
//    ui->title->setAlignment(Qt::AlignRight);

//    // sidebar
//    ui->sidebar->layout()->setAlignment(Qt::AlignRight);

//    // shapes
//    ui->shape0->setFixedSize(69, 69);
//    ui->shape1->setFixedSize(69, 69);
//    ui->shape2->setFixedSize(69, 69);
//    ui->shape3->setFixedSize(69, 69);
//    ui->shape4->setFixedSize(69, 69);
//    ui->shape5->setFixedSize(69, 69);
//    ui->shape6->setFixedSize(69, 69);
//    const QModelIndex index; // not actually used, so ok blank
//    on_shape0_pressed(index);

//    // colors
//    ui->colors->setFixedSize(69, 69);
//    ui->colors->setRowCount(2);
//    ui->colors->setColumnCount(2);
//    ui->colors->horizontalHeader()->setVisible(false);
//    ui->colors->verticalHeader()->setVisible(false);
//    ui->colors->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->colors->setFocusPolicy(Qt::NoFocus);
//    ui->colors->setSelectionMode(QAbstractItemView::NoSelection);
//    ui->colors->setShowGrid(false);
//    ui->colors->horizontalHeader()->setMinimumSectionSize(0);
//    ui->colors->verticalHeader()->setMinimumSectionSize(0);
//    ui->colors->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->colors->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
////    ui->colors->setFrameStyle(QFrame::Box | QFrame::Plain);
////    ui->colors->setFrameStyle(QFrame::NoFrame);
//    ui->colors->setStyleSheet("border: none;");

//    QTableWidgetItem *greenSquare = new QTableWidgetItem;
//    ui->colors->setItem(0, 0, greenSquare);
//    greenSquare->setBackgroundColor(Color::green->qColor());
//    QTableWidgetItem *blueSquare = new QTableWidgetItem;
//    ui->colors->setItem(0, 1, blueSquare);
//    blueSquare->setBackgroundColor(Color::blue->qColor());
//    QTableWidgetItem *redSquare = new QTableWidgetItem;
//    ui->colors->setItem(1, 0, redSquare);
//    redSquare->setBackgroundColor(Color::red->qColor());
//    QTableWidgetItem *yellowSquare = new QTableWidgetItem;
//    ui->colors->setItem(1, 1, yellowSquare);
//    yellowSquare->setBackgroundColor(Color::yellow->qColor());

//    selectedColor = Color::green;

//    // board
//    ui->board->setFixedSize(600, 600);
//    ui->board->setRowCount(boardRows);
//    ui->board->setColumnCount(boardColumns);
//    ui->board->horizontalHeader()->setVisible(false);
//    ui->board->verticalHeader()->setVisible(false);
//    ui->board->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    ui->board->setFocusPolicy(Qt::NoFocus);
//    ui->board->setSelectionMode(QAbstractItemView::NoSelection);
//    ui->board->setShowGrid(false);
//    ui->board->horizontalHeader()->setMinimumSectionSize(0);
//    ui->board->verticalHeader()->setMinimumSectionSize(0);
//    ui->board->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    ui->board->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//    for (int row = 0; row < ui->board->rowCount(); row++) {
//        for (int column = 0; column < ui->board->columnCount(); column++) {
//            QTableWidgetItem *item = new QTableWidgetItem();
//            ui->board->setItem(row, column, item);
//        }
//    }

//    // controls
//    ui->controls->layout()->setContentsMargins(0, 0, 0, 0);
//    ui->controls->layout()->setSpacing(0);

//    // about
//>>>>>>> Stashed changes
//    QFont aboutFont = QFont(openSansCondensed);
//    aboutFont.setPixelSize(50);
//    about->setFont(aboutFont);
//    about->setStyleSheet("background-color: red;");
//    simcellular->addWidget(about, 3, 1, 4, 2);

//    shape0 = new QTableWidget(1, 1);
//    shape1 = new QTableWidget(1, 1);
//    shape2 = new QTableWidget(1, 1);
//    shape3 = new QTableWidget(1, 1);
//    shape4 = new QTableWidget(1, 1);
//    shape5 = new QTableWidget(1, 1);
//    shape6 = new QTableWidget(1, 1);
//    colors = new QTableWidget(2, 2);

//    shape0->setFixedSize(63, 63);
//    shape1->setFixedSize(63, 63);
//    shape2->setFixedSize(63, 63);
//    shape3->setFixedSize(63, 63);
//    shape4->setFixedSize(63, 63);
//    shape5->setFixedSize(63, 63);
//    shape6->setFixedSize(63, 63);
//    colors->setFixedSize(63, 63);

//    sidebar = new QVBoxLayout();
//    sidebar->addWidget(shape0);
//    sidebar->addWidget(shape1);
//    sidebar->addWidget(shape2);
//    sidebar->addWidget(shape3);
//    sidebar->addWidget(shape4);
//    sidebar->addWidget(shape5);
//    sidebar->addWidget(shape6);
//    sidebar->addWidget(colors);

//    simcellular->addLayout(sidebar, 1, 0, 4, 2);

//    stepForward = new QToolButton();
//    pause = new QToolButton();
//    play = new QToolButton();
//    fastForward = new QToolButton();
//    clear = new QToolButton();
//    random = new QToolButton();

//    controls = new QHBoxLayout();
//    controls->addWidget(stepForward);
//    controls->addWidget(pause);
//    controls->addWidget(play);
//    controls->addWidget(fastForward);
//    controls->addWidget(clear);
//    controls->addWidget(random);

//    simcellular->addLayout(controls, 2, 1, 4, 2);


////    QVBoxLayout *sidebar = new QVBoxLayout;

////    setLayout(sidebar);

////    boardWidget = new QTableWidget(200, 200, this);
//}

//Widget::~Widget()
//{
//    delete ui;
//}

//<<<<<<< Updated upstream
//=======
//void Widget::render() {
//    QBrush brush = QBrush(QColor(0, 0, 0));
//    ui->board->itemAt(0, 0)->setBackground(brush);
//    for (int row = 0; row < game->board.size(); row++) {
//        for (int column = 0; column < game->board[0].size(); column++) {
//            QColor color = game->board[row][column]->color->qColor();
////            qDebug() << color.red() << color.blue() << color.green() << game->board[row][column].state;
//            ui->board->item(row, column)->setBackgroundColor(color);
//        }
//    }
//}

//void Widget::on_step_forward_pressed()
//{
//    qDebug() << "STEP FORWARD PRESSED!";
////    game->board[0][1]->color->setBlue();
////    game->board[0][0]->color->copy(game->board[0][1]->color);
//    game->transition();
////    qDebug() << game->board[0][0]->state << game->board[0][1]->state;
//    render();
//}

//void Widget::on_pause_pressed()
//{
//    transitionTimer->stop();
//}

//void Widget::on_play_pressed()
//{
//    transitionTimer->start(playInterval);
//}

//void Widget::on_fast_forward_pressed()
//{
//    transitionTimer->start(fastForwardInterval);
//}

//void Widget::on_clear_pressed()
//{
//    game->clear();
//    game->board[0][2]->setNext(true, Color::blue);
//    game->board[0][2]->transition();
//    game->board[1][0]->setNext(true, Color::blue);
//    game->board[1][0]->transition();
//    game->board[1][2]->setNext(true, Color::blue);
//    game->board[1][2]->transition();
//    game->board[2][1]->setNext(true, Color::blue);
//    game->board[2][1]->transition();
//    game->board[2][2]->setNext(true, Color::blue);
//    game->board[2][2]->transition();
//    render();
//}

//void Widget::on_random_pressed()
//{
//    game->random();
////    qDebug() << game->board[0][0]->state << game->board[0][1]->state;
//    render();
//}

//void Widget::on_board_cellEntered(int row, int column)
//{
//    if (selectedShape == 0) {
//        if (QApplication::mouseButtons() == Qt::LeftButton) {
//            Cell *cell = game->board[row][column];
//            if (cell->state) {
//                cell->setNext(false);
//            } else {
//                cell->setNext(true, selectedColor);
//            }
//            cell->transition();
//            render();
//        }
//    }
//}

//void Widget::transitionHandler() {
//    qDebug() << "handling transition";
//    game->transition();
//    render();
//}

//void Widget::on_colors_cellPressed(int row, int column)
//{
//    if (row == 0 && column == 0) {
//        selectedColor = Color::green;
//    } else if (row == 0 && column == 1) {
//        selectedColor = Color::blue;
//    } else if (row == 1 && column == 0) {
//        selectedColor = Color::red;
//    } else {
//        selectedColor = Color::yellow;
//    }
//}

//void Widget::on_board_cellPressed(int row, int column)
//{
//    if (selectedShape != 0) {

//    }
//}

//void Widget::on_shape0_pressed(const QModelIndex &index)
//{
//    qDebug() << "shape0 pressed";
//    selectedShape = 0;
//    deSelectShapes();
//    ui->shape0->setStyleSheet("");
//}

//void Widget::on_shape1_pressed(const QModelIndex &index)
//{
//    qDebug() << "shape1 pressed";
//    selectedShape = 1;
//    deSelectShapes();
//    ui->shape1->setStyleSheet("");
//}

//void Widget::on_shape2_pressed(const QModelIndex &index)
//{
//    selectedShape = 2;
//    deSelectShapes();
//    ui->shape2->setStyleSheet("");
//}

//void Widget::on_shape3_pressed(const QModelIndex &index)
//{
//    selectedShape = 3;
//    deSelectShapes();
//    ui->shape3->setStyleSheet("");
//}

//void Widget::on_shape4_pressed(const QModelIndex &index)
//{
//    selectedShape = 4;
//    deSelectShapes();
//    ui->shape4->setStyleSheet("");
//}

//void Widget::on_shape5_pressed(const QModelIndex &index)
//{
//    selectedShape = 5;
//    deSelectShapes();
//    ui->shape5->setStyleSheet("");
//}

//void Widget::on_shape6_pressed(const QModelIndex &index)
//{
//    selectedShape = 6;
//    deSelectShapes();
//    ui->shape6->setStyleSheet("");
//}

//void Widget::deSelectShapes() {
//    ui->shape0->setStyleSheet("border: none;");
//    ui->shape1->setStyleSheet("border: none;");
//    ui->shape2->setStyleSheet("border: none;");
//    ui->shape3->setStyleSheet("border: none;");
//    ui->shape4->setStyleSheet("border: none;");
//    ui->shape5->setStyleSheet("border: none;");
//    ui->shape6->setStyleSheet("border: none;");
//}
//>>>>>>> Stashed changes


#include "widget.h"
#include "ui_widget.h"
#include "game.h"
#include "color.h"

#include <QFile>
#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFontDatabase>
#include <QHeaderView>
#include <QSpacerItem>
#include <QSizePolicy>
#include <QIcon>
#include <QBrush>
#include <QColor>
#include <QTableWidgetItem>
#include <QString>

// TODO: make it easier to press-change cells

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile file("stylesheet.qss");
    file.open(QIODevice::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    this->setStyleSheet(stylesheet);

    int id = QFontDatabase::addApplicationFont("open_sans_condensed_light.ttf");
    QString openSansCondensed = QFontDatabase::applicationFontFamilies(id).at(0);

    game = new Game(boardRows, boardColumns);
    library = new Library();

        transitionTimer = new QTimer(this);
        connect(transitionTimer, SIGNAL(timeout()), this, SLOT(transitionHandler()));

    // title
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
    on_colors_cellPressed(0, 1);

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
//            shapeTables[i]->setContentsMargins(100, 100, 100, 100);

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

    const QModelIndex index; // not actually used, so ok blank
    on_shape0_pressed(index);
    on_random_pressed();
    prevCellPressed = nullptr;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::render() {
    QBrush brush = QBrush(QColor(0, 0, 0));
    ui->board->itemAt(0, 0)->setBackground(brush);
    for (int row = 0; row < game->board.size(); row++) {
        for (int column = 0; column < game->board[0].size(); column++) {
            QColor color = game->board[row][column]->color->qColor();
            ui->board->item(row, column)->setBackgroundColor(color);
        }
    }
}

void Widget::on_step_forward_pressed()
{
    game->transition();
    render();
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
