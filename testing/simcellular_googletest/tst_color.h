#ifndef TST_COLOR_H
#define TST_COLOR_H

#include "../headers/color.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

using namespace testing;

// Color_StaticColorsTest

TEST(Color_StaticColorsTest, redIsRed) {
    Color *red = Color::red;
    EXPECT_EQ(red->redValue, 255) << "Incorrect red value.";
    EXPECT_EQ(red->greenValue, 91) << "Incorrect green value.";
    EXPECT_EQ(red->blueValue, 71) << "Incorrect blue value.";
}

TEST(Color_StaticColorsTest, greenIsGreen) {
    Color *green = Color::green;
    EXPECT_EQ(green->redValue, 49) << "Incorrect red value.";
    EXPECT_EQ(green->greenValue, 204) << "Incorrect green value.";
    EXPECT_EQ(green->blueValue, 50) << "Incorrect blue value.";
}

TEST(Color_StaticColorsTest, blueIsBlue) {
    Color *blue = Color::blue;
    EXPECT_EQ(blue->redValue, 0) << "Incorrect red value.";
    EXPECT_EQ(blue->greenValue, 191) << "Incorrect green value.";
    EXPECT_EQ(blue->blueValue, 255) << "Incorrect blue value.";
}

TEST(Color_StaticColorsTest, yellowIsYellow) {
    Color *yellow = Color::yellow;
    EXPECT_EQ(yellow->redValue, 245) << "Incorrect red value.";
    EXPECT_EQ(yellow->greenValue, 227) << "Incorrect green value.";
    EXPECT_EQ(yellow->blueValue, 68) << "Incorrect blue value.";
}

TEST(Color_StaticColorsTest, whiteIsWhite) {
    Color *white = Color::white;
    EXPECT_EQ(white->redValue, 255) << "Incorrect red value.";
    EXPECT_EQ(white->greenValue, 255) << "Incorrect green value.";
    EXPECT_EQ(white->blueValue, 255) << "Incorrect blue value.";
}

// Color_ConstructorTest

TEST(Color_ConstructorTest, defaultIsWhite) {
    Color *newWhite = new Color();
    Color *staticWhite = Color::white;
    EXPECT_EQ(newWhite->redValue, staticWhite->redValue) << "Red value improperly initialized.";
    EXPECT_EQ(newWhite->greenValue, staticWhite->greenValue) << "Green value improperly initialized.";
    EXPECT_EQ(newWhite->blueValue, staticWhite->blueValue) << "Blue value improperly initialized.";
}

TEST(Color_ConstructorTest, acceptsParameters) {
    Color *newColor = new Color(0, 1, 2);
    EXPECT_EQ(newColor->redValue, 0) << "Red value improperly initialized.";
    EXPECT_EQ(newColor->greenValue, 1) << "Green value improperly initialized.";
    EXPECT_EQ(newColor->blueValue, 2) << "Blue value improperly initialized.";
}

// Color_GetterTest

TEST(Color_GetterTest, getsRed) {
    Color *newColor = Color::getRed();
    Color *staticColor = Color::red;
    EXPECT_EQ(newColor->redValue, staticColor->redValue) << "Incorrect red value.";
    EXPECT_EQ(newColor->greenValue, staticColor->greenValue) << "Incorrect green value.";
    EXPECT_EQ(newColor->blueValue, staticColor->blueValue) << "Incorrect blue value.";
}

TEST(Color_GetterTest, getsGreen) {
    Color *newColor = Color::getGreen();
    Color *staticColor = Color::green;
    EXPECT_EQ(newColor->redValue, staticColor->redValue) << "Incorrect red value.";
    EXPECT_EQ(newColor->greenValue, staticColor->greenValue) << "Incorrect green value.";
    EXPECT_EQ(newColor->blueValue, staticColor->blueValue) << "Incorrect blue value.";
}

TEST(Color_GetterTest, getsBlue) {
    Color *newColor = Color::getBlue();
    Color *staticColor = Color::blue;
    EXPECT_EQ(newColor->redValue, staticColor->redValue) << "Incorrect red value.";
    EXPECT_EQ(newColor->greenValue, staticColor->greenValue) << "Incorrect green value.";
    EXPECT_EQ(newColor->blueValue, staticColor->blueValue) << "Incorrect blue value.";
}

TEST(Color_GetterTest, getsYellow) {
    Color *newColor = Color::getYellow();
    Color *staticColor = Color::yellow;
    EXPECT_EQ(newColor->redValue, staticColor->redValue) << "Incorrect red value.";
    EXPECT_EQ(newColor->greenValue, staticColor->greenValue) << "Incorrect green value.";
    EXPECT_EQ(newColor->blueValue, staticColor->blueValue) << "Incorrect blue value.";
}

TEST(Color_GetterTest, getsWhite) {
    Color *newColor = Color::getWhite();
    Color *staticColor = Color::white;
    EXPECT_EQ(newColor->redValue, staticColor->redValue) << "Incorrect red value.";
    EXPECT_EQ(newColor->greenValue, staticColor->greenValue) << "Incorrect green value.";
    EXPECT_EQ(newColor->blueValue, staticColor->blueValue) << "Incorrect blue value.";
}

TEST(Color_GetterTest, getsRandomReturnsProperColor) {
    Color *randomColor = Color::getRandom();
    EXPECT_GE(randomColor->redValue, 0) << "Red value outside of range (too low).";
    EXPECT_GE(randomColor->greenValue, 0) << "Green value outside of range (too low).";
    EXPECT_GE(randomColor->blueValue, 0) << "Blue value outside of range (too low).";
    EXPECT_LE(randomColor->redValue, 255) << "Red value outside of range (too high).";
    EXPECT_LE(randomColor->greenValue, 255) << "Green value outside of range (too high).";
    EXPECT_LE(randomColor->blueValue, 255) << "Blue value outside of range (too high).";
}

// Color_SetterTest

TEST(Color_SetterTest, setsRed) {
    Color *color = new Color(0, 0, 0);
    color->setRed();
    EXPECT_EQ(color->redValue, Color::red->redValue) << "Red value improperly set.";
    EXPECT_EQ(color->greenValue, Color::red->greenValue) << "Green value improperly set.";
    EXPECT_EQ(color->blueValue, Color::red->blueValue) << "Blue value improperly set.";
}

TEST(Color_SetterTest, setsGreen) {
    Color *color = new Color(0, 0, 0);
    color->setGreen();
    EXPECT_EQ(color->redValue, Color::green->redValue) << "Red value improperly set.";
    EXPECT_EQ(color->greenValue, Color::green->greenValue) << "Green value improperly set.";
    EXPECT_EQ(color->blueValue, Color::green->blueValue) << "Blue value improperly set.";
}

TEST(Color_SetterTest, setsBlue) {
    Color *color = new Color(0, 0, 0);
    color->setBlue();
    EXPECT_EQ(color->redValue, Color::blue->redValue) << "Red value improperly set.";
    EXPECT_EQ(color->greenValue, Color::blue->greenValue) << "Green value improperly set.";
    EXPECT_EQ(color->blueValue, Color::blue->blueValue) << "Blue value improperly set.";
}

TEST(Color_SetterTest, setsYellow) {
    Color *color = new Color(0, 0, 0);
    color->setYellow();
    EXPECT_EQ(color->redValue, Color::yellow->redValue) << "Red value improperly set.";
    EXPECT_EQ(color->greenValue, Color::yellow->greenValue) << "Green value improperly set.";
    EXPECT_EQ(color->blueValue, Color::yellow->blueValue) << "Blue value improperly set.";
}

TEST(Color_SetterTest, setsWhite) {
    Color *color = new Color(0, 0, 0);
    color->setWhite();
    EXPECT_EQ(color->redValue, Color::white->redValue) << "Red value improperly set.";
    EXPECT_EQ(color->greenValue, Color::white->greenValue) << "Green value improperly set.";
    EXPECT_EQ(color->blueValue, Color::white->blueValue) << "Blue value improperly set.";
}

TEST(Color_SetterTest, setsRandomChangesColor) {
    Color *color = new Color(0, 0, 0);
    color->setRed();
    EXPECT_NE(color->redValue, 0) << "Red value unchanged.";
    EXPECT_NE(color->greenValue, 0) << "Green value unchanged.";
    EXPECT_NE(color->blueValue, 0) << "Blue value unchanged.";
}

// Color_QColorTest

TEST(Color_QColorTest, returnsCorrespondingQColor){
    Color *color = new Color(0, 1, 2);
    QColor qColor = color->qColor();
    EXPECT_EQ(color->redValue, qColor.red()) << "Red value does not match created QColor.";
    EXPECT_EQ(color->greenValue, qColor.green()) << "Green value does not match created QColor.";
    EXPECT_EQ(color->blueValue, qColor.blue()) << "Blue value does not match created QColor.";
}

// Color_CopyTest

TEST(Color_CopyTest, copiesColor) {
    Color *color = new Color(0, 0, 0);
    Color *desiredColor = new Color(255, 255, 255);
    color->copy(desiredColor);
    EXPECT_EQ(color->redValue, desiredColor->redValue) << "Red value not copied correctly.";
    EXPECT_EQ(color->greenValue, desiredColor->greenValue) << "Green value not copied correctly.";
    EXPECT_EQ(color->blueValue, desiredColor->blueValue) << "Blue value not copied correctly.";
}

#endif // TST_COLOR_H
