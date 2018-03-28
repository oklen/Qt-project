/****************************************************************************
** Meta object code from reading C++ file 'ux3dw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ux3dw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ux3dw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_UX3DW_t {
    QByteArrayData data[11];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UX3DW_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UX3DW_t qt_meta_stringdata_UX3DW = {
    {
QT_MOC_LITERAL(0, 0, 5), // "UX3DW"
QT_MOC_LITERAL(1, 6, 12), // "changetoggle"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "checked"
QT_MOC_LITERAL(4, 28, 9), // "hidechart"
QT_MOC_LITERAL(5, 38, 11), // "enablechart"
QT_MOC_LITERAL(6, 50, 7), // "rotatex"
QT_MOC_LITERAL(7, 58, 8), // "rotation"
QT_MOC_LITERAL(8, 67, 7), // "rotatey"
QT_MOC_LITERAL(9, 75, 6), // "zoomto"
QT_MOC_LITERAL(10, 82, 4) // "zoom"

    },
    "UX3DW\0changetoggle\0\0checked\0hidechart\0"
    "enablechart\0rotatex\0rotation\0rotatey\0"
    "zoomto\0zoom"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UX3DW[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    1,   49,    2, 0x0a /* Public */,
       8,    1,   52,    2, 0x0a /* Public */,
       9,    1,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

void UX3DW::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UX3DW *_t = static_cast<UX3DW *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changetoggle((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->hidechart(); break;
        case 2: _t->enablechart(); break;
        case 3: _t->rotatex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->rotatey((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->zoomto((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject UX3DW::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_UX3DW.data,
      qt_meta_data_UX3DW,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *UX3DW::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UX3DW::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UX3DW.stringdata0))
        return static_cast<void*>(this);
    return QFrame::qt_metacast(_clname);
}

int UX3DW::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
