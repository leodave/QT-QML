/****************************************************************************
** Meta object code from reading C++ file 'filereciever.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ESGreciever/filereciever.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filereciever.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_FileReciever_t {
    uint offsetsAndSizes[24];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[8];
    char stringdata5[10];
    char stringdata6[9];
    char stringdata7[6];
    char stringdata8[9];
    char stringdata9[22];
    char stringdata10[9];
    char stringdata11[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_FileReciever_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_FileReciever_t qt_meta_stringdata_FileReciever = {
    {
        QT_MOC_LITERAL(0, 12),  // "FileReciever"
        QT_MOC_LITERAL(13, 12),  // "dataRecieved"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 4),  // "data"
        QT_MOC_LITERAL(32, 7),  // "started"
        QT_MOC_LITERAL(40, 9),  // "portError"
        QT_MOC_LITERAL(50, 8),  // "readData"
        QT_MOC_LITERAL(59, 5),  // "start"
        QT_MOC_LITERAL(65, 8),  // "portName"
        QT_MOC_LITERAL(74, 21),  // "QSerialPort::BaudRate"
        QT_MOC_LITERAL(96, 8),  // "baudRate"
        QT_MOC_LITERAL(105, 4)   // "stop"
    },
    "FileReciever",
    "dataRecieved",
    "",
    "data",
    "started",
    "portError",
    "readData",
    "start",
    "portName",
    "QSerialPort::BaudRate",
    "baudRate",
    "stop"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_FileReciever[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       4,    0,   53,    2, 0x06,    3 /* Public */,
       5,    0,   54,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,   55,    2, 0x09,    5 /* Protected */,
       7,    2,   56,    2, 0x0a,    6 /* Public */,
      11,    0,   61,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantList,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    8,   10,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FileReciever::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileReciever.offsetsAndSizes,
    qt_meta_data_FileReciever,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_FileReciever_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FileReciever, std::true_type>,
        // method 'dataRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariantList, std::false_type>,
        // method 'started'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'portError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSerialPort::BaudRate, std::false_type>,
        // method 'stop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FileReciever::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileReciever *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dataRecieved((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 1: _t->started(); break;
        case 2: _t->portError(); break;
        case 3: _t->readData(); break;
        case 4: _t->start((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QSerialPort::BaudRate>>(_a[2]))); break;
        case 5: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileReciever::*)(QVariantList );
            if (_t _q_method = &FileReciever::dataRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileReciever::*)();
            if (_t _q_method = &FileReciever::started; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileReciever::*)();
            if (_t _q_method = &FileReciever::portError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *FileReciever::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileReciever::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileReciever.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileReciever::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void FileReciever::dataRecieved(QVariantList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileReciever::started()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FileReciever::portError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
