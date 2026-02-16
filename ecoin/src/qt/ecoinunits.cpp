// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#include "ecoinunits.h"
#include <QStringList>

EcoinUnits::EcoinUnits(QObject *parent):
        QAbstractListModel(parent),
        unitlist(availableUnits())
{
}

QList<EcoinUnits::Unit> EcoinUnits::availableUnits()
{
    QList<EcoinUnits::Unit> unitlist;
    unitlist.append(ECO);
    unitlist.append(mECO);
    unitlist.append(uECO);
    return unitlist;
}

bool EcoinUnits::valid(int unit)
{
    switch(unit)
    {
    case ECO:
    case mECO:
    case uECO:
        return true;
    default:
        return false;
    }
}

QString EcoinUnits::name(int unit)
{
    switch(unit)
    {
    case ECO: return QString("ECO");
    case mECO: return QString("mECO");
    case uECO: return QString::fromUtf8("μECO");
    default: return QString("???");
    }
}

QString EcoinUnits::description(int unit)
{
    switch(unit)
    {
    case ECO: return QString("Ecoins");
    case mECO: return QString("Milli-Ecoins (1 / 1,000)");
    case uECO: return QString("Micro-Ecoins (1 / 1,000,000)");
    default: return QString("???");
    }
}

qint64 EcoinUnits::factor(int unit)
{
    switch(unit)
    {
    case ECO:  return 1000000;
    case mECO: return 1000;
    case uECO: return 1;
    default:   return 1000000;
    }
}

int EcoinUnits::amountDigits(int unit)
{
    switch(unit)
    {
    case ECO: return 8; // 21,000,000 (# digits, without commas)
    case mECO: return 11; // 21,000,000,000
    case uECO: return 14; // 21,000,000,000,000
    default: return 0;
    }
}

int EcoinUnits::decimals(int unit)
{
    switch(unit)
    {
    case ECO: return 6;
    case mECO: return 3;
    case uECO: return 0;
    default: return 0;
    }
}

QString EcoinUnits::format(int unit, qint64 n, bool fPlus)
{
    if(!valid(unit))
        return QString(); // Refuse to format invalid unit
    qint64 coin = factor(unit);
    int num_decimals = decimals(unit);
    qint64 n_abs = (n > 0 ? n : -n);
    qint64 quotient = n_abs / coin;
    qint64 remainder = n_abs % coin;
    QString quotient_str = QString::number(quotient);
    QString remainder_str = QString::number(remainder).rightJustified(num_decimals, '0');

    // Right-trim excess zeros after the decimal point
    int nTrim = 0;
    for (int i = remainder_str.size()-1; i>=2 && (remainder_str.at(i) == '0'); --i)
        ++nTrim;
    remainder_str.chop(nTrim);

    if (n < 0)
        quotient_str.insert(0, '-');
    else if (fPlus && n > 0)
        quotient_str.insert(0, '+');
    return quotient_str + QString(".") + remainder_str;
}

QString EcoinUnits::formatWithUnit(int unit, qint64 amount, bool plussign)
{
    return format(unit, amount, plussign) + QString(" ") + name(unit);
}

bool EcoinUnits::parse(int unit, const QString &value, qint64 *val_out)
{
    if(!valid(unit) || value.isEmpty())
        return false; // Refuse to parse invalid unit or empty string
    int num_decimals = decimals(unit);
    QStringList parts = value.split(".");

    if(parts.size() > 2)
    {
        return false; // More than one dot
    }
    QString whole = parts[0];
    QString decimals;

    if(parts.size() > 1)
    {
        decimals = parts[1];
    }
    if(decimals.size() > num_decimals)
    {
        return false; // Exceeds max precision
    }
    bool ok = false;
    QString str = whole + decimals.leftJustified(num_decimals, '0');

    if(str.size() > 18)
    {
        return false; // Longer numbers will exceed 63 bits
    }
    qint64 retvalue = str.toLongLong(&ok);
    if(val_out)
    {
        *val_out = retvalue;
    }
    return ok;
}

int EcoinUnits::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return unitlist.size();
}

QVariant EcoinUnits::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row >= 0 && row < unitlist.size())
    {
        Unit unit = unitlist.at(row);
        switch(role)
        {
        case Qt::EditRole:
        case Qt::DisplayRole:
            return QVariant(name(unit));
        case Qt::ToolTipRole:
            return QVariant(description(unit));
        case UnitRole:
            return QVariant(static_cast<int>(unit));
        }
    }
    return QVariant();
}
