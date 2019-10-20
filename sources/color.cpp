//#include "color.h"

//#include <QColor>
//#include <QRandomGenerator>
//<<<<<<< Updated upstream
//=======
//#include <QDebug>

//Color *Color::red = new Color(255, 91, 71);
//Color *Color::green = new Color(49, 204, 50);
//Color *Color::blue = new Color(0, 191, 255);
//Color *Color::yellow = new Color(245, 227, 68);
//Color *Color::white = new Color(255, 255, 255);
//>>>>>>> Stashed changes

//Color::Color() {
//    Color cheatSheet = getWhite();
//    redValue = cheatSheet.redValue;
//    greenValue = cheatSheet.greenValue;
//    blueValue = cheatSheet.blueValue;
//}

//Color::Color(int red, int green, int blue)
//{
//    redValue = red;
//    greenValue = green;
//    blueValue = blue;
//}

//Color Color::getRed() {
//    return Color(255, 91, 71);
//}

//<<<<<<< Updated upstream
//Color Color::getGreen() {
//    return Color(50, 205, 50);
//=======
//Color *Color::getRandom(){
//    Color *color = new Color();
//    switch (QRandomGenerator::global()->bounded(0, 4)) {
//    case 0:
//        color->copy(red);
//        return color;
//    case 1:
//        color->copy(green);
//        return color;
//    case 2:
//        color->copy(blue);
//        return color;
//    default:
//        color->copy(yellow);
//        return color;
//    }
//>>>>>>> Stashed changes
//}

//Color Color::getBlue() {
//    return Color(0, 191, 255);
//}

//Color Color::getYellow() {
//    return Color(245, 227, 68);
//}

//Color Color::getWhite() {
//    return Color(255, 255, 255);
//}

//<<<<<<< Updated upstream
//Color Color::getRandom(){
//    QRandomGenerator rand;
//    switch (rand.bounded(0, 3)) {
//=======
//void Color::setYellow() {
//    copy(yellow);
//}

//void Color::setWhite() {
////    redValue = white->redValue;
////    greenValue = 255;
////    blueValue = 255;
//    copy(white);
//}

//void Color::setRandom(){
//    switch (QRandomGenerator::global()->bounded(0, 4)) {
//>>>>>>> Stashed changes
//    case 0:
//        return getRed();
//    case 1:
//        return getGreen();
//    case 2:
//<<<<<<< Updated upstream
//        return getBlue();
//    default:
//        return getYellow();
//=======
//        copy(blue);
//        break;
//    case 3:
//        copy(yellow);
//        break;
//>>>>>>> Stashed changes
//    }
//}

//QColor Color::getQColor() {
//    return QColor(redValue, greenValue, blueValue);
//}

#include "headers/color.h"

#include <QColor>
#include <QRandomGenerator>
#include <QDebug>

Color *Color::red = new Color(255, 91, 71);
Color *Color::green = new Color(49, 204, 50);
Color *Color::blue = new Color(0, 191, 255);
Color *Color::yellow = new Color(245, 227, 68);
Color *Color::white = new Color(255, 255, 255);

Color::Color() {
    copy(white);
}

Color::Color(int redParameter, int greenParameter, int blueParameter)
{
    redValue = redParameter;
    greenValue = greenParameter;
    blueValue = blueParameter;
}

Color *Color::getRed() {
    Color *color = new Color();
    color->copy(red);
    return color;
}

Color *Color::getGreen() {
    Color *color = new Color();
    color->copy(green);
    return color;
}

Color *Color::getBlue() {
    Color *color = new Color();
    color->copy(blue);
    return color;
}

Color *Color::getYellow() {
    Color *color = new Color();
    color->copy(yellow);
    return color;
}

Color *Color::getWhite() {
    Color *color = new Color();
    color->copy(white);
    return color;
}

Color *Color::getRandom(){
    Color *color = new Color();
    switch (QRandomGenerator::global()->bounded(0, 4)) {
    case 0:
        color->copy(red);
        return color;
    case 1:
        color->copy(green);
        return color;
    case 2:
        color->copy(blue);
        return color;
    default:
        color->copy(yellow);
        return color;
    }
}

void Color::setRed() {
    copy(red);
}

void Color::setGreen() {
    copy(green);
}

void Color::setBlue() {
    copy(blue);
}

void Color::setYellow() {
    copy(yellow);
}

void Color::setWhite() {
    copy(white);
}

void Color::setRandom(){
    switch (QRandomGenerator::global()->bounded(0, 4)) {
    case 0:
        copy(red);
        break;
    case 1:
        copy(green);
        break;
    case 2:
        copy(blue);
        break;
    default:
        copy(yellow);
        break;
    }
}

QColor Color::qColor() {
    return QColor(redValue, greenValue, blueValue);
}

void Color::copy(Color *color) {
    redValue = color->redValue;
    greenValue = color->greenValue;
    blueValue = color->blueValue;
}
