#ifndef GAME_H
#define GAME_H

#include "color.h"
#include "cell.h"

class Game
{
public:
    Game();
    QList<QList<Cell>> board;
    void update();
    void insert(Cell insertCell, QList<QList<bool>> shape, QColor color);
    void clear();
    void random(); // originally passed in list of colors

private:
    Cell inRangeCell(int  row, int column);
    QList<Cell> getNeighbors(cell Cell);
    QColor averageColor(QList<Cell> cells);

};

#endif // GAME_H
