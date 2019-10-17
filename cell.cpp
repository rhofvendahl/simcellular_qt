#include "cell.h"
#include "color.h"

#include <QtMath>

Cell::Cell(int rowParam, int columnParam)
{
    state = false;
    nextState = false;
    row = rowParam; // not in original
    column = columnParam; // not in original
}

bool Cell::areSame(Cell cell1, Cell cell2){
    return (cell1.row == cell2.row) && (cell1.column == cell2.column);
}

QList<Cell> Cell::getLiveNeighbors() {
    QList<Cell> liveNeighbors;
    for (int i = 0; i < neighbors.size(); i++) {
        if (neighbors[i].state) {
            liveNeighbors += neighbors[i];
        }
    }
    return liveNeighbors;
}

Color Cell::getAverageColor(QList<Cell> cells) {
    int rSum = 0, gSum = 0, bSum = 0;
    for (int  i = 0; i < cells.size(); i++) {
        rSum += static_cast<int>(qPow(cells.at(i).color.redValue, 2));
        gSum += static_cast<int>(qPow(cells.at(i).color.blueValue, 2));
        bSum += static_cast<int>(qPow(cells.at(i).color.greenValue, 2));
    }

    int rAvg, gAvg, bAvg;
    rAvg = static_cast<int>(qSqrt(rSum / static_cast<double>(cells.size())));
    gAvg = static_cast<int>(qSqrt(gSum / static_cast<double>(cells.size())));
    bAvg = static_cast<int>(qSqrt(bSum / static_cast<double>(cells.size())));

    return Color(rAvg, gAvg, bAvg);
}
