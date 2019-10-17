#include "library.h"

#include <QList>

Library::Library()
{
    glider = QList<QList<bool>>({QList<bool>({false, true, false}),
                                 QList<bool>({false, false, true}),
                                 QList<bool>({true, true, true})});

    toad = QList<QList<bool>>({QList<bool>({false, true, true, true}),
                                 QList<bool>({true, true, true, false})});

    beehive = QList<QList<bool>>({QList<bool>({false, true, true, false}),
                                 QList<bool>({true, false, false, true}),
                                 QList<bool>({false, true, true, false})});

    shapes = QList<QList<QList<bool>>>({glider, toad, beehive});
}
