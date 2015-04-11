/********************************************************************************
** Form generated from reading UI file 'savingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVINGSDIALOG_H
#define UI_SAVINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AutoSavingsDialog
{
public:
    QLineEdit *savingsPercentEdit;
    QLineEdit *savingsAddressEdit;
    QLabel *label_2;
    QLineEdit *savingsMinEdit;
    QLineEdit *savingsMaxEdit;
    QLabel *message;
    QPushButton *enableButton;
    QPushButton *disableButton;
    QPushButton *addressBookButton;
    QLineEdit *savingsChangeAddressEdit;
    QPushButton *changeAddressBookButton;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_6;
    QLineEdit *freeAddressEdit;
    QPushButton *freeAddressBookButton;
    QLabel *freelabel;
    QPushButton *freeRequestButton;
    QFrame *line;
    QLabel *freeMessage;
    QLabel *label_7;
    QPushButton *pushButton_copy;
    QPushButton *freeDisableButton;
    QPushButton *freeReferButton;

    void setupUi(QWidget *AutoSavingsDialog)
    {
        if (AutoSavingsDialog->objectName().isEmpty())
            AutoSavingsDialog->setObjectName(QString::fromUtf8("AutoSavingsDialog"));
        AutoSavingsDialog->setWindowModality(Qt::NonModal);
        AutoSavingsDialog->resize(850, 400);
        savingsPercentEdit = new QLineEdit(AutoSavingsDialog);
        savingsPercentEdit->setObjectName(QString::fromUtf8("savingsPercentEdit"));
        savingsPercentEdit->setGeometry(QRect(20, 130, 131, 21));
        savingsAddressEdit = new QLineEdit(AutoSavingsDialog);
        savingsAddressEdit->setObjectName(QString::fromUtf8("savingsAddressEdit"));
        savingsAddressEdit->setGeometry(QRect(20, 180, 301, 21));
        label_2 = new QLabel(AutoSavingsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 20, 611, 41));
        label_2->setLineWidth(1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        savingsMinEdit = new QLineEdit(AutoSavingsDialog);
        savingsMinEdit->setObjectName(QString::fromUtf8("savingsMinEdit"));
        savingsMinEdit->setGeometry(QRect(160, 130, 131, 21));
        savingsMaxEdit = new QLineEdit(AutoSavingsDialog);
        savingsMaxEdit->setObjectName(QString::fromUtf8("savingsMaxEdit"));
        savingsMaxEdit->setGeometry(QRect(300, 130, 131, 21));
        message = new QLabel(AutoSavingsDialog);
        message->setObjectName(QString::fromUtf8("message"));
        message->setGeometry(QRect(20, 210, 611, 21));
        enableButton = new QPushButton(AutoSavingsDialog);
        enableButton->setObjectName(QString::fromUtf8("enableButton"));
        enableButton->setGeometry(QRect(350, 180, 75, 21));
        disableButton = new QPushButton(AutoSavingsDialog);
        disableButton->setObjectName(QString::fromUtf8("disableButton"));
        disableButton->setGeometry(QRect(430, 180, 75, 21));
        addressBookButton = new QPushButton(AutoSavingsDialog);
        addressBookButton->setObjectName(QString::fromUtf8("addressBookButton"));
        addressBookButton->setGeometry(QRect(320, 180, 28, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/address-book"), QSize(), QIcon::Normal, QIcon::Off);
        addressBookButton->setIcon(icon);
        addressBookButton->setAutoDefault(false);
        savingsChangeAddressEdit = new QLineEdit(AutoSavingsDialog);
        savingsChangeAddressEdit->setObjectName(QString::fromUtf8("savingsChangeAddressEdit"));
        savingsChangeAddressEdit->setGeometry(QRect(20, 260, 301, 21));
        changeAddressBookButton = new QPushButton(AutoSavingsDialog);
        changeAddressBookButton->setObjectName(QString::fromUtf8("changeAddressBookButton"));
        changeAddressBookButton->setGeometry(QRect(320, 260, 28, 21));
        changeAddressBookButton->setIcon(icon);
        changeAddressBookButton->setAutoDefault(false);
        label = new QLabel(AutoSavingsDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 110, 121, 16));
        label_3 = new QLabel(AutoSavingsDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 110, 101, 16));
        label_4 = new QLabel(AutoSavingsDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(320, 110, 101, 16));
        label_6 = new QLabel(AutoSavingsDialog);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 160, 121, 16));
        freeAddressEdit = new QLineEdit(AutoSavingsDialog);
        freeAddressEdit->setObjectName(QString::fromUtf8("freeAddressEdit"));
        freeAddressEdit->setGeometry(QRect(20, 330, 301, 21));
        freeAddressBookButton = new QPushButton(AutoSavingsDialog);
        freeAddressBookButton->setObjectName(QString::fromUtf8("freeAddressBookButton"));
        freeAddressBookButton->setGeometry(QRect(320, 330, 28, 21));
        freeAddressBookButton->setIcon(icon);
        freeAddressBookButton->setAutoDefault(false);
        freelabel = new QLabel(AutoSavingsDialog);
        freelabel->setObjectName(QString::fromUtf8("freelabel"));
        freelabel->setGeometry(QRect(20, 310, 331, 16));
        freeRequestButton = new QPushButton(AutoSavingsDialog);
        freeRequestButton->setObjectName(QString::fromUtf8("freeRequestButton"));
        freeRequestButton->setGeometry(QRect(350, 330, 75, 21));
        line = new QFrame(AutoSavingsDialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 290, 611, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        freeMessage = new QLabel(AutoSavingsDialog);
        freeMessage->setObjectName(QString::fromUtf8("freeMessage"));
        freeMessage->setGeometry(QRect(20, 360, 611, 21));
        label_7 = new QLabel(AutoSavingsDialog);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(110, 70, 481, 21));
        pushButton_copy = new QPushButton(AutoSavingsDialog);
        pushButton_copy->setObjectName(QString::fromUtf8("pushButton_copy"));
        pushButton_copy->setGeometry(QRect(20, 70, 85, 21));
        freeDisableButton = new QPushButton(AutoSavingsDialog);
        freeDisableButton->setObjectName(QString::fromUtf8("freeDisableButton"));
        freeDisableButton->setGeometry(QRect(430, 330, 75, 21));
        freeReferButton = new QPushButton(AutoSavingsDialog);
        freeReferButton->setObjectName(QString::fromUtf8("freeReferButton"));
        freeReferButton->setGeometry(QRect(510, 330, 75, 21));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/add"), QSize(), QIcon::Normal, QIcon::Off);
        freeReferButton->setIcon(icon1);

        retranslateUi(AutoSavingsDialog);

        QMetaObject::connectSlotsByName(AutoSavingsDialog);
    } // setupUi

    void retranslateUi(QWidget *AutoSavingsDialog)
    {
        AutoSavingsDialog->setWindowTitle(QApplication::translate("AutoSavingsDialog", "EcoinShare", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savingsPercentEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Enter the percent to share (whole numbers)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savingsPercentEdit->setText(QString());
        savingsPercentEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "Enter % to share", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savingsAddressEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Enter Ecoin address", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savingsAddressEdit->setText(QString());
        savingsAddressEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "EgAiyRYKKsQEDsbkYuML9d48WUm5DMTdAw", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AutoSavingsDialog", "EcoinShare allows you to automatically send up to 50% of your stake to another Ecoin address after it matures.", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savingsMinEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Do not send less than this (whole numbers)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savingsMinEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "Enter Min Amount", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savingsMaxEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Do not send more than this (whole numbers)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savingsMaxEdit->setText(QString());
        savingsMaxEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "Enter Max Amount", 0, QApplication::UnicodeUTF8));
        message->setText(QString());
#ifndef QT_NO_STATUSTIP
        enableButton->setStatusTip(QApplication::translate("AutoSavingsDialog", "Check and turn on EcoinShare", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        enableButton->setText(QApplication::translate("AutoSavingsDialog", "Enable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        disableButton->setStatusTip(QApplication::translate("AutoSavingsDialog", "Turn off EcoinShare", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        disableButton->setText(QApplication::translate("AutoSavingsDialog", "Disable", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addressBookButton->setToolTip(QApplication::translate("AutoSavingsDialog", "Choose an address from the address book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addressBookButton->setText(QString());
        addressBookButton->setShortcut(QApplication::translate("AutoSavingsDialog", "Alt+A", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        savingsChangeAddressEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Change address must be owned by you", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        savingsChangeAddressEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "Enter Change Address (optional)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        changeAddressBookButton->setToolTip(QApplication::translate("AutoSavingsDialog", "Choose an address from the address book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        changeAddressBookButton->setText(QString());
        changeAddressBookButton->setShortcut(QApplication::translate("AutoSavingsDialog", "Alt+A", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AutoSavingsDialog", "Donation Percent", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AutoSavingsDialog", "Min(optional)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("AutoSavingsDialog", "Max(optional)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("AutoSavingsDialog", "Donation Address", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        freeAddressEdit->setToolTip(QApplication::translate("AutoSavingsDialog", "Enter Ecoin address", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        freeAddressEdit->setText(QString());
        freeAddressEdit->setPlaceholderText(QApplication::translate("AutoSavingsDialog", "EgAiyRYKKsQEDsbkYuML9d48WUm5DMTdAw", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        freeAddressBookButton->setToolTip(QApplication::translate("AutoSavingsDialog", "Choose an address from the address book", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        freeAddressBookButton->setText(QString());
        freeAddressBookButton->setShortcut(QApplication::translate("AutoSavingsDialog", "Alt+A", 0, QApplication::UnicodeUTF8));
        freelabel->setText(QApplication::translate("AutoSavingsDialog", "Free Ecoins for running the app each day!", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        freeRequestButton->setStatusTip(QApplication::translate("AutoSavingsDialog", "Get Free Ecoins", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        freeRequestButton->setText(QApplication::translate("AutoSavingsDialog", "Enable", 0, QApplication::UnicodeUTF8));
        freeMessage->setText(QString());
        label_7->setText(QApplication::translate("AutoSavingsDialog", "EgAiyRYKKsQEDsbkYuML9d48WUm5DMTdAw - Ecoin Bounty Fund", 0, QApplication::UnicodeUTF8));
        pushButton_copy->setText(QApplication::translate("AutoSavingsDialog", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        freeDisableButton->setStatusTip(QApplication::translate("AutoSavingsDialog", "Get Free Ecoins", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        freeDisableButton->setText(QApplication::translate("AutoSavingsDialog", "Disable", 0, QApplication::UnicodeUTF8));
        freeReferButton->setText(QApplication::translate("AutoSavingsDialog", "Friend", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AutoSavingsDialog: public Ui_AutoSavingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVINGSDIALOG_H
