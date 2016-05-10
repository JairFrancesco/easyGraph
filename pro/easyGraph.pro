#-------------------------------------------------
#
# Project created by QtCreator 2016-04-16T22:40:43
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = easyGraph
TEMPLATE = app

INCLUDEPATH += ../Controller \
                ../Model \
                ../View

SOURCES += ../main.cpp\
        ../View/mainwindow.cpp \
    ../Model/countmodel.cpp \
    ../Controller/countcontroller.cpp \
    ../Controller/appcontroller.cpp \
    settingsdialog.cpp \
    myopengl.cpp \
    myopengl2.cpp

HEADERS  += ../View/mainwindow.h \
    ../Model/countmodel.h \
    ../Controller/countcontroller.h \
    ../Controller/appcontroller.h \
    settingsdialog.h \
    myopengl.h \
    myopengl2.h

FORMS    += ../View/mainwindow.ui \
    settingsdialog.ui

DESTDIR = ../temp
OBJECTS_DIR = ../temp


MOC_DIR = ../temp
UI_DIR = ../temp

RESOURCES += \
    ../Resources/resources.qrc

DISTFILES +=


