QT += core
QT -= gui

TARGET = csdb
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    personlist.cpp \
    display.cpp \
    controller.cpp

HEADERS += \
    person.h \
    personlist.h \
    display.h \
    controller.h

DISTFILES += \
    data.txt
