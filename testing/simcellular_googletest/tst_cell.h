#ifndef TST_CELL_H
#define TST_CELL_H

#include "../headers/cell.h"
#include "../headers/color.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QList>
#include <QtMath>

using namespace testing;

// Color_ConstructorTest

TEST(Cell_ConstructorTest, setsMemberVariables) {
    Cell *cell = new Cell(0, 1);
    EXPECT_FALSE(cell->state) << "Cell state is not false.";
    EXPECT_FALSE(cell->nextState) << "Cell nextState is not false.";
    EXPECT_EQ(cell->color->redValue, Color::white->redValue) << "Cell color is not white (incorrect redValue).";
    EXPECT_EQ(cell->color->greenValue, Color::white->greenValue) << "Cell color is not white (incorrect greenValue).";
    EXPECT_EQ(cell->color->blueValue, Color::white->blueValue) << "Cell color is not white (incorrect blueValue).";
    EXPECT_EQ(cell->nextColor->redValue, Color::white->redValue) << "Cell nextColor is not white (incorrect redValue).";
    EXPECT_EQ(cell->nextColor->greenValue, Color::white->greenValue) << "Cell nextColor is not white (incorrect greenValue).";
    EXPECT_EQ(cell->nextColor->blueValue, Color::white->blueValue) << "Cell nextColor is not white (incorrect blueValue).";
    EXPECT_EQ(cell->row, 0) << "Cell row not set correctly.";
    EXPECT_EQ(cell->column, 1) << "Cell column not set correctly.";
}

// Cell_AreSameTest

TEST(Cell_AreSameTest, comparesCells) {
    Cell *cell1 = new Cell(0, 1);
    Cell *cell2 = new Cell(0, 1);
    Cell *cell3 = new Cell(1, 2);
    EXPECT_TRUE(Cell::areSame(cell1, cell2)) << "Does not recognize same cells";
    EXPECT_FALSE(Cell::areSame(cell2, cell3)) << "Does not recognize different cells";
}

// Cell_GetLiveNeighborsTest

TEST(Cell_GetLiveNeighborsTest, countsLiveNeighbors) {
    Cell *cell1 = new Cell(1, 1);
    cell1->state = true;
    Cell *cell2 = new Cell(2, 2);
    cell2->state = true;
    QList<Cell*> neighbors = QList<Cell*>({cell1,  cell2});

    Cell *cell3 = new Cell(3, 3);
    cell3->neighbors = neighbors;
    QList<Cell*> liveNeighbors = cell3->getLiveNeighbors();
    EXPECT_EQ(liveNeighbors.size(), 2) << "Live neighbors tallied incorrectly.";
}

TEST(Cell_GetLiveNeighborsTest, doesNotCountDeadNeighbors) {
   Cell *cell1 = new Cell(1, 1);
   cell1->state = false;
   Cell *cell2 = new Cell(2, 2);
   cell2->state = false;
   QList<Cell*> neighbors = QList<Cell*>({cell1,  cell2});

   Cell *cell3 = new Cell(3, 3);
   cell3->neighbors = neighbors;
   QList<Cell*> liveNeighbors = cell3->getLiveNeighbors();
   EXPECT_EQ(liveNeighbors.size(), 0) << "Live neighbors tallied incorrectly.";
}

// Cell_AveragesColorTest

TEST(Cell_AverageColorTest, averagesSameColors) {
    QList<Cell*> cells = QList<Cell*>({});
    Cell *cell1 = new Cell(1, 1);
    cell1->color->setGreen();
    cells += cell1;
    Cell  *cell2 = new Cell(2, 2);
    cell2->color->setGreen();
    cells += cell2;

    Color *color = Cell::getAverageColor(cells);
    EXPECT_EQ(color->redValue, Color::green->redValue) << "Red values not correctly averaged.";
    EXPECT_EQ(color->greenValue, Color::green->greenValue) << "Green values not correctly averaged.";
    EXPECT_EQ(color->blueValue, Color::green->blueValue) << "Blue values not correctly averaged.";
}

TEST(Cell_AverageColorTest, averagesDifferentColors) {
    QList<Cell*> cells = QList<Cell*>({});
    Cell *cell1 = new Cell(1, 1);
    cell1->color->setWhite();
    cells += cell1;
    Cell *cell2 = new Cell(2, 2);
    cell2->color = new Color(0, 0, 0);
    cells += cell2;

    int desiredComponentValue = static_cast<int>(qSqrt((0*0 + 255*255) / 2));

    Color *color = Cell::getAverageColor(cells);
    EXPECT_EQ(color->redValue, desiredComponentValue) <<  "Red values not correctly averaged.";
    EXPECT_EQ(color->greenValue, desiredComponentValue) << "Green values not correctly averaged.";
    EXPECT_EQ(color->blueValue, desiredComponentValue) << "Blue values not correctly averaged.";
}

// Cell_UpdateTest

TEST(Cell_UpdateTest, tooManyNeighborsDeath) {
    Cell *cell1 = new Cell(1, 1);
    cell1->state = true;
    Cell *cell2 = new Cell(2, 2);
    cell2->state = true;
    Cell *cell3 = new Cell(3, 3);
    cell3->state = true;
    Cell *cell4 = new Cell(4, 4);
    cell4->state = true;

    Cell *cell5 = new Cell(5, 5);
    cell5->nextState = true;
    QList<Cell*> neighbors = QList<Cell*>({cell1, cell2, cell3, cell4});
    cell5->neighbors = neighbors;
    cell5->determineNext();
    EXPECT_FALSE(cell5->nextState) <<  "Cell not killed by too many neighbors";
}

TEST(Cell_UpdateTest, notEnoughNeighborsDeath) {
    Cell *cell1 = new Cell(1, 1);
    cell1->state = true;

    Cell *cell2 = new Cell(2, 2);
    cell2->nextState = true;
    QList<Cell*> neighbors = QList<Cell*>({cell1});
    cell2->neighbors = neighbors;
    cell2->determineNext();
    EXPECT_FALSE(cell2->nextState) <<  "Cell not killed by not enough neighbors";
}

TEST(Cell_UpdateTest, regenerates) {
    Cell *cell1 = new Cell(1, 1);
    cell1->state = true;
    Cell *cell2 = new Cell(2, 2);
    cell2->state = true;
    Cell *cell3 = new Cell(3, 3);
    cell3->state = true;

    Cell *cell4 = new Cell(4, 4);
    cell4->nextState = false;
    QList<Cell*> neighbors = QList<Cell*>({cell1, cell2, cell3});
    cell4->neighbors = neighbors;
    cell4->determineNext();
    EXPECT_TRUE(cell4->nextState) <<  "Cell not killed by not enough neighbors";
}

TEST(Cell_UpdateTest, transitions) {
    Cell *cell = new Cell(0, 0);
    cell->state = false;
    cell->nextState = true;
    cell->color = Color::getWhite();
    cell->nextColor = Color::getBlue();

    cell->transition();
    EXPECT_TRUE(cell->state) << "Cell did not transition states.";
    EXPECT_TRUE(Color::areSame(cell->color, Color::blue)) << "Cell  did not transition colors.";
}

// Cell_SetNextFunctionsTest

TEST(Cell_SetNextFunctionsTest, setsNext) {
    Cell *cell = new Cell(0, 0);
    cell->nextState = false;
    cell->nextColor = Color::getWhite();

    cell->setNext(true, Color::getRed());
    EXPECT_TRUE(cell->nextState) << "Next state not set.";
    EXPECT_TRUE(Color::areSame(cell->nextColor, Color::red)) << "Next color not set.";
}

TEST(Cell_SetNextFunctionsTest, setsNextWhiteIfFalse) {
    Cell *cell = new Cell(0, 0);
    cell->nextState = true;
    cell->nextColor = Color::getRed();

    cell->setNext(false);
    EXPECT_TRUE(Color::areSame(cell->nextColor, Color::white)) << "Next color not set to white (next state false).";
}

TEST(Cell_SetNextFunctionsTest, setsNextWhiteIfFalseRandom) {
    Cell *cell = new Cell(0, 0);

    // run until set to false
    while (cell->nextState) {
        cell->setNextRandom();
    }

    EXPECT_TRUE(Color::areSame(cell->nextColor, Color::white)) << "Next color not set to white (next state false).";
}

#endif // TST_CELL_H
