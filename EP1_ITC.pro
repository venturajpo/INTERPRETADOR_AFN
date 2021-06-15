TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG ~= s/-O[0123s]//g
CONFIG += -O0

SOURCES += \
        automato.cpp \
        glc.cpp

HEADERS += \
    automato.h

DISTFILES += \
    LEIAME.TXT \
    Makefile
