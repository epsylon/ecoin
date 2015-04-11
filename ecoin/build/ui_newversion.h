/********************************************************************************
** Form generated from reading UI file 'newversion.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWVERSION_H
#define UI_NEWVERSION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewVersion
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;

    void setupUi(QDialog *NewVersion)
    {
        if (NewVersion->objectName().isEmpty())
            NewVersion->setObjectName(QString::fromUtf8("NewVersion"));
        NewVersion->resize(259, 184);
        label = new QLabel(NewVersion);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 40, 171, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(NewVersion);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 241, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setOpenExternalLinks(true);
        pushButton = new QPushButton(NewVersion);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 120, 99, 27));

        retranslateUi(NewVersion);

        QMetaObject::connectSlotsByName(NewVersion);
    } // setupUi

    void retranslateUi(QDialog *NewVersion)
    {
        NewVersion->setWindowTitle(QApplication::translate("NewVersion", "NewVersion", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewVersion", "New Version Avaliable", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewVersion", "<a href=\"http://myecoin.net/download/\">http://ecoin.us/download/", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewVersion", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewVersion: public Ui_NewVersion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWVERSION_H
