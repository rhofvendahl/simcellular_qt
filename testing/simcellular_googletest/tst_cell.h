#ifndef TST_CELL_H
#define TST_CELL_H

#include "../headers/cell.h"
#include "../headers/color.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QList>

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

// Cell_AverageColorTest

TEST(Cell_AverageColorTest, averagesSameColors) {
    QList<Cell*> cells = QList<Cell*>({});
    Cell *cell1 = new Cell(1, 1);
    cell1->color->setGreen();
    cells += cell1;
    Cell  *cell2 = new Cell(2, 2);
    cell2->color->setGreen();
    cells += cell2;

    QColor *color = Cell::getAverageColor(cells);
    EXPECT_EQ(color->redValue, Color::green->redValue())
}

TEST(Cell_AverageColorTest, averagesDifferentColors) {
    QList<Cell*> cells = QList<Cell*>({});
    Cell *cell3 = new Cell(3, 3);
    cell3->color->setWhite();
}

#endif // TST_CELL_H
