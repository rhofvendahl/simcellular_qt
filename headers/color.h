//#ifndef COLOR_H
//#define COLOR_H

//#include <QColor>


//class Color
//{
//public:
//    static Color getRed();
//    static Color getGreen();
//    static Color getBlue();
//    static Color getYellow();
//    static Color getWhite();
//    static Color getRandom();
//
//    Color();
//    Color(int red, int green, int blue);
//    QColor getQColor();

//    int redValue;
//    int greenValue;
//    int blueValue;
//};

//#endif // COLOR_H

// consider replacing this class with QColor (which apparently has individually set-able rgb values)

#ifndef COLOR_H
#define COLOR_H

#include <QColor>


class Color
{
public:
    static Color *red;
    static Color *green;
    static Color *blue;
    static Color *yellow;
    static Color *white;

    static Color *getRed();
    static Color *getGreen();
    static Color *getBlue();
    static Color *getYellow();
    static Color *getWhite();
    static Color *getRandom();
\
    Color();
    Color(int redParameter, int greenParameter, int blueParameter);
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

    static bool areSame(Color *color1, Color *color2);
};

#endif // COLOR_H
