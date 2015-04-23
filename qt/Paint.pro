TEMPLATE = app

QT += qml quick \
      core

SOURCES += main.cpp \
    src/core/TreeStorage.cpp \
    src/gui/GUI.cpp \
    src/saveload/SaveLoad.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    include/core/constraints/IsPointOnSection.h \
    include/core/constraints/Point2SectionDistance.h \
    include/core/LinkedList_Template.h \
    include/core/Storage_Template.h \
    include/core/Structures.h \
    include/core/TreeStorage.h \
    include/gui/GUI.h
