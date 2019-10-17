#include "game.h"

#include <QList>

Game::Game(int rows, int columns)
{
    for (int row = 0; row < rows; row++) {
        QList<Cell> newRow;
        for (int column = 0; column < columns; column++) {
            newRow += Cell(row, column);
        }
        board += newRow;
    }

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Cell cell = board[row][column];
            cell.neighbors = getNeighbors(cell);
        }
    }
}

Cell Game::inRangeCell(int row, int column) {
    int inRangeRow = (row + board.size()) % board.size();
    int inRangeColumn = (column + board[0].size()) % board[0].size();
    return board[inRangeRow][inRangeColumn];
}

QList<Cell> Game::getNeighbors(Cell cell) {
    QList<Cell> neighbors;
    for (int row = cell.row -1; row <= cell.row +  1; row++) {
        for (int column = cell.column - 1; column <= cell.column + 1; column++) {
            Cell neighbor = inRangeCell(row, column);
            if (!Cell::areSame(neighbor, cell)) {
                neighbors += neighbor;
            }
        }
    }
    return neighbors;
}

void Game::update() {
    for (int row = 0; row < board.size(); row++) {
        for (int column = 0; column < board[0].size(); column++) {
            Cell cell = board[row][column];
            cell.liveNeighbors = getLiveNeighbors(cell);
        }
    }
}
