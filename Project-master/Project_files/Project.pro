#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T21:51:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app


SOURCES += \
    ../lib/constraints/DistancePoint-Section.cpp \
    ../lib/constraints/DistanceToTheLine.cpp \
    ../lib/Color.cpp \
    ../lib/core_add.cpp \
    ../lib/core_other.cpp \
    ../lib/core_private.cpp \
    ../lib/core_stream.cpp \
    ../lib/global.cpp \
    ../lib/gui.cpp \
    ../lib/LineSkin.cpp \
    ../lib/main.cpp \
    ../lib/ObjectSkin.cpp \
    ../lib/structures.cpp \
    ../lib/objectpropertieswindow.cpp \
    ../lib/mycanvas.cpp \
    ../lib/Save.cpp

HEADERS  += \
    ../lib/constraints/AngleSegment-Segment.h \
    ../lib/constraints/AspectRatio.h \
    ../lib/constraints/Collector.h \
    ../lib/constraints/DistancePoint-Point.h \
    ../lib/constraints/DistancePoint-Section.h \
    ../lib/constraints/DistanceToTheLine.h \
    ../lib/constraints/ThreePointsOnTheLine.h \
    ../lib/storages/heshtable.h \
    ../lib/storages/matrix.h \
    ../lib/storages/storage_array.h \
    ../lib/storages/storage_list.h \
    ../lib/Color.h \
    ../lib/core.h \
    ../lib/global.h \
    ../lib/gui.h \
    ../lib/Id.h \
    ../lib/LineSkin.h \
    ../lib/ObjectSkin.h \
    ../lib/structures.h \
    ../lib/objectpropertieswindow.h \
    ../lib/mycanvas.h \
    ../lib/Save.h

FORMS += \
    ../lib/QTforms/gui.ui \
    ../lib/QTforms/objectpropertieswindow.ui
