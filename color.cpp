#include "color.h"

#include <QColor>
#include <QRandomGenerator>

Color *Color::red = new Color(255, 91, 71);
Color *Color::green = new Color(50, 255, 50);
Color *Color::blue = new Color(0, 191, 255);
Color *Color::yellow = new Color(245, 227, 68);
Color *Color::white = new Color(255, 255, 255);

Color::Color() {
    copy(white);
}

Color::Color(int red, int green, int blue)
{
    redValue = red;
    greenValue = green;
    blueValue = blue;
}

//Color Color::getRed() {
//    return Color(255, 91, 71);
//}

//Color Color::getGreen() {
//    return Color(50, 205, 50);
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

//Color Color::getRandom(){
//    switch (QRandomGenerator::global()->bounded(0, 3)) {
//    case 0:
//        return red();
//    case 1:
//        return green();
//    case 2:
//        return blue();
//    default:
//        return yellow();
//    }
//}

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
    switch (QRandomGenerator::global()->bounded(0, 3)) {
    case 0:
        copy(red);
    case 1:
        copy(green)
    case 2:
        return copy(blue);
    default:
        return copy(yellow);
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
