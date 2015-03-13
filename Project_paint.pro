#-------------------------------------------------
#
# Project created by QtCreator 2015-02-28T21:49:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project_paint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    objectpropertieswindow.cpp \
    gui.cpp \
    core.cpp

HEADERS  += mainwindow.h \
    objectpropertieswindow.h \
    gui.h \
    core.h

FORMS    += mainwindow.ui \
    objectpropertieswindow.ui
