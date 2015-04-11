/****************************************************************************
** Meta object code from reading C++ file 'tail.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/tail.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tail[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,    6,    5,    5, 0x05,
      33,   29,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,    5,    5,    5, 0x08,
      60,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tail[] = {
    "Tail\0\0line\0sendLine(QString)\0arg\0"
    "Error(QString)\0checkLine()\0stopProcess()\0"
};

void Tail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tail *_t = static_cast<Tail *>(_o);
        switch (_id) {
        case 0: _t->sendLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->Error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->checkLine(); break;
        case 3: _t->stopProcess(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tail::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tail::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Tail,
      qt_meta_data_Tail, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tail::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tail))
        return static_cast<void*>(const_cast< Tail*>(this));
    return QThread::qt_metacast(_clname);
}

int Tail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Tail::sendLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Tail::Error(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
