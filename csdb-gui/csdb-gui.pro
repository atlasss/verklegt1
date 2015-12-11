#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T09:44:55
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = csdb-gui
TEMPLATE = app

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x


SOURCES += main.cpp\
        mainwindow.cpp \
    computerlist.cpp \
    personlist.cpp \
    computer.cpp \
    dataaccess.cpp \
    person.cpp

HEADERS  += mainwindow.h \
    computer.h \
    personlist.h \
    computerlist.h \
    dataaccess.h \
    person.h

FORMS    += mainwindow.ui
