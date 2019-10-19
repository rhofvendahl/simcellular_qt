#ifndef WIDGET_H
#define WIDGET_H

#include "game.h"
#include "library.h"
#include "color.h"

#include <QtWidgets/QWidget>
#include <QTableWidget>
#include <QLayout>
#include <QLabel>
#include <QToolButton>
#include <QFrame>
#include <QTimer>

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
    void on_board_cellEntered(int row, int column);
    void transitionHandler();
    void on_colors_cellPressed(int row, int column);
    void on_board_cellPressed(int row, int column);
    void on_shape0_pressed(const QModelIndex &index);
    void on_shape1_pressed(const QModelIndex &index);
    void on_shape2_pressed(const QModelIndex &index);
    void on_shape3_pressed(const QModelIndex &index);
    void on_shape4_pressed(const QModelIndex &index);
    void on_shape5_pressed(const QModelIndex &index);
    void on_shape6_pressed(const QModelIndex &index);

private:
    Ui::Widget *ui;

    const int boardRows = 30;
    const int boardColumns = 30;
    Game *game;
    Library *library;

    void render();

    QTimer *transitionTimer;
    const int playInterval = 150;
    const int fastForwardInterval = 50;

    Color *selectedColor;
    int selectedShape;

    void deSelectShapes();

};
#endif // WIDGET_H
