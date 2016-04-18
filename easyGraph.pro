#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T22:40:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = easyGraph
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    countmodel.cpp \
    countcontroller.cpp \
    appcontroller.cpp

HEADERS  += mainwindow.h \
    countmodel.h \
    countcontroller.h \
    appcontroller.h

FORMS    += mainwindow.ui
