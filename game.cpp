#include "game.h"

#include <QList>
#include <QRandomGenerator>
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

void Game::update()
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
    for (int shapeRow = 0; shapeRow < shape.size(); shapeRow++) {
        for (int shapeColumn = 0; shapeColumn < shape[0].size(); shapeColumn++) {
            Cell *cell = inRangeCell(insertCell->row + shapeRow, insertCell->column + shapeColumn);
            cell->state = shape[shapeRow][shapeColumn];
            cell->color = color;
            cell->set(shape[shapeRow][shapeColumn], color);
        }
    }
}

void Game::clear()
{
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            board[row][column]->set(false);
        }
    }
}

void Game::random()
{
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {

        }
    }
}
