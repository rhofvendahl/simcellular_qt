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

    QGridLayout *simcellularLayout = new QGridLayout(this);

    title = new QLabel("simcellular");
    QFont titleFont = QFont(openSansCondensed);
    titleFont.setPixelSize(60);
    title->setFont(titleFont);
    title->setStyleSheet("background-color: red;");
    simcellularLayout->addWidget(title, 0, 1, 4, 2);

    board = new QFrame();
    board->setFixedSize(60, 120);
    board->setStyleSheet("background-color: green;");
//    QSizePolicy sizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
//    board->setSizePolicy(sizePolicy);
    QGridLayout *boardLayout = new QGridLayout(board);
    boardLayout->setContentsMargins(0, 0, 0, 0);
    boardLayout->setSpacing(0);
    for (int row = 0; row < 20; row++) {
        for (int column = 0; column < 20; column++) {
            QFrame *cell = new QFrame();
            cell->setStyleSheet("background-color: blue");
            cell->setFixedSize(3,3);
            boardLayout->addWidget(cell, row, column, 21, 21);
        }
    }

    QSpacerItem *horizontalSpacer = new QSpacerItem(1, 1, QSizePolicy::Fixed, QSizePolicy::Expanding);
    boardLayout->addItem(horizontalSpacer, 0, 20, 21, 21);
    simcellularLayout->addWidget(board, 1, 1, 4, 2);


    about = new QLabel("about");
    QFont aboutFont = QFont(openSansCondensed);
    aboutFont.setPixelSize(50);
    about->setFont(aboutFont);
    about->setStyleSheet("background-color: red;");
    simcellularLayout->addWidget(about, 3, 1, 4, 2);

    shape0 = new QFrame();
    shape1 = new QFrame();
    shape2 = new QFrame();
    shape3 = new QFrame();
    shape4 = new QFrame();
    shape5 = new QFrame();
    shape6 = new QFrame();
    colors = new QFrame();

    QGridLayout *shape0Layout = new QGridLayout(shape0);
    QGridLayout *shape1Layout = new QGridLayout(shape1);
    QGridLayout *shape2Layout = new QGridLayout(shape2);
    QGridLayout *shape3Layout = new QGridLayout(shape3);
    QGridLayout *shape4Layout = new QGridLayout(shape4);
    QGridLayout *shape5Layout = new QGridLayout(shape5);
    QGridLayout *shape6Layout = new QGridLayout(shape6);
    QGridLayout *colorsLayout = new QGridLayout(colors);

    sidebar = new QFrame();
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebar);
    sidebarLayout->addWidget(shape0);
    sidebarLayout->addWidget(shape1);
    sidebarLayout->addWidget(shape2);
    sidebarLayout->addWidget(shape3);
    sidebarLayout->addWidget(shape4);
    sidebarLayout->addWidget(shape5);
    sidebarLayout->addWidget(shape6);
    sidebarLayout->addWidget(colors);

    simcellularLayout->addWidget(sidebar, 1, 0, 4, 2);

    stepForward = new QToolButton();
    pause = new QToolButton();
    play = new QToolButton();
    fastForward = new QToolButton();
    clear = new QToolButton();
    random = new QToolButton();

    controls = new QFrame();
    QHBoxLayout *controlsLayout = new QHBoxLayout(controls);
    controlsLayout->addWidget(stepForward);
    controlsLayout->addWidget(pause);
    controlsLayout->addWidget(play);
    controlsLayout->addWidget(fastForward);
    controlsLayout->addWidget(clear);
    controlsLayout->addWidget(random);

    simcellularLayout->addWidget(controls, 2, 1, 4, 2);


//    QVBoxLayout *sidebar = new QVBoxLayout;

//    setLayout(sidebar);

//    boardWidget = new QGridLayout(200, 200, this);
}

Widget::~Widget()
{
    delete ui;
}

