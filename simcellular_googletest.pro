include(testing/simcellular_googletest/gtest_dependency.pri)

QT       += core gui widgets # added

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets  # added

TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle (commented)
CONFIG += thread
#CONFIG -= qt (commented)

DEFINES += QT_DEPRECATED_WARNINGS # added

HEADERS += \
        headers/cell.h \
        headers/color.h \
        headers/game.h \
        headers/library.h \
        headers/widget.h \
        testing/simcellular_googletest/tst_cell.h \
        testing/simcellular_googletest/tst_color.h \
        testing/simcellular_googletest/tst_game.h \
        testing/simcellular_googletest/tst_library.h \
        testing/simcellular_googletest/tst_widget.h

SOURCES += \
        sources/cell.cpp \
        sources/color.cpp \
        sources/game.cpp \
        sources/library.cpp \
        sources/widget.cpp \
        testing/simcellular_googletest/main.cpp

DISTFILES += \
    resources/black_forward_icon.png \
    resources/black_pause_icon.png \
    resources/black_play_icon.png \
    resources/black_random_icon.png \
    resources/black_step_forward_icon.png \
    resources/black_stop_icon.png \
    resources/forward_icon.png \
    resources/open_sans_condensed_light.ttf \
    resources/pause_icon.png \
    resources/play_icon.png \
    resources/random_icon.png \
    resources/shapes.json \
    resources/step_forward_icon.png \
    resources/stop_icon.png \
    resources/stylesheet.qss

FORMS += \
    forms/widget.ui
