//#include "game.h"

//#include <QList>
//#include <QRandomGenerator>

//Game::Game(int rows, int columns)
//{
//    for (int row = 0; row < rows; row++) {
//        QList<Cell> newRow;
//        for (int column = 0; column < columns; column++) {
//            newRow += Cell(row, column);
//        }
//        board += newRow;
//    }

//    for (int row = 0; row < rows; row++) {
//        for (int column = 0; column < columns; column++) {
//            Cell cell = board[row][column];
//            cell.neighbors = getNeighbors(cell);
//        }
//    }
//}

//Cell Game::inRangeCell(int row, int column) {
//    int inRangeRow = (row + board.size()) % board.size();
//    int inRangeColumn = (column + board[0].size()) % board[0].size();
//    return board[inRangeRow][inRangeColumn];
//}

//QList<Cell> Game::getNeighbors(Cell cell) {
//    QList<Cell> neighbors;
//    for (int row = cell.row -1; row <= cell.row +  1; row++) {
//        for (int column = cell.column - 1; column <= cell.column + 1; column++) {
//            Cell neighbor = inRangeCell(row, column);
//            if (!Cell::areSame(neighbor, cell)) {
//                neighbors += neighbor;
//            }
//        }
//    }
//    return neighbors;
//}

//void Game::update() {
//    // calculate next states
//    for (int row = 0; row < board.size(); row++) {
//        for (int column = 0; column < board[0].size(); column++) {
//            Cell cell = board[row][column];
//            QList<Cell> liveNeighbors = cell.getLiveNeighbors();
//            int tally = liveNeighbors.size();

//            bool shouldSurvive = (tally == 2 || tally == 3);
//            bool shouldRegenerate = (tally == 3);

//            if  (cell.state && shouldSurvive) {
//                cell.nextState = true;
//                // color remains
//            } else if (!cell.state && shouldRegenerate) {
//                cell.nextState = true;
//                QRandomGenerator rand;
//                if  (rand.bounded(0, 9) < 8) {
//                    cell.nextColor = liveNeighbors[rand.bounded(0, liveNeighbors.size() - 1)].color;
//                } else {
//                    cell.nextColor = Cell::getAverageColor(liveNeighbors);
//                }
//            } else {
//                cell.nextState = false;
//                cell.nextColor = Color::getWhite();
//            }
//        }
//    }

//    // transition
//    for (int row = 0; row < board.size(); row++) {
//        for (int column = 0; column < board[0].size(); column++) {
//            Cell cell = board[row][column];
//            cell.state = cell.nextState;
//            cell.color = cell.nextColor;
//        }
//    }
//}

//void Game::insert(Cell insertCell, QList<QList<bool>> shape, Color color) {
//    for (int shapeRow = 0; shapeRow < shape.size(); shapeRow++) {
//        for (int shapeColumn = 0; shapeColumn < shape[0].size(); shapeColumn++) {
//            Cell cell = inRangeCell(insertCell.row + shapeRow, insertCell.column + shapeColumn);
//            cell.state= shape[shapeRow][shapeColumn];
//            cell.color = color;
//        }
//    }
//}

//void Game::clear() {
//    for (int row = 0; row < board.size(); row++) {
//        for (int column = 0; column < board[0].size(); column++) {
//            Cell cell = board[row][column];
//            cell.state = false;
//            cell.nextState = false;
//        }
//    }
//}

//void Game::random(){
//    for (int row = 0; row < board.size(); row++) {
//        for (int column = 0; column < board[0].size(); column++) {
//            Cell cell = board[row][column];
//            QRandomGenerator rand;
//            cell.state = rand.bounded(0, 9) < 2;
//            cell.color = Color::getRandom();
//        }
//    }
//}
#include "headers/game.h"

#include <QList>
//#include <QRandomGenerator>
#include <QDebug>

Game::Game(int rows, int columns)
{
    for (int row = 0; row < rows; row++) {
        QList<Cell*> newRow;
        for (int column = 0; column < columns; column++) {
            newRow += new Cell(row, column);
        }
        board += newRow;
    }

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Cell *cell = board[row][column];
            cell->neighbors = getNeighbors(cell);
        }
    }
}

Cell *Game::inRangeCell(int row, int column)
{
    int inRangeRow = (row + board.size()) % board.size();
    int inRangeColumn = (column + board[0].size()) % board[0].size();
    return board[inRangeRow][inRangeColumn];
}

QList<Cell*> Game::getNeighbors(Cell *cell)
{
    QList<Cell*> neighbors;
    for (int row = cell->row -1; row <= cell->row +  1; row++) {
        for (int column = cell->column - 1; column <= cell->column + 1; column++) {
            Cell *neighbor = inRangeCell(row, column);
            if (!Cell::areSame(neighbor, cell)) {
                neighbors += neighbor;
            }
        }
    }
    return neighbors;
}

void Game::transition()
{
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            board[row][column]->determineNext();
        }
    }

    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            board[row][column]->transition();
        }
    }
}

void Game::insert(Cell *insertCell, QList<QList<bool>> shape, Color *color)
{
    qDebug() << "inserting";
    for (int shapeRow = 0; shapeRow < shape.size(); shapeRow++) {
        for (int shapeColumn = 0; shapeColumn < shape[0].size(); shapeColumn++) {
            Cell *cell = inRangeCell(insertCell->row + shapeRow, insertCell->column + shapeColumn);
            qDebug() << cell->row << cell->column;
            cell->setNext(shape[shapeRow][shapeColumn], color);
            cell->transition();
        }
    }
}

void Game::clear()
{
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            Cell *cell = board[row][column];
            cell->setNext(false);
            cell->transition();

        }
    }
}

void Game::random()
{
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            Cell *cell = board[row][column];
            cell->setNextRandom();
            cell->transition();
        }
    }
}
