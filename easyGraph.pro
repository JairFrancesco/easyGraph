#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T22:40:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = easyGraph
TEMPLATE = app

DEPENDPATH += Controller
INCLUDEPATH += Controller

SOURCES += main.cpp\
        View/mainwindow.cpp \
    Model/countmodel.cpp \
    Controller/countcontroller.cpp \
    Controller/appcontroller.cpp

HEADERS  += View/mainwindow.h \
    Model/countmodel.h \
    Controller/countcontroller.h \
    Controller/appcontroller.h

FORMS    += View/mainwindow.ui
