#include "headers/library.h"

#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Library::Library() {
//    glider = QList<QList<bool>>({QList<bool>({false, true, false}),
//                                 QList<bool>({false, false, true}),
//                                 QList<bool>({true, true, true})});

//    toad = QList<QList<bool>>({QList<bool>({false, true, true, true}),
//                                 QList<bool>({true, true, true, false})});

//    beehive = QList<QList<bool>>({QList<bool>({false, true, true, false}),
//                                 QList<bool>({true, false, false, true}),
//                                 QList<bool>({false, true, true, false})});
    loadShapes();
}

void Library::loadShapes() {
    QFile shapesFile("../resources/shapes.json");
    shapesFile.open(QIODevice::ReadOnly);
    QByteArray shapesData = shapesFile.readAll();
    QJsonDocument shapesDoc(QJsonDocument::fromJson(shapesData));
    QJsonObject shapesObject = shapesDoc.object();
    QJsonArray shapesArray = shapesObject["shapes"].toArray();

    for (int i = 0; i < shapesArray.size(); i++) {
        QJsonArray shapeArray = shapesArray[i].toArray();
        QList<QList<bool>> shapeList;
        for (int row = 0; row < shapeArray.size(); row++) {
            QJsonArray rowArray = shapeArray[row].toArray();
            QList<bool> rowList;
            for (int column = 0; column < rowArray.size(); column++) {
                rowList += rowArray[column].toBool();
            }
            shapeList += rowList;
        }
        shapes += shapeList;
    }
}
