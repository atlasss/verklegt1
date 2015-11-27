QT += core
QT -= gui

TARGET = csdb
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    personlist.cpp

HEADERS += \
    person.h \
    personlist.h

