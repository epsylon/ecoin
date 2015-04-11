/****************************************************************************
** Meta object code from reading C++ file 'savingsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/savingsdialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savingsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AutoSavingsDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x08,
      45,   18,   18,   18, 0x08,
      72,   18,   18,   18, 0x08,
     103,   18,   18,   18, 0x08,
     140,   18,   18,   18, 0x08,
     169,   18,   18,   18, 0x08,
     204,   18,   18,   18, 0x08,
     235,   18,   18,   18, 0x08,
     266,   18,   18,   18, 0x08,
     301,  295,   18,   18, 0x08,
     331,  295,   18,   18, 0x08,
     366,   18,   18,   18, 0x08,
     408,  383,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AutoSavingsDialog[] = {
    "AutoSavingsDialog\0\0on_enableButton_clicked()\0"
    "on_disableButton_clicked()\0"
    "on_addressBookButton_clicked()\0"
    "on_changeAddressBookButton_clicked()\0"
    "on_pushButton_copy_clicked()\0"
    "on_freeAddressBookButton_clicked()\0"
    "on_freeRequestButton_clicked()\0"
    "on_freeDisableButton_clicked()\0"
    "on_freeReferButton_clicked()\0reply\0"
    "replyFinished(QNetworkReply*)\0"
    "replyTimerFinished(QNetworkReply*)\0"
    "freeDoHttpPost()\0userAddress,referAddress\0"
    "freeDoReferHttpPost(QString,QString)\0"
};

void AutoSavingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        AutoSavingsDialog *_t = static_cast<AutoSavingsDialog *>(_o);
        switch (_id) {
        case 0: _t->on_enableButton_clicked(); break;
        case 1: _t->on_disableButton_clicked(); break;
        case 2: _t->on_addressBookButton_clicked(); break;
        case 3: _t->on_changeAddressBookButton_clicked(); break;
        case 4: _t->on_pushButton_copy_clicked(); break;
        case 5: _t->on_freeAddressBookButton_clicked(); break;
        case 6: _t->on_freeRequestButton_clicked(); break;
        case 7: _t->on_freeDisableButton_clicked(); break;
        case 8: _t->on_freeReferButton_clicked(); break;
        case 9: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->replyTimerFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 11: _t->freeDoHttpPost(); break;
        case 12: _t->freeDoReferHttpPost((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData AutoSavingsDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject AutoSavingsDialog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AutoSavingsDialog,
      qt_meta_data_AutoSavingsDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AutoSavingsDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AutoSavingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AutoSavingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoSavingsDialog))
        return static_cast<void*>(const_cast< AutoSavingsDialog*>(this));
    return QWidget::qt_metacast(_clname);
}

int AutoSavingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
