#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QTableWidget>
#include <QLayout>
#include <QLabel>
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

    QGridLayout *simcellular;
    QLabel *title;
    QTableWidget *board;
    QLabel *about;

    QVBoxLayout *sidebar;
    QTableWidget *shape0;
    QTableWidget *shape1;
    QTableWidget *shape2;
    QTableWidget *shape3;
    QTableWidget *shape4;
    QTableWidget *shape5;
    QTableWidget *shape6;
    QTableWidget *colors;

    QHBoxLayout *controls;
    QToolButton *stepForward;
    QToolButton *pause;
    QToolButton *play;
    QToolButton *fastForward;
    QToolButton *clear;
    QToolButton *random;
};
#endif // WIDGET_H
