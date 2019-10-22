#ifndef CELL_H
#define CELL_H

#include "color.h"

#include <QList>

class Cell {
public:
    static bool areSame(Cell *cell1, Cell *cell2);

    Cell(int rowParam, int columnParam);
    bool state;
    bool nextState;
    int row; // commented out in original - vestigial?
    int column; // commented out in original - vestigial?
    Color *color;
    Color *nextColor;
    QList<Cell*> neighbors;
    QList<Cell*> getLiveNeighbors();
    void determineNext();
    void transition();
    void setNext(bool state, Color *colorParameter=nullptr);
    void setNextRandom();
    static Color  *getAverageColor(QList<Cell*> liveNeighbors);

};

#endif // CELL_H
