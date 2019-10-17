#ifndef COLOR_H
#define COLOR_H

#include <QColor>


class Color
{
public:
    static Color getAverage(QList<Color> colors);
    static Color getRed();
    static Color getGreen();
    static Color getBlue();
    static Color getYellow();
    static Color getRandom();

    Color(int red, int green, int blue);
    QColor getQColor();

private:
    int redValue;
    int greenValue;
    int blueValue;
};

#endif // COLOR_H
