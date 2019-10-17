#include "color.h"

#include <QColor>
#include <QtMath>
//#include <QRandomGenerator>

Color::Color(int red, int green, int blue)
{
    redValue = red;
    greenValue = green;
    blueValue = blue;
}

static Color getRed() {
    return Color(255, 91, 71);
}

static Color getGreen() {
    return Color(50, 205, 50);
}

static Color getBlue() {
    return Color(0, 191, 255);
}

static Color getYellow() {
    return Color(245, 227, 68);
}

static Color getAverage(QList<Color> colors) {
    int rSum = 0, gSum = 0, bSum = 0;
    for (int  i = 0; i < colors.size(); i++) {
        rSum += static_cast<int>(qPow(colors.at(i).redValue, 2));
        gSum += static_cast<int>(qPow(colors.at(i).blueValue, 2));
        bSum += static_cast<int>(qPow(colors.at(i).greenValue, 2));
    }

    int rAvg, gAvg, bAvg;
    rAvg = static_cast<int>(qSqrt(rSum / static_cast<double>(colors.size())));
    gAvg = static_cast<int>(qSqrt(gSum / static_cast<double>(colors.size())));
    bAvg = static_cast<int>(qSqrt(bSum / static_cast<double>(colors.size())));

    return Color(rAvg, gAvg, bAvg);
}

static Color getRandom(){
    return Color(255, 91, 71);
}

QColor Color::getQColor() {
    return QColor(redValue, greenValue, blueValue);
}
