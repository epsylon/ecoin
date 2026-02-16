// ECOin - Copyright (c) - 2014/2026 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef ECOINFIELD_H
#define ECOINFIELD_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QDoubleSpinBox;
class QValueComboBox;
QT_END_NAMESPACE

class EcoinAmountField: public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qint64 value READ value WRITE setValue NOTIFY textChanged USER true)
public:
    explicit EcoinAmountField(QWidget *parent = 0);

    qint64 value(bool *valid=0) const;
    void setValue(qint64 value);
    void setValid(bool valid);
    bool validate();
    void setDisplayUnit(int unit);
    void clear();

    QWidget *setupTabChain(QWidget *prev);

signals:
    void textChanged();

protected:
    bool eventFilter(QObject *object, QEvent *event);

private:
    QDoubleSpinBox *amount;
    QValueComboBox *unit;
    int currentUnit;

    void setText(const QString &text);
    QString text() const;

private slots:
    void unitChanged(int idx);

};

#endif // ECOINFIELD_H
