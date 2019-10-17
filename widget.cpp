#include "widget.h"
#include "ui_widget.h"

#include <QTableWidget>
#include <QFile>
#include <QDebug>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFontDatabase>
#include <QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QFile file("stylesheet.qss");
    file.open(QIODevice::ReadOnly);
    QString stylesheet = QLatin1String(file.readAll());
    setStyleSheet(stylesheet);

    // set font, as this (unfortunately) cannot be done with stylesheets
    int id = QFontDatabase::addApplicationFont("open_sans_condensed_light.ttf");
    QString openSansCondensed = QFontDatabase::applicationFontFamilies(id).at(0);

    simcellular = new QGridLayout(this);

    title = new QLabel("simcellular");
    QFont titleFont = QFont(openSansCondensed);
    titleFont.setPixelSize(60);
    title->setFont(titleFont);
    title->setStyleSheet("background-color: red;");
    simcellular->addWidget(title, 0, 1, 4, 2);

    board = new QTableWidget(10, 10);
//    board->setFixedSize(600, 600);
    board->horizontalHeader()->setDefaultSectionSize(3);
    board->horizontalHeader()->hide();
    board->verticalHeader()->setDefaultSectionSize(3);
    board->verticalHeader()->hide();
    simcellular->addWidget(board, 1, 1, 4, 2);


    about = new QLabel("about");
    QFont aboutFont = QFont(openSansCondensed);
    aboutFont.setPixelSize(50);
    about->setFont(aboutFont);
    about->setStyleSheet("background-color: red;");
    simcellular->addWidget(about, 3, 1, 4, 2);

    shape0 = new QTableWidget(1, 1);
    shape1 = new QTableWidget(1, 1);
    shape2 = new QTableWidget(1, 1);
    shape3 = new QTableWidget(1, 1);
    shape4 = new QTableWidget(1, 1);
    shape5 = new QTableWidget(1, 1);
    shape6 = new QTableWidget(1, 1);
    colors = new QTableWidget(2, 2);

    shape0->setFixedSize(63, 63);
    shape1->setFixedSize(63, 63);
    shape2->setFixedSize(63, 63);
    shape3->setFixedSize(63, 63);
    shape4->setFixedSize(63, 63);
    shape5->setFixedSize(63, 63);
    shape6->setFixedSize(63, 63);
    colors->setFixedSize(63, 63);

    sidebar = new QVBoxLayout();
    sidebar->addWidget(shape0);
    sidebar->addWidget(shape1);
    sidebar->addWidget(shape2);
    sidebar->addWidget(shape3);
    sidebar->addWidget(shape4);
    sidebar->addWidget(shape5);
    sidebar->addWidget(shape6);
    sidebar->addWidget(colors);

    simcellular->addLayout(sidebar, 1, 0, 4, 2);

    stepForward = new QToolButton();
    pause = new QToolButton();
    play = new QToolButton();
    fastForward = new QToolButton();
    clear = new QToolButton();
    random = new QToolButton();

    controls = new QHBoxLayout();
    controls->addWidget(stepForward);
    controls->addWidget(pause);
    controls->addWidget(play);
    controls->addWidget(fastForward);
    controls->addWidget(clear);
    controls->addWidget(random);

    simcellular->addLayout(controls, 2, 1, 4, 2);


//    QVBoxLayout *sidebar = new QVBoxLayout;

//    setLayout(sidebar);

//    boardWidget = new QTableWidget(200, 200, this);
}

Widget::~Widget()
{
    delete ui;
}

