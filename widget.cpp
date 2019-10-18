#include "widget.h"
#include "ui_widget.h"

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

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile file("stylesheet.qss");
    file.open(QIODevice::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    this->setStyleSheet(stylesheet);

    // set font, as this (unfortunately) cannot be done with stylesheets
    int id = QFontDatabase::addApplicationFont("open_sans_condensed_light.ttf");
    QString openSansCondensed = QFontDatabase::applicationFontFamilies(id).at(0);

//    QGridLayout *simcellularLayout = new QGridLayout(this);
//    simcellularLayout->setContentsMargins(0, 0, 0, 0);
//    simcellularLayout->setSpacing(0);
//    simcellularLayout->setColumnStretch(0, 1);
//    simcellularLayout->setColumnStretch(1, 1);

//    title = new QLabel("simcellular");
    QFont titleFont = QFont(openSansCondensed);
    titleFont.setPixelSize(60);
    ui->title->setFont(titleFont);
//    title->setStyleSheet("background-color: red;");
//    simcellularLayout->addWidget(title, 0, 1, 4, 2);

//    board = new QFrame();
    ui->board->setFixedSize(600, 600);
//    board->setStyleSheet("background-color: green; padding: 0px;");
//    QSizePolicy sizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
//    board->setSizePolicy(sizePolicy);
//    QGridLayout *boardLayout = new QGridLayout(ui->board);
//    boardLayout->setContentsMargins(0, 0, 0, 0);
//    boardLayout->setSpacing(0);
//    ui->board->setContentsMargins(0, 0, 0, 0);
//    for (int row = 0; row < 20; row++) {
//        for (int column = 0; column < 20; column++) {
//            QFrame *cell = new QFrame();
//            cell->setStyleSheet("background-color: blue; border: none; margins: 0px;");
//            cell->setFixedSize(31, 31);
//            boardLayout->addWidget(cell, row, column, 20, 20);
//        }
//    }

//    QSpacerItem *horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);
//    boardLayout->addItem(horizontalSpacer, 0, 20, 21, 21);
//    simcellularLayout->addWidget(board, 1, 1, 4, 2);


//    about = new QLabel("about");
    QFont aboutFont = QFont(openSansCondensed);
    aboutFont.setPixelSize(50);
    ui->about->setFont(aboutFont);
//    ui->about->layout()->setContentsMargins(0, 0, 0, 0);
//    ui->about->layout()->setSpacing(0);
    ui->about->setContentsMargins(0, 0, 0, 0);

    ui->controls->setContentsMargins(0, 0, 0, 0);
    ui->controls->layout()->setContentsMargins(0, 0, 0, 0);
    ui->controls->layout()->setSpacing(0);

    ui->title->setAlignment(Qt::AlignRight);

//    layout()->setContentsMargins(0, 0, 0, 0);
//    setContentsMargins(0, 0, 0, 0);
//    about->setStyleSheet("background-color: red;");
//    simcellularLayout->addWidget(about, 3, 1, 4, 2);

//    shape0 = new QFrame();
//    shape0->setFixedSize(63, 63);
//    shape0->setStyleSheet("background-color: red");
//    shape1 = new QFrame();
//    shape1->setFixedSize(63, 63);
//    shape1->setStyleSheet("background-color: red");
//    shape2 = new QFrame();
//    shape2->setFixedSize(63, 63);
//    shape2->setStyleSheet("background-color: red");
//    shape3 = new QFrame();
//    shape3->setFixedSize(63, 63);
//    shape3->setStyleSheet("background-color: red");
//    shape4 = new QFrame();
//    shape4->setFixedSize(63, 63);
//    shape4->setStyleSheet("background-color: red");
//    shape5 = new QFrame();
//    shape5->setFixedSize(63, 63);
//    shape5->setStyleSheet("background-color: red");
//    shape6 = new QFrame();
//    shape6->setFixedSize(63, 63);
//    shape6->setStyleSheet("background-color: red");
//    colors = new QFrame();
//    colors->setFixedSize(63, 63);
//    colors->setStyleSheet("background-color: red");

//    QGridLayout *shape0Layout = new QGridLayout(shape0);
//    QGridLayout *shape1Layout = new QGridLayout(shape1);
//    QGridLayout *shape2Layout = new QGridLayout(shape2);
//    QGridLayout *shape3Layout = new QGridLayout(shape3);
//    QGridLayout *shape4Layout = new QGridLayout(shape4);
//    QGridLayout *shape5Layout = new QGridLayout(shape5);
//    QGridLayout *shape6Layout = new QGridLayout(shape6);
//    QGridLayout *colorsLayout = new QGridLayout(colors);

////    sidebar = new QFrame();
//    QVBoxLayout *sidebarLayout = new QVBoxLayout(ui->sidebar);
//    sidebarLayout->addWidget(shape0);
//    sidebarLayout->addWidget(shape1);
//    sidebarLayout->addWidget(shape2);
//    sidebarLayout->addWidget(shape3);
//    sidebarLayout->addWidget(shape4);
//    sidebarLayout->addWidget(shape5);
//    sidebarLayout->addWidget(shape6);
//    sidebarLayout->addWidget(colors);

//    simcellularLayout->addWidget(sidebar, 1, 0, 4, 2);

//    ui->step_forward->setIcon(QIcon("step_forward.png"));

//    stepForward = new QToolButton();
//    pause = new QToolButton();
//    play = new QToolButton();
//    fastForward = new QToolButton();
//    clear = new QToolButton();
//    random = new QToolButton();

//    controls = new QFrame();
//    QHBoxLayout *controlsLayout = new QHBoxLayout(ui->controls);
//    controlsLayout->addWidget(stepForward);
//    controlsLayout->addWidget(pause);
//    controlsLayout->addWidget(play);
//    controlsLayout->addWidget(fastForward);
//    controlsLayout->addWidget(clear);
//    controlsLayout->addWidget(random);

//    simcellularLayout->addWidget(controls, 2, 1, 4, 2);


//    QVBoxLayout *sidebar = new QVBoxLayout;

//    setLayout(sidebar);

//    boardWidget = new QGridLayout(200, 200, this);
}

Widget::~Widget()
{
    delete ui;
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
