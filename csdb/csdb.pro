QT += core
QT -= gui

TARGET = csdb
CONFIG += console
CONFIG -= app_bundle
QMAKE_CXXFLAGS += -std=c++0x
TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    personlist.cpp

HEADERS += \
    person.h \
    personlist.h

DISTFILES += \
    data.txt

