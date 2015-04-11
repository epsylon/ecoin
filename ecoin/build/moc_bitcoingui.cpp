/****************************************************************************
** Meta object code from reading C++ file 'bitcoingui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qt/bitcoingui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bitcoingui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BitcoinGUI[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      43,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      60,   41,   11,   11, 0x0a,
      89,   82,   11,   11, 0x0a,
     134,  114,   11,   11, 0x0a,
     182,  162,   11,   11, 0x0a,
     210,  203,   11,   11, 0x0a,
     229,   11,   11,   11, 0x08,
     248,   11,   11,   11, 0x08,
     266,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     311,   11,   11,   11, 0x08,
     331,   11,   11,   11, 0x08,
     354,  349,   11,   11, 0x08,
     382,   11,   11,   11, 0x28,
     403,  349,   11,   11, 0x08,
     433,   11,   11,   11, 0x28,
     456,   11,   11,   11, 0x08,
     473,   11,   11,   11, 0x08,
     495,  488,   11,   11, 0x08,
     565,  548,   11,   11, 0x08,
     606,  548,   11,   11, 0x08,
     643,   82,   11,   11, 0x08,
     663,   11,   11,   11, 0x08,
     678,   11,   11,   11, 0x08,
     697,   11,   11,   11, 0x08,
     710,   11,   11,   11, 0x08,
     725,   11,   11,   11, 0x08,
     747,  349,   11,   11, 0x08,
     771,   11,   11,   11, 0x28,
     802,  788,   11,   11, 0x08,
     828,   11,   11,   11, 0x28,
     861,  847,   11,   11, 0x08,
     889,   11,   11,   11, 0x28,
     913,   11,   11,   11, 0x08,
     928,   11,   11,   11, 0x08,
     943,   11,   11,   11, 0x08,
     963,   11,   11,   11, 0x08,
     983,   11,   11,   11, 0x08,
    1000,   11,   11,   11, 0x08,
    1021, 1015,   11,   11, 0x08,
    1042, 1015,   11,   11, 0x08,
    1068, 1061,   11,   11, 0x08,
    1095, 1093,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BitcoinGUI[] = {
    "BitcoinGUI\0\0count\0setNumConnections(int)\0"
    "count,nTotalBlocks\0setNumBlocks(int,int)\0"
    "status\0setEncryptionStatus(int)\0"
    "title,message,modal\0error(QString,QString,bool)\0"
    "nFeeRequired,payFee\0askFee(qint64,bool*)\0"
    "strURI\0handleURI(QString)\0gotoOverviewPage()\0"
    "gotoHistoryPage()\0gotoAddressBookPage()\0"
    "gotoReceiveCoinsPage()\0gotoSendCoinsPage()\0"
    "gotoMessagePage()\0addr\0"
    "gotoSignMessageTab(QString)\0"
    "gotoSignMessageTab()\0gotoVerifyMessageTab(QString)\0"
    "gotoVerifyMessageTab()\0optionsClicked()\0"
    "aboutClicked()\0reason\0"
    "trayIconActivated(QSystemTrayIcon::ActivationReason)\0"
    "parent,start,end\0"
    "incomingTransaction(QModelIndex,int,int)\0"
    "incomingMessage(QModelIndex,int,int)\0"
    "encryptWallet(bool)\0backupWallet()\0"
    "changePassphrase()\0lockWallet()\0"
    "unlockWallet()\0unlockWalletStaking()\0"
    "savingsClicked(QString)\0savingsClicked()\0"
    "transactionId\0gotoBlockBrowser(QString)\0"
    "gotoBlockBrowser()\0fToggleHidden\0"
    "showNormalIfMinimized(bool)\0"
    "showNormalIfMinimized()\0toggleHidden()\0"
    "updateWeight()\0updateStakingIcon()\0"
    "ecoinSpeedClicked()\0websiteClicked()\0"
    "forumClicked()\0theme\0changeTheme(QString)\0"
    "loadTheme(QString)\0themes\0"
    "listThemes(QStringList&)\0e\0"
    "keyPressEvent(QKeyEvent*)\0"
};

void BitcoinGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BitcoinGUI *_t = static_cast<BitcoinGUI *>(_o);
        switch (_id) {
        case 0: _t->setNumConnections((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setNumBlocks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setEncryptionStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->error((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->askFee((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< bool*(*)>(_a[2]))); break;
        case 5: _t->handleURI((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->gotoOverviewPage(); break;
        case 7: _t->gotoHistoryPage(); break;
        case 8: _t->gotoAddressBookPage(); break;
        case 9: _t->gotoReceiveCoinsPage(); break;
        case 10: _t->gotoSendCoinsPage(); break;
        case 11: _t->gotoMessagePage(); break;
        case 12: _t->gotoSignMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->gotoSignMessageTab(); break;
        case 14: _t->gotoVerifyMessageTab((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->gotoVerifyMessageTab(); break;
        case 16: _t->optionsClicked(); break;
        case 17: _t->aboutClicked(); break;
        case 18: _t->trayIconActivated((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 19: _t->incomingTransaction((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 20: _t->incomingMessage((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 21: _t->encryptWallet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->backupWallet(); break;
        case 23: _t->changePassphrase(); break;
        case 24: _t->lockWallet(); break;
        case 25: _t->unlockWallet(); break;
        case 26: _t->unlockWalletStaking(); break;
        case 27: _t->savingsClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: _t->savingsClicked(); break;
        case 29: _t->gotoBlockBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: _t->gotoBlockBrowser(); break;
        case 31: _t->showNormalIfMinimized((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->showNormalIfMinimized(); break;
        case 33: _t->toggleHidden(); break;
        case 34: _t->updateWeight(); break;
        case 35: _t->updateStakingIcon(); break;
        case 36: _t->ecoinSpeedClicked(); break;
        case 37: _t->websiteClicked(); break;
        case 38: _t->forumClicked(); break;
        case 39: _t->changeTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 40: _t->loadTheme((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 41: _t->listThemes((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 42: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BitcoinGUI::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BitcoinGUI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BitcoinGUI,
      qt_meta_data_BitcoinGUI, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BitcoinGUI::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BitcoinGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BitcoinGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BitcoinGUI))
        return static_cast<void*>(const_cast< BitcoinGUI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BitcoinGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 43)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 43;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
