/********************************************************************************
** Form generated from reading UI file 'ecoinspeed.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECOINSPEED_H
#define UI_ECOINSPEED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EcoinSpeed
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonStart;

    void setupUi(QDialog *EcoinSpeed)
    {
        if (EcoinSpeed->objectName().isEmpty())
            EcoinSpeed->setObjectName(QString::fromUtf8("EcoinSpeed"));
        EcoinSpeed->resize(374, 295);
        label = new QLabel(EcoinSpeed);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(16, 16, 351, 171));
        label->setWordWrap(true);
        horizontalLayoutWidget = new QWidget(EcoinSpeed);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 250, 221, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        buttonCancel = new QPushButton(horizontalLayoutWidget);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        horizontalLayout->addWidget(buttonCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonStart = new QPushButton(horizontalLayoutWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        horizontalLayout->addWidget(buttonStart);


        retranslateUi(EcoinSpeed);

        QMetaObject::connectSlotsByName(EcoinSpeed);
    } // setupUi

    void retranslateUi(QDialog *EcoinSpeed)
    {
        EcoinSpeed->setWindowTitle(QApplication::translate("EcoinSpeed", "EcoinSpeed", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("EcoinSpeed", "Clicking on Start will delete the current blockchain files and exit the program, upon next run of program it will attempt to download the bulk of the blockchain from the Internet and finish with a rescan of transactions in wallet along with a catchup of the chain via p2p. This process should not be canceled, if it is it may simply start from scratch syncing p2p or stop the program from starting properly.", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("EcoinSpeed", "Cancel", 0, QApplication::UnicodeUTF8));
        buttonStart->setText(QApplication::translate("EcoinSpeed", "Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EcoinSpeed: public Ui_EcoinSpeed {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECOINSPEED_H
