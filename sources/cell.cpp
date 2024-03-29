#include "headers/cell.h"
#include "headers/color.h"

#include <QtMath>
#include <QRandomGenerator>
#include <QDebug>

Cell::Cell(int rowParam, int columnParam) {
    state = false;
    nextState = false;
    color = Color::getWhite();
    nextColor = Color::getWhite();
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
Color *Cell::getAverageColor(QList<Cell*> liveNeighbors) {
    int rSum = 0, gSum = 0, bSum = 0;
    for (int  i = 0; i < liveNeighbors.size(); i++) {
        Cell *neighbor = liveNeighbors.at(i);
        rSum += static_cast<int>(qPow(neighbor->color->redValue, 2));
        gSum += static_cast<int>(qPow(neighbor->color->greenValue, 2));
        bSum += static_cast<int>(qPow(neighbor->color->blueValue, 2));
    }

    int liveNeighborsSize = liveNeighbors.size();
    int redValue = static_cast<int>(qSqrt(rSum / static_cast<double>(liveNeighborsSize)));
    int greenValue = static_cast<int>(qSqrt(gSum / static_cast<double>(liveNeighborsSize)));
    int blueValue = static_cast<int>(qSqrt(bSum / static_cast<double>(liveNeighborsSize)));
    return new Color(redValue, greenValue, blueValue);
}

void Cell::determineNext() {
    QList<Cell*> liveNeighbors = getLiveNeighbors();
    int tally = liveNeighbors.size();

    if  (state) {
        bool shouldSurvive = (tally == 2 || tally == 3); // temp
        setNext(shouldSurvive);
    } else {
        bool shouldGenerate = (tally == 3); // temp
        Color *color;
        if (shouldGenerate) {
            if  (QRandomGenerator::global()->bounded(0, 10) < 8) {
                for (int i = 0; i < liveNeighbors.size(); i++) {
                }
                color = liveNeighbors[QRandomGenerator::global()->bounded(0, liveNeighbors.size() - 1)]->color;
            } else {
                for (int i = 0; i < liveNeighbors.size(); i++) {
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
    nextState = QRandomGenerator::global()->bounded(0, 9) < 2;
    if (nextState) {
        nextColor->setRandom();
    } else {
        nextColor->setWhite();
    }
}

