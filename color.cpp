#include "color.h"

#include <QColor>
#include <QRandomGenerator>

Color::Color() {
    Color cheatSheet = getWhite();
    redValue = cheatSheet.redValue;
    greenValue = cheatSheet.greenValue;
    blueValue = cheatSheet.blueValue;
}

Color::Color(int red, int green, int blue)
{
    redValue = red;
    greenValue = green;
    blueValue = blue;
}

Color Color::getRed() {
    return Color(255, 91, 71);
}

Color Color::getGreen() {
    return Color(50, 205, 50);
}

Color Color::getBlue() {
    return Color(0, 191, 255);
}

Color Color::getYellow() {
    return Color(245, 227, 68);
}

Color Color::getWhite() {
    return Color(255, 255, 255);
}

Color Color::getRandom(){
    QRandomGenerator rand;
    switch (rand.bounded(0, 3)) {
    case 0:
        return getRed();
    case 1:
        return getGreen();
    case 2:
        return getBlue();
    default:
        return getYellow();
    }
}

QColor Color::getQColor() {
    return QColor(redValue, greenValue, blueValue);
}
