#include "cell.h"
#include "color.h"

#include <QtMath>
#include <QRandomGenerator>

Cell::Cell(int rowParam, int columnParam)
{
    state = false;
    row = rowParam; // not in original
    column = columnParam; // not in original
}

bool Cell::areSame(Cell *cell1, Cell *cell2){
    return (cell1->row == cell2->row) && (cell1->column == cell2->column);
}

QList<Cell*> Cell::getLiveNeighbors() {
    QList<Cell*> liveNeighbors;
    for (int i = 0; i < neighbors.size(); i++) {
        if (neighbors[i]->state) {
            liveNeighbors += neighbors[i];
        }
    }
    return liveNeighbors;
}

// accepts liveNeighbors parameter to save time
void Cell::inheritColor(QList<Cell*> liveNeighbors) {
    int rSum = 0, gSum = 0, bSum = 0;
    for (int  i = 0; i < liveNeighbors.size(); i++) {
        Cell *neighbor = liveNeighbors.at(i);
        rSum += static_cast<int>(qPow(neighbor->color->redValue, 2));
        gSum += static_cast<int>(qPow(neighbor->color->blueValue, 2));
        bSum += static_cast<int>(qPow(neighbor->color->greenValue, 2));
    }

    int liveNeighborsSize = liveNeighbors.size();
    color->redValue = static_cast<int>(qSqrt(rSum / static_cast<double>(liveNeighborsSize)));
    color->greenValue = static_cast<int>(qSqrt(gSum / static_cast<double>(liveNeighborsSize)));
    color->blueValue = static_cast<int>(qSqrt(bSum / static_cast<double>(liveNeighborsSize)));
}

void Cell::determineNext()  {
    QList<Cell*> liveNeighbors = getLiveNeighbors();
    int tally = liveNeighbors.size();

    bool shouldSurvive = (tally == 2 || tally == 3);
    bool shouldRegenerate = (tally == 3);

    if  (state && shouldSurvive) {
        nextState = true;
        // & color remains
    } else if (state && shouldRegenerate) {
        nextState = true;
        if  (QRandomGenerator::global()->bounded(0, 9) < 8) {
            Color *color = liveNeighbors[QRandomGenerator::global()->bounded(0, liveNeighbors.size() - 1)]->color;
            nextColor->copy(color);
        } else {
            inheritColor(liveNeighbors);
        }
    } else {
        nextState = false;
        nextColor->setWhite();
    }
}

void Cell::transition() {
    state = nextState;
    color->copy(nextColor);
}

void Cell::set(bool stateParameter, Color *colorParameter) {
    state = stateParameter;
    if (state) {
        color->copy(colorParameter);
    } else {
        color->setWhite();
    }
}

void Cell::setRandom() {
    state = QRandomGenerator::global()->bounded(0, 9) < 2;
//            qDebug() << cell.state << board[row][column].state;
    if (state) {
        color->setRandom();
//                qDebug() << cell.color.getQColor().red() << cell.color.getQColor().blue() << cell.color.getQColor().green();
    } else {
        color->setWhite();
    }
}
