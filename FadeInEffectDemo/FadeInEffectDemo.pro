#-------------------------------------------------
#
# Project created by QtCreator 2014-07-03T17:37:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FadeInEffectDemo
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

macx: QMAKE_CXXFLAGS += -std=c++11
