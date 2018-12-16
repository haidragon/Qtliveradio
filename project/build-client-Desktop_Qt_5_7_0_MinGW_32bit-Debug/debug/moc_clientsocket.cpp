/****************************************************************************
** Meta object code from reading C++ file 'clientsocket.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/clientsocket.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClientSocket_t {
    QByteArrayData data[16];
    char stringdata0[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientSocket_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientSocket_t qt_meta_stringdata_ClientSocket = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ClientSocket"
QT_MOC_LITERAL(1, 13, 6), // "sigReg"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 6), // "user_t"
QT_MOC_LITERAL(4, 28, 4), // "user"
QT_MOC_LITERAL(5, 33, 8), // "sigLogin"
QT_MOC_LITERAL(6, 42, 11), // "sigRoomName"
QT_MOC_LITERAL(7, 54, 11), // "sigRoomList"
QT_MOC_LITERAL(8, 66, 11), // "sigChatName"
QT_MOC_LITERAL(9, 78, 11), // "sigChatList"
QT_MOC_LITERAL(10, 90, 13), // "sigMasterExit"
QT_MOC_LITERAL(11, 104, 11), // "sigChatText"
QT_MOC_LITERAL(12, 116, 8), // "sigVideo"
QT_MOC_LITERAL(13, 125, 10), // "sigunVideo"
QT_MOC_LITERAL(14, 136, 5), // "sigBs"
QT_MOC_LITERAL(15, 142, 11) // "onReadyRead"

    },
    "ClientSocket\0sigReg\0\0user_t\0user\0"
    "sigLogin\0sigRoomName\0sigRoomList\0"
    "sigChatName\0sigChatList\0sigMasterExit\0"
    "sigChatText\0sigVideo\0sigunVideo\0sigBs\0"
    "onReadyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientSocket[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       6,    1,   80,    2, 0x06 /* Public */,
       7,    1,   83,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
       9,    1,   89,    2, 0x06 /* Public */,
      10,    1,   92,    2, 0x06 /* Public */,
      11,    1,   95,    2, 0x06 /* Public */,
      12,    1,   98,    2, 0x06 /* Public */,
      13,    1,  101,    2, 0x06 /* Public */,
      14,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ClientSocket::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientSocket *_t = static_cast<ClientSocket *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigReg((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 1: _t->sigLogin((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 2: _t->sigRoomName((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 3: _t->sigRoomList((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 4: _t->sigChatName((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 5: _t->sigChatList((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 6: _t->sigMasterExit((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 7: _t->sigChatText((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 8: _t->sigVideo((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 9: _t->sigunVideo((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 10: _t->sigBs((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 11: _t->onReadyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigReg)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigLogin)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigRoomName)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigRoomList)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigChatName)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigChatList)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigMasterExit)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigChatText)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigVideo)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigunVideo)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (ClientSocket::*_t)(user_t );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClientSocket::sigBs)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject ClientSocket::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientSocket.data,
      qt_meta_data_ClientSocket,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientSocket.stringdata0))
        return static_cast<void*>(const_cast< ClientSocket*>(this));
    return QObject::qt_metacast(_clname);
}

int ClientSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ClientSocket::sigReg(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientSocket::sigLogin(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientSocket::sigRoomName(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientSocket::sigRoomList(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientSocket::sigChatName(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientSocket::sigChatList(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientSocket::sigMasterExit(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ClientSocket::sigChatText(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ClientSocket::sigVideo(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void ClientSocket::sigunVideo(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void ClientSocket::sigBs(user_t _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_END_MOC_NAMESPACE
