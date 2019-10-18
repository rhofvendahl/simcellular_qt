#ifndef COLOR_H
#define COLOR_H

#include <QColor>


class Color
{
public:
    static Color getRed();
//    static Color getGreen();
//    static Color getBlue();
//    static Color getYellow();
//    static Color getWhite();
//    static Color getRandom();
\
    Color();
    Color(int red, int green, int blue);
    QColor qColor();

    int redValue;
    int greenValue;
    int blueValue;

    void setRed();
    void setGreen();
    void setBlue();
    void setYellow();
    void setWhite();
    void setRandom();

    void copy(Color *color);

private:
    static Color *red;
    static Color *green;
    static Color *blue;
    static Color *yellow;
    static Color *white;
};

#endif // COLOR_H
