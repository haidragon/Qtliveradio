/****************************************************************************
** Meta object code from reading C++ file 'chatroom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/chatroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ChatRoom_t {
    QByteArrayData data[22];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatRoom_t qt_meta_stringdata_ChatRoom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatRoom"
QT_MOC_LITERAL(1, 9, 13), // "onsigChatName"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "user_t"
QT_MOC_LITERAL(4, 31, 4), // "user"
QT_MOC_LITERAL(5, 36, 13), // "onsigChatList"
QT_MOC_LITERAL(6, 50, 23), // "on_chatlist_btn_clicked"
QT_MOC_LITERAL(7, 74, 15), // "onsigMasterExit"
QT_MOC_LITERAL(8, 90, 15), // "on_send_clicked"
QT_MOC_LITERAL(9, 106, 13), // "onsigChatText"
QT_MOC_LITERAL(10, 120, 16), // "on_video_clicked"
QT_MOC_LITERAL(11, 137, 10), // "onsigVideo"
QT_MOC_LITERAL(12, 148, 12), // "onsigunVideo"
QT_MOC_LITERAL(13, 161, 11), // "UdpReadRead"
QT_MOC_LITERAL(14, 173, 14), // "onvideoChanged"
QT_MOC_LITERAL(15, 188, 11), // "QVideoFrame"
QT_MOC_LITERAL(16, 200, 9), // "onTimeOut"
QT_MOC_LITERAL(17, 210, 7), // "onsigBs"
QT_MOC_LITERAL(18, 218, 13), // "on_bs_clicked"
QT_MOC_LITERAL(19, 232, 16), // "on_audio_clicked"
QT_MOC_LITERAL(20, 249, 14), // "ReadyReadAudio"
QT_MOC_LITERAL(21, 264, 15) // "on_gift_clicked"

    },
    "ChatRoom\0onsigChatName\0\0user_t\0user\0"
    "onsigChatList\0on_chatlist_btn_clicked\0"
    "onsigMasterExit\0on_send_clicked\0"
    "onsigChatText\0on_video_clicked\0"
    "onsigVideo\0onsigunVideo\0UdpReadRead\0"
    "onvideoChanged\0QVideoFrame\0onTimeOut\0"
    "onsigBs\0on_bs_clicked\0on_audio_clicked\0"
    "ReadyReadAudio\0on_gift_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatRoom[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x08 /* Private */,
       5,    1,  102,    2, 0x08 /* Private */,
       6,    0,  105,    2, 0x08 /* Private */,
       7,    1,  106,    2, 0x08 /* Private */,
       8,    0,  109,    2, 0x08 /* Private */,
       9,    1,  110,    2, 0x08 /* Private */,
      10,    0,  113,    2, 0x08 /* Private */,
      11,    1,  114,    2, 0x08 /* Private */,
      12,    1,  117,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    1,  121,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    1,  125,    2, 0x08 /* Private */,
      18,    0,  128,    2, 0x08 /* Private */,
      19,    0,  129,    2, 0x08 /* Private */,
      20,    0,  130,    2, 0x08 /* Private */,
      21,    0,  131,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ChatRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChatRoom *_t = static_cast<ChatRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onsigChatName((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 1: _t->onsigChatList((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 2: _t->on_chatlist_btn_clicked(); break;
        case 3: _t->onsigMasterExit((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 4: _t->on_send_clicked(); break;
        case 5: _t->onsigChatText((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 6: _t->on_video_clicked(); break;
        case 7: _t->onsigVideo((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 8: _t->onsigunVideo((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 9: _t->UdpReadRead(); break;
        case 10: _t->onvideoChanged((*reinterpret_cast< QVideoFrame(*)>(_a[1]))); break;
        case 11: _t->onTimeOut(); break;
        case 12: _t->onsigBs((*reinterpret_cast< user_t(*)>(_a[1]))); break;
        case 13: _t->on_bs_clicked(); break;
        case 14: _t->on_audio_clicked(); break;
        case 15: _t->ReadyReadAudio(); break;
        case 16: _t->on_gift_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVideoFrame >(); break;
            }
            break;
        }
    }
}

const QMetaObject ChatRoom::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ChatRoom.data,
      qt_meta_data_ChatRoom,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ChatRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ChatRoom.stringdata0))
        return static_cast<void*>(const_cast< ChatRoom*>(this));
    return QDialog::qt_metacast(_clname);
}

int ChatRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
