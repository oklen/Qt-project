/****************************************************************************
** Meta object code from reading C++ file 'qtmaterialflatbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "components/qtmaterialflatbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtmaterialflatbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QtMaterialFlatButton_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QtMaterialFlatButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QtMaterialFlatButton_t qt_meta_stringdata_QtMaterialFlatButton = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QtMaterialFlatButton"
QT_MOC_LITERAL(1, 21, 12), // "invokeriddle"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 15), // "foregroundColor"
QT_MOC_LITERAL(4, 51, 15), // "backgroundColor"
QT_MOC_LITERAL(5, 67, 12), // "overlayColor"
QT_MOC_LITERAL(6, 80, 23), // "disabledForegroundColor"
QT_MOC_LITERAL(7, 104, 23), // "disabledBackgroundColor"
QT_MOC_LITERAL(8, 128, 8), // "fontSize"
QT_MOC_LITERAL(9, 137, 6) // "border"

    },
    "QtMaterialFlatButton\0invokeriddle\0\0"
    "foregroundColor\0backgroundColor\0"
    "overlayColor\0disabledForegroundColor\0"
    "disabledBackgroundColor\0fontSize\0"
    "border"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QtMaterialFlatButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       7,   20, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       3, QMetaType::QColor, 0x00095103,
       4, QMetaType::QColor, 0x00095103,
       5, QMetaType::QColor, 0x00095103,
       6, QMetaType::QColor, 0x00095103,
       7, QMetaType::QColor, 0x00095103,
       8, QMetaType::QReal, 0x00095103,
       9, QMetaType::Bool, 0x00095003,

       0        // eod
};

void QtMaterialFlatButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QtMaterialFlatButton *_t = static_cast<QtMaterialFlatButton *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->invokeriddle(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        QtMaterialFlatButton *_t = static_cast<QtMaterialFlatButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QColor*>(_v) = _t->foregroundColor(); break;
        case 1: *reinterpret_cast< QColor*>(_v) = _t->backgroundColor(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = _t->overlayColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = _t->disabledForegroundColor(); break;
        case 4: *reinterpret_cast< QColor*>(_v) = _t->disabledBackgroundColor(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->fontSize(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->border(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        QtMaterialFlatButton *_t = static_cast<QtMaterialFlatButton *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 1: _t->setBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 2: _t->setOverlayColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: _t->setDisabledForegroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: _t->setDisabledBackgroundColor(*reinterpret_cast< QColor*>(_v)); break;
        case 5: _t->setFontSize(*reinterpret_cast< qreal*>(_v)); break;
        case 6: _t->setborder(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject QtMaterialFlatButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_QtMaterialFlatButton.data,
      qt_meta_data_QtMaterialFlatButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QtMaterialFlatButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QtMaterialFlatButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QtMaterialFlatButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int QtMaterialFlatButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 7;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
