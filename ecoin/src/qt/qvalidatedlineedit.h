// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef QVALIDATEDLINEEDIT_H
#define QVALIDATEDLINEEDIT_H

#include <QLineEdit>

class QValidatedLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit QValidatedLineEdit(QWidget *parent = 0);
    void clear();

protected:
    void focusInEvent(QFocusEvent *evt);

private:
    bool valid;

public slots:
    void setValid(bool valid);

private slots:
    void markValid();
};

#endif // QVALIDATEDLINEEDIT_H
