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

//<<<<<<< Updated upstream
    return Color(rAvg, gAvg, bAvg);
//=======
    if  (state) {
        bool shouldSurvive = (tally == 2 || tally == 3); // temp
        setNext(shouldSurvive);
    } else {
        bool shouldGenerate = (tally == 3); // temp
        Color *color;
        if (shouldGenerate) {
            if  (QRandomGenerator::global()->bounded(0, 10) < 8) {
                for (int i = 0; i < liveNeighbors.size(); i++) {
                    qDebug() << "neighbor" << i << "of" << tally << "(" << liveNeighbors[i]->row << liveNeighbors[i]->column << "):" << liveNeighbors[i]->state << liveNeighbors[i]->color->redValue << liveNeighbors[i]->color->greenValue << liveNeighbors[i]->color->blueValue;
                }
                color = liveNeighbors[QRandomGenerator::global()->bounded(0, liveNeighbors.size())]->color;
            } else {
                for (int i = 0; i < liveNeighbors.size(); i++) {
                    qDebug() << "neighbor" << i << "of" << tally << "(" << liveNeighbors[i]->row << liveNeighbors[i]->column << "):" << liveNeighbors[i]->state << liveNeighbors[i]->color->redValue << liveNeighbors[i]->color->greenValue << liveNeighbors[i]->color->blueValue;
                }
                color = getAverageColor(liveNeighbors);
            }
            setNext(true, color);
        } else {
            setNext(false);
        }
    }
}

void Cell::transition() {
    state = nextState;
    color->copy(nextColor);
}

void Cell::setNext(bool stateParameter, Color *colorParameter) {
    nextState = stateParameter;
    if (nextState) {
        if (colorParameter != nullptr) { // could probably be combined with above
            nextColor->copy(colorParameter);
        }
    } else {
        nextColor->setWhite();
    }
}

void Cell::setNextRandom() {
    nextState = QRandomGenerator::global()->bounded(0, 10) < 2;
//            qDebug() << cell.state << board[row][column].state;
    if (nextState) {
        nextColor->setRandom();
//                qDebug() << cell.color.getQColor().red() << cell.color.getQColor().blue() << cell.color.getQColor().green();
    } else {
        nextColor->setWhite();
    }
//>>>>>>> Stashed changes
}
