// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef CSVMODELWRITER_H
#define CSVMODELWRITER_H

#include <QObject>
#include <QList>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
QT_END_NAMESPACE
class CSVModelWriter : public QObject
{
    Q_OBJECT
public:
    explicit CSVModelWriter(const QString &filename, QObject *parent = 0);
    void setModel(const QAbstractItemModel *model);
    void addColumn(const QString &title, int column, int role=Qt::EditRole);
    bool write();

private:
    QString filename;
    const QAbstractItemModel *model;
    struct Column
    {
        QString title;
        int column;
        int role;
    };
    QList<Column> columns;

signals:

public slots:

};

#endif // CSVMODELWRITER_H
