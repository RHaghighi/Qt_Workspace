#-------------------------------------------------
#
# Project created by QtCreator 2016-12-08T14:50:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EdgeSelection
TEMPLATE = app

LIBS += -L/usr/X11R6/lib -lX11
LIBS += -L/usr/lib/x86_64-linux-gnu -lXtst

QT += x11extras

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
