#ifndef LIBRARY_H
#define LIBRARY_H

#include <QList>

class Library
{
public:
    Library();
    QList<QList<bool>> glider;
    QList<QList<bool>> toad;
    QList<QList<bool>> beehive;
    QList<QList<QList<bool>>> shapes;
};

#endif // LIBRARY_H
