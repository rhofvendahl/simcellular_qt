#ifndef COLOR_H
#define COLOR_H

#include <QColor>


class Color
{
public:
    static Color getRed();
    static Color getGreen();
    static Color getBlue();
    static Color getYellow();
    static Color getWhite();
    static Color getRandom();
\
    Color();
    Color(int red, int green, int blue);
    QColor getQColor();

    int redValue;
    int greenValue;
    int blueValue;
};

#endif // COLOR_H
