/********************************************************************************
** Form generated from reading UI file 'debugdialog.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGDIALOG_H
#define UI_DEBUGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_debugDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Pause;
    QPushButton *Close;

    void setupUi(QDialog *debugDialog)
    {
        if (debugDialog->objectName().isEmpty())
            debugDialog->setObjectName(QString::fromUtf8("debugDialog"));
        debugDialog->resize(945, 367);
        verticalLayoutWidget = new QWidget(debugDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(7, 9, 931, 351));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QFont font;
        font.setPointSize(9);
        textEdit->setFont(font);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Pause = new QPushButton(verticalLayoutWidget);
        Pause->setObjectName(QString::fromUtf8("Pause"));

        horizontalLayout->addWidget(Pause);

        Close = new QPushButton(verticalLayoutWidget);
        Close->setObjectName(QString::fromUtf8("Close"));

        horizontalLayout->addWidget(Close);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(debugDialog);

        QMetaObject::connectSlotsByName(debugDialog);
    } // setupUi

    void retranslateUi(QDialog *debugDialog)
    {
        debugDialog->setWindowTitle(QApplication::translate("debugDialog", "Debug Window", 0, QApplication::UnicodeUTF8));
        Pause->setText(QApplication::translate("debugDialog", "Pause", 0, QApplication::UnicodeUTF8));
        Close->setText(QApplication::translate("debugDialog", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class debugDialog: public Ui_debugDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGDIALOG_H
