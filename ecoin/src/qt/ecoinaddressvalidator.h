// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef ECOINADDRESSVALIDATOR_H
#define ECOINADDRESSVALIDATOR_H

#include <QRegExpValidator>

class EcoinAddressValidator : public QValidator
{
    Q_OBJECT
public:
    explicit EcoinAddressValidator(QObject *parent = 0);

    State validate(QString &input, int &pos) const;

    static const int MaxAddressLength = 35;
signals:

public slots:

};

#endif // ECOINADDRESSVALIDATOR_H
