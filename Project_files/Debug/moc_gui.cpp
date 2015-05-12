/****************************************************************************
** Meta object code from reading C++ file 'gui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lib/gui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[19];
    char stringdata[423];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 24), // "on_openAddingBTN_clicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 30), // "on_ruleBox_currentIndexChanged"
QT_MOC_LITERAL(4, 61, 5), // "index"
QT_MOC_LITERAL(5, 67, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 89, 25), // "on_concatinateBTN_clicked"
QT_MOC_LITERAL(7, 115, 24), // "on_selectBTNTool_clicked"
QT_MOC_LITERAL(8, 140, 23), // "on_pointBTNTool_clicked"
QT_MOC_LITERAL(9, 164, 22), // "on_ZoomBTNTool_clicked"
QT_MOC_LITERAL(10, 187, 29), // "on_actionRedraw_all_triggered"
QT_MOC_LITERAL(11, 217, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(12, 242, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(13, 266, 26), // "on_actionSave_As_triggered"
QT_MOC_LITERAL(14, 293, 28), // "on_actionClear_all_triggered"
QT_MOC_LITERAL(15, 322, 23), // "on_actionLoad_triggered"
QT_MOC_LITERAL(16, 346, 22), // "on_objectsList_clicked"
QT_MOC_LITERAL(17, 369, 29), // "on_openChangingDialog_clicked"
QT_MOC_LITERAL(18, 399, 23) // "on_deleteObjBTN_clicked"

    },
    "GUI\0on_openAddingBTN_clicked\0\0"
    "on_ruleBox_currentIndexChanged\0index\0"
    "on_pushButton_clicked\0on_concatinateBTN_clicked\0"
    "on_selectBTNTool_clicked\0"
    "on_pointBTNTool_clicked\0on_ZoomBTNTool_clicked\0"
    "on_actionRedraw_all_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSave_As_triggered\0"
    "on_actionClear_all_triggered\0"
    "on_actionLoad_triggered\0on_objectsList_clicked\0"
    "on_openChangingDialog_clicked\0"
    "on_deleteObjBTN_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x08 /* Private */,
       3,    1,   95,    2, 0x08 /* Private */,
       5,    0,   98,    2, 0x08 /* Private */,
       6,    0,   99,    2, 0x08 /* Private */,
       7,    0,  100,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    0,  108,    2, 0x08 /* Private */,
      16,    1,  109,    2, 0x08 /* Private */,
      17,    0,  112,    2, 0x08 /* Private */,
      18,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI *_t = static_cast<GUI *>(_o);
        switch (_id) {
        case 0: _t->on_openAddingBTN_clicked(); break;
        case 1: _t->on_ruleBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_concatinateBTN_clicked(); break;
        case 4: _t->on_selectBTNTool_clicked(); break;
        case 5: _t->on_pointBTNTool_clicked(); break;
        case 6: _t->on_ZoomBTNTool_clicked(); break;
        case 7: _t->on_actionRedraw_all_triggered(); break;
        case 8: _t->on_actionClose_triggered(); break;
        case 9: _t->on_actionSave_triggered(); break;
        case 10: _t->on_actionSave_As_triggered(); break;
        case 11: _t->on_actionClear_all_triggered(); break;
        case 12: _t->on_actionLoad_triggered(); break;
        case 13: _t->on_objectsList_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 14: _t->on_openChangingDialog_clicked(); break;
        case 15: _t->on_deleteObjBTN_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GUI.data,
      qt_meta_data_GUI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GUI.stringdata))
        return static_cast<void*>(const_cast< GUI*>(this));
    if (!strcmp(_clname, "GraphicsInterface"))
        return static_cast< GraphicsInterface*>(const_cast< GUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
