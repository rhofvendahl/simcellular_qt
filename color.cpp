#include "color.h"

#include <QColor>
#include <QRandomGenerator>
#include <QDebug>

Color *Color::red = new Color(255, 91, 71);
Color *Color::green = new Color(50, 255, 50);
Color *Color::blue = new Color(0, 191, 255);
Color *Color::yellow = new Color(245, 227, 68);
Color *Color::white = new Color(255, 255, 255);

Color::Color() {
//    qDebug() << "default color (white)";
    copy(white);

//    qDebug() << "blueValue of blue is:" << blue->redValue << blue->greenValue << blue->blueValue;

}

Color::Color(int redParameter, int greenParameter, int blueParameter)
{
//    qDebug() << "new color:" << red << blue << green;
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
    switch (QRandomGenerator::global()->bounded(0, 3)) {
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
//    qDebug() << "trying!" << redValue << "should be:";
//    qDebug() << blue->redValue;
    copy(blue);
//    qDebug() << redValue << "should be" << blue->redValue;
}

void Color::setYellow() {
    copy(yellow);
}

void Color::setWhite() {
//    redValue = white->redValue;
//    greenValue = 255;
//    blueValue = 255;
    copy(white);
}

void Color::setRandom(){
    switch (QRandomGenerator::global()->bounded(0, 3)) {
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
//    qDebug() << "copying";
//    Color *someColor = new Color(0, 0, 255);
//    qDebug() << "testing out a new shade of blue!" << someColor->redValue << someColor->greenValue << someColor->blueValue;
    redValue = color->redValue;
    greenValue = color->greenValue;
    blueValue = color->blueValue;
//    qDebug() << "done copying";
}
