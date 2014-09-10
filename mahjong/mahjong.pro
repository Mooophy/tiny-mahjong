TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11

SOURCES += main.cpp \
    player.cpp

HEADERS += \
    random_sequence.hpp \
    tile.h \
    win.hpp

