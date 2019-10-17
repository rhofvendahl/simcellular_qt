#ifndef CELL_H
#define CELL_H

#include "color_bag.h"

#include <QList>

class Cell
{
public:
    Cell(int row, int column);
    bool state = false;
    bool nextState;
    int row; // commented out in original - vestigial?
    int column; // commented out in original - vestigial?
    Color color;
    QList<
};

#endif // CELL_H
