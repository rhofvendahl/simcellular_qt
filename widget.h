#ifndef WIDGET_H
#define WIDGET_H

#include "game.h"
#include "library.h"

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

private slots:
    void on_step_forward_pressed();

    void on_pause_pressed();

    void on_play_pressed();

    void on_fast_forward_pressed();

    void on_clear_pressed();

    void on_random_pressed();

private:
    Ui::Widget *ui;

    const int boardRows = 200;
    const int boardColumns = 200;
    Game game = Game(boardRows, boardColumns);
    Library library;

    void render();
};
#endif // WIDGET_H
