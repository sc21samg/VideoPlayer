/****************************************************************************
** Meta object code from reading C++ file 'the_player.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../2811_cw2-master-release/the_player.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'the_player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
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
struct qt_meta_stringdata_ThePlayer_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[8];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[20];
    char stringdata5[3];
    char stringdata6[7];
    char stringdata7[15];
    char stringdata8[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ThePlayer_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ThePlayer_t qt_meta_stringdata_ThePlayer = {
    {
        QT_MOC_LITERAL(0, 9),  // "ThePlayer"
        QT_MOC_LITERAL(10, 7),  // "shuffle"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 16),  // "playStateChanged"
        QT_MOC_LITERAL(36, 19),  // "QMediaPlayer::State"
        QT_MOC_LITERAL(56, 2),  // "ms"
        QT_MOC_LITERAL(59, 6),  // "jumpTo"
        QT_MOC_LITERAL(66, 14),  // "TheButtonInfo*"
        QT_MOC_LITERAL(81, 6)   // "button"
    },
    "ThePlayer",
    "shuffle",
    "",
    "playStateChanged",
    "QMediaPlayer::State",
    "ms",
    "jumpTo",
    "TheButtonInfo*",
    "button"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ThePlayer[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    1,   33,    2, 0x08,    2 /* Private */,
       6,    1,   36,    2, 0x0a,    4 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject ThePlayer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMediaPlayer::staticMetaObject>(),
    qt_meta_stringdata_ThePlayer.offsetsAndSizes,
    qt_meta_data_ThePlayer,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ThePlayer_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ThePlayer, std::true_type>,
        // method 'shuffle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'playStateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QMediaPlayer::State, std::false_type>,
        // method 'jumpTo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<TheButtonInfo *, std::false_type>
    >,
    nullptr
} };

void ThePlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThePlayer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->shuffle(); break;
        case 1: _t->playStateChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::State>>(_a[1]))); break;
        case 2: _t->jumpTo((*reinterpret_cast< std::add_pointer_t<TheButtonInfo*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *ThePlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThePlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThePlayer.stringdata0))
        return static_cast<void*>(this);
    return QMediaPlayer::qt_metacast(_clname);
}

int ThePlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMediaPlayer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
