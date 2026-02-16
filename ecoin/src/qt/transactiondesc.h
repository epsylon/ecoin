// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef TRANSACTIONDESC_H
#define TRANSACTIONDESC_H

#include <QString>
#include <QObject>
#include <string>

class CWallet;
class CWalletTx;

/** Provide a human-readable extended HTML description of a transaction.*/
class TransactionDesc: public QObject
{
    Q_OBJECT
public:
    static QString toHTML(CWallet *wallet, CWalletTx &wtx);
private:
    TransactionDesc() {}

    static QString FormatTxStatus(const CWalletTx& wtx);
};

#endif // TRANSACTIONDESC_H
