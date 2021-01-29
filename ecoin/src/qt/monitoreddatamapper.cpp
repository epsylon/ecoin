// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#include "monitoreddatamapper.h"
#include <QWidget>
#include <QMetaObject>
#include <QMetaProperty>

MonitoredDataMapper::MonitoredDataMapper(QObject *parent) :
    QDataWidgetMapper(parent)
{
}

void MonitoredDataMapper::addMapping(QWidget *widget, int section)
{
    QDataWidgetMapper::addMapping(widget, section);
    addChangeMonitor(widget);
}

void MonitoredDataMapper::addMapping(QWidget *widget, int section, const QByteArray &propertyName)
{
    QDataWidgetMapper::addMapping(widget, section, propertyName);
    addChangeMonitor(widget);
}

void MonitoredDataMapper::addChangeMonitor(QWidget *widget)
{
    QMetaProperty prop = widget->metaObject()->userProperty();
    int signal = prop.notifySignalIndex();
    int method = this->metaObject()->indexOfMethod("viewModified()");
    if(signal != -1 && method != -1)
    {
        QMetaObject::connect(widget, signal, this, method);
    }
}
