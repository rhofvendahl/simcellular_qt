#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QFrame>

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

    QLabel *title;

    QFrame *sidebar;
    QFrame *shape0;
    QFrame *shape1;
    QFrame *shape2;
    QFrame *shape3;
    QFrame *shape4;
    QFrame *shape5;
    QFrame *shape6;
    QFrame *colors;

    QFrame *board;

    QFrame *controls;
    QToolButton *stepForward;
    QToolButton *pause;
    QToolButton *play;
    QToolButton *fastForward;
    QToolButton *clear;
    QToolButton *random;

    QLabel *about;

};
#endif // WIDGET_H
