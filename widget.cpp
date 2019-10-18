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

    // title
    QFont titleFont = QFont(openSansCondensed);
    titleFont.setPixelSize(60);
    ui->title->setFont(titleFont);
    ui->title->setAlignment(Qt::AlignRight);

    // sidebar
    ui->shape0->setFixedSize(69, 69);
    ui->shape1->setFixedSize(69, 69);
    ui->shape2->setFixedSize(69, 69);
    ui->shape3->setFixedSize(69, 69);
    ui->shape4->setFixedSize(69, 69);
    ui->shape5->setFixedSize(69, 69);
    ui->shape6->setFixedSize(69, 69);
    ui->colors->setFixedSize(69, 69);
    ui->sidebar->layout()->setAlignment(Qt::AlignRight);

    // board
    ui->board->setFixedSize(600, 600);
    ui->board->setRowCount(boardRows);
    ui->board->setColumnCount(boardColumns);
    ui->board->horizontalHeader()->hide();
    ui->board->verticalHeader()->hide();
    for (int row = 0; row < ui->board->rowCount(); row++) {
        for (int column = 0; column < ui->board->columnCount(); column++) {
            QTableWidgetItem *item = new QTableWidgetItem();
            ui->board->setItem(row, column, item);
        }
    }

    // controls
    ui->controls->layout()->setContentsMargins(0, 0, 0, 0);
    ui->controls->layout()->setSpacing(0);

    // about
    QFont aboutFont = QFont(openSansCondensed);
    aboutFont.setPixelSize(50);
    ui->about->setFont(aboutFont);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::render() {
    QBrush brush = QBrush(QColor(0, 0, 0));
    ui->board->itemAt(0, 0)->setBackground(brush);
    for (int row = 0; row < game.board.size(); row++) {
        for (int column = 0; column < game.board[0].size(); column++) {
            QColor color = game.board[row][column].color.getQColor();
            qDebug() << color.red() << color.blue() << color.green() << game.board[row][column].state;
            ui->board->item(row, column)->setBackgroundColor(color);
        }
    }
}

void Widget::on_step_forward_pressed()
{

}

void Widget::on_pause_pressed()
{

}

void Widget::on_play_pressed()
{

}

void Widget::on_fast_forward_pressed()
{

}

void Widget::on_clear_pressed()
{

}

void Widget::on_random_pressed()
{
    game.random();
    qDebug() << game.board[0][0].state << game.board[0][1].state;
    render();
}
