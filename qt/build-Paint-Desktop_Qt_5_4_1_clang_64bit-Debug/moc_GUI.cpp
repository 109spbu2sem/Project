/****************************************************************************
** Meta object code from reading C++ file 'GUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../include/gui/GUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GUI_t {
    QByteArrayData data[22];
    char stringdata[188];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUI_t qt_meta_stringdata_GUI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "GUI"
QT_MOC_LITERAL(1, 4, 16), // "statusBarChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 13), // "newPointAdded"
QT_MOC_LITERAL(4, 36, 1), // "x"
QT_MOC_LITERAL(5, 38, 1), // "y"
QT_MOC_LITERAL(6, 40, 15), // "newSegmentAdded"
QT_MOC_LITERAL(7, 56, 3), // "a_x"
QT_MOC_LITERAL(8, 60, 3), // "a_y"
QT_MOC_LITERAL(9, 64, 3), // "b_x"
QT_MOC_LITERAL(10, 68, 3), // "b_y"
QT_MOC_LITERAL(11, 72, 9), // "statusBar"
QT_MOC_LITERAL(12, 82, 12), // "setStatusBar"
QT_MOC_LITERAL(13, 95, 6), // "String"
QT_MOC_LITERAL(14, 102, 8), // "newPoint"
QT_MOC_LITERAL(15, 111, 5), // "Point"
QT_MOC_LITERAL(16, 117, 11), // "setNewPoint"
QT_MOC_LITERAL(17, 129, 11), // "addNewPoint"
QT_MOC_LITERAL(18, 141, 10), // "newSegment"
QT_MOC_LITERAL(19, 152, 7), // "Segment"
QT_MOC_LITERAL(20, 160, 13), // "setNewSegment"
QT_MOC_LITERAL(21, 174, 13) // "addNewSegment"

    },
    "GUI\0statusBarChanged\0\0newPointAdded\0"
    "x\0y\0newSegmentAdded\0a_x\0a_y\0b_x\0b_y\0"
    "statusBar\0setStatusBar\0String\0newPoint\0"
    "Point\0setNewPoint\0addNewPoint\0newSegment\0"
    "Segment\0setNewSegment\0addNewSegment"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       1,  118, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    2,   70,    2, 0x06 /* Public */,
       6,    4,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   84,    2, 0x0a /* Public */,
      12,    1,   85,    2, 0x0a /* Public */,
      14,    0,   88,    2, 0x0a /* Public */,
      16,    2,   89,    2, 0x0a /* Public */,
      17,    2,   94,    2, 0x0a /* Public */,
      18,    0,   99,    2, 0x0a /* Public */,
      20,    4,  100,    2, 0x0a /* Public */,
      21,    4,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::QVariant,
    QMetaType::Void, QMetaType::QVariant,   13,
    0x80000000 | 15,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    4,    5,
    0x80000000 | 19,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,
    QMetaType::Void, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double,    7,    8,    9,   10,

 // properties: name, type, flags
      11, QMetaType::QVariant, 0x00495103,

 // properties: notify_signal_id
       0,

       0        // eod
};

void GUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GUI *_t = static_cast<GUI *>(_o);
        switch (_id) {
        case 0: _t->statusBarChanged(); break;
        case 1: _t->newPointAdded((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 2: _t->newSegmentAdded((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 3: { QVariant _r = _t->statusBar();
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = _r; }  break;
        case 4: _t->setStatusBar((*reinterpret_cast< const QVariant(*)>(_a[1]))); break;
        case 5: { Point _r = _t->newPoint();
            if (_a[0]) *reinterpret_cast< Point*>(_a[0]) = _r; }  break;
        case 6: _t->setNewPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 7: _t->addNewPoint((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: { Segment _r = _t->newSegment();
            if (_a[0]) *reinterpret_cast< Segment*>(_a[0]) = _r; }  break;
        case 9: _t->setNewSegment((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 10: _t->addNewSegment((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GUI::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::statusBarChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GUI::*_t)(double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::newPointAdded)) {
                *result = 1;
            }
        }
        {
            typedef void (GUI::*_t)(double , double , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GUI::newSegmentAdded)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject GUI::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GUI.data,
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
    return QObject::qt_metacast(_clname);
}

int GUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariant*>(_v) = statusBar(); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setStatusBar(*reinterpret_cast< QVariant*>(_v)); break;
        default: break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GUI::statusBarChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void GUI::newPointAdded(double _t1, double _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUI::newSegmentAdded(double _t1, double _t2, double _t3, double _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
