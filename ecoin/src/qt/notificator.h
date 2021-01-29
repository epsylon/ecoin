// ECOin - Copyright (c) - 2014/2021 - GPLv3 - epsylon@riseup.net (https://03c8.net)
#ifndef NOTIFICATOR_H
#define NOTIFICATOR_H

#include <QObject>
#include <QIcon>

QT_BEGIN_NAMESPACE
class QSystemTrayIcon;
#ifdef USE_DBUS
class QDBusInterface;
#endif
QT_END_NAMESPACE

class Notificator: public QObject
{
    Q_OBJECT
public:
    Notificator(const QString &programName=QString(), QSystemTrayIcon *trayIcon=0, QWidget *parent=0);
    ~Notificator();

    // Message class
    enum Class
    {
        Information,         /**< Informational message */
        Warning,             /**< Notify user of potential problem */
        Critical             /**< An error occurred */
    };

public slots:

    void notify(Class cls, const QString &title, const QString &text,
                const QIcon &icon = QIcon(), int millisTimeout = 10000);

private:
    QWidget *parent;
    enum Mode {
        None,        /**< Ignore informational notifications, and show a modal pop-up dialog for Critical notifications. */
        Freedesktop, /**< Use DBus org.freedesktop.Notifications */
        QSystemTray, /**< Use QSystemTray::showMessage */
        Growl12,        /**< Use the Growl 1.2 notification system (Mac only) */
        Growl13        /**< Use the Growl 1.3 notification system (Mac only) */
    };
    QString programName;
    Mode mode;
    QSystemTrayIcon *trayIcon;
#ifdef USE_DBUS
    QDBusInterface *interface;

    void notifyDBus(Class cls, const QString &title, const QString &text, const QIcon &icon, int millisTimeout);
#endif
    void notifySystray(Class cls, const QString &title, const QString &text, const QIcon &icon, int millisTimeout);
#ifdef Q_OS_MAC
    void notifyGrowl(Class cls, const QString &title, const QString &text, const QIcon &icon);
#endif
};

#endif // NOTIFICATOR_H
