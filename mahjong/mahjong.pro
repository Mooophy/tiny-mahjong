TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    game.cpp

HEADERS += \
    random_sequence.hpp \
    win.hpp \
    tile.hpp \
    player.hpp \
    game.h \
    ai.hpp

