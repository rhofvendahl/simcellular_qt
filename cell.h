#ifndef CELL_H
#define CELL_H

#include "color.h"

#include <QList>

class Cell
{
public:
    Cell(int rowParam, int columnParam);
    bool state;
    bool nextState;
    int row; // commented out in original - vestigial?
    int column; // commented out in original - vestigial?
    Color color;
    QList<Cell> neighbors;
};

#endif // CELL_H
