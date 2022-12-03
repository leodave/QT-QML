/****************************************************************************
** Meta object code from reading C++ file 'serialsender.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SerialSender/serialsender.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialsender.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_SerialSender_t {
    uint offsetsAndSizes[28];
    char stringdata0[13];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[14];
    char stringdata5[6];
    char stringdata6[9];
    char stringdata7[10];
    char stringdata8[9];
    char stringdata9[5];
    char stringdata10[11];
    char stringdata11[9];
    char stringdata12[19];
    char stringdata13[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_SerialSender_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_SerialSender_t qt_meta_stringdata_SerialSender = {
    {
        QT_MOC_LITERAL(0, 12),  // "SerialSender"
        QT_MOC_LITERAL(13, 15),  // "portNameChanged"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 4),  // "name"
        QT_MOC_LITERAL(35, 13),  // "valueRecieved"
        QT_MOC_LITERAL(49, 5),  // "value"
        QT_MOC_LITERAL(55, 8),  // "openPort"
        QT_MOC_LITERAL(64, 9),  // "closePort"
        QT_MOC_LITERAL(74, 8),  // "sendByte"
        QT_MOC_LITERAL(83, 4),  // "data"
        QT_MOC_LITERAL(88, 10),  // "sendString"
        QT_MOC_LITERAL(99, 8),  // "readByte"
        QT_MOC_LITERAL(108, 18),  // "listAvailablePorts"
        QT_MOC_LITERAL(127, 8)   // "PortName"
    },
    "SerialSender",
    "portNameChanged",
    "",
    "name",
    "valueRecieved",
    "value",
    "openPort",
    "closePort",
    "sendByte",
    "data",
    "sendString",
    "readByte",
    "listAvailablePorts",
    "PortName"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_SerialSender[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    2 /* Public */,
       4,    1,   65,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   68,    2, 0x0a,    6 /* Public */,
       7,    0,   69,    2, 0x0a,    7 /* Public */,
       8,    1,   70,    2, 0x0a,    8 /* Public */,
      10,    1,   73,    2, 0x0a,   10 /* Public */,
      11,    0,   76,    2, 0x08,   12 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   77,    2, 0x02,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Char,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Char,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QStringList,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00015103, uint(0), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject SerialSender::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_SerialSender.offsetsAndSizes,
    qt_meta_data_SerialSender,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_SerialSender_t,
        // property 'PortName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SerialSender, std::true_type>,
        // method 'portNameChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'valueRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char, std::false_type>,
        // method 'openPort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'closePort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sendByte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char, std::false_type>,
        // method 'sendString'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'readByte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'listAvailablePorts'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>
    >,
    nullptr
} };

void SerialSender::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SerialSender *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->portNameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->valueRecieved((*reinterpret_cast< std::add_pointer_t<char>>(_a[1]))); break;
        case 2: _t->openPort(); break;
        case 3: _t->closePort(); break;
        case 4: _t->sendByte((*reinterpret_cast< std::add_pointer_t<char>>(_a[1]))); break;
        case 5: _t->sendString((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->readByte(); break;
        case 7: { QStringList _r = _t->listAvailablePorts();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SerialSender::*)(QString );
            if (_t _q_method = &SerialSender::portNameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SerialSender::*)(char );
            if (_t _q_method = &SerialSender::valueRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<SerialSender *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getPortName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<SerialSender *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPortName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *SerialSender::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialSender::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialSender.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SerialSender::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SerialSender::portNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialSender::valueRecieved(char _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
