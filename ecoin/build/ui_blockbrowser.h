/********************************************************************************
** Form generated from reading UI file 'blockbrowser.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKBROWSER_H
#define UI_BLOCKBROWSER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BlockBrowser
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QWidget *layoutWidgetBE1;
    QHBoxLayout *horizontalLayoutBE;
    QLabel *labelBlockExplorer;
    QSpacerItem *horizontalSpacerBE;
    QWidget *layoutWidgetBE2;
    QGridLayout *gridLayoutBE;
    QSpacerItem *verticalSpacer;
    QPushButton *txButton;
    QLabel *inputLabel;
    QLabel *hashRateBox;
    QLabel *valueLabel;
    QLabel *txLabel;
    QLabel *diffBox;
    QLabel *txID;
    QLabel *inputBox;
    QLabel *valueBox;
    QLabel *diffLabel;
    QSpinBox *heightBox;
    QLabel *heightLabelBE2;
    QLabel *timeBox;
    QPushButton *blockButton;
    QLabel *merkleLabel;
    QLabel *hashLabel;
    QLabel *feesBox;
    QLabel *hashRateLabel;
    QLabel *heightLabelBE1;
    QLabel *feesLabel;
    QLabel *bitsLabel;
    QLabel *bitsBox;
    QLabel *merkleBox;
    QLabel *outputLabel;
    QLabel *outputBox;
    QLabel *nonceLabel;
    QLabel *nonceBox;
    QLabel *timeLabel;
    QLabel *hashBox;
    QLineEdit *txBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *BlockBrowser)
    {
        if (BlockBrowser->objectName().isEmpty())
            BlockBrowser->setObjectName(QString::fromUtf8("BlockBrowser"));
        BlockBrowser->setWindowModality(Qt::NonModal);
        BlockBrowser->setEnabled(true);
        BlockBrowser->resize(850, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(BlockBrowser->sizePolicy().hasHeightForWidth());
        BlockBrowser->setSizePolicy(sizePolicy);
        BlockBrowser->setMinimumSize(QSize(0, 0));
        BlockBrowser->setAcceptDrops(false);
        gridLayout = new QGridLayout(BlockBrowser);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(21, 10, 10, -1);
        widget = new QWidget(BlockBrowser);
        widget->setObjectName(QString::fromUtf8("widget"));
        layoutWidgetBE1 = new QWidget(widget);
        layoutWidgetBE1->setObjectName(QString::fromUtf8("layoutWidgetBE1"));
        layoutWidgetBE1->setGeometry(QRect(0, 0, 822, 27));
        horizontalLayoutBE = new QHBoxLayout(layoutWidgetBE1);
        horizontalLayoutBE->setSpacing(7);
        horizontalLayoutBE->setObjectName(QString::fromUtf8("horizontalLayoutBE"));
        horizontalLayoutBE->setContentsMargins(0, 0, 0, 0);
        labelBlockExplorer = new QLabel(layoutWidgetBE1);
        labelBlockExplorer->setObjectName(QString::fromUtf8("labelBlockExplorer"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelBlockExplorer->sizePolicy().hasHeightForWidth());
        labelBlockExplorer->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelBlockExplorer->setFont(font);
        labelBlockExplorer->setStyleSheet(QString::fromUtf8("font-weight:bold;"));

        horizontalLayoutBE->addWidget(labelBlockExplorer);

        horizontalSpacerBE = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutBE->addItem(horizontalSpacerBE);

        layoutWidgetBE2 = new QWidget(widget);
        layoutWidgetBE2->setObjectName(QString::fromUtf8("layoutWidgetBE2"));
        layoutWidgetBE2->setGeometry(QRect(0, 30, 812, 410));
        gridLayoutBE = new QGridLayout(layoutWidgetBE2);
        gridLayoutBE->setObjectName(QString::fromUtf8("gridLayoutBE"));
        gridLayoutBE->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayoutBE->setHorizontalSpacing(7);
        gridLayoutBE->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutBE->addItem(verticalSpacer, 18, 0, 1, 1);

        txButton = new QPushButton(layoutWidgetBE2);
        txButton->setObjectName(QString::fromUtf8("txButton"));

        gridLayoutBE->addWidget(txButton, 12, 1, 1, 1);

        inputLabel = new QLabel(layoutWidgetBE2);
        inputLabel->setObjectName(QString::fromUtf8("inputLabel"));
        inputLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayoutBE->addWidget(inputLabel, 17, 0, 1, 1);

        hashRateBox = new QLabel(layoutWidgetBE2);
        hashRateBox->setObjectName(QString::fromUtf8("hashRateBox"));
        hashRateBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(hashRateBox, 10, 1, 1, 1);

        valueLabel = new QLabel(layoutWidgetBE2);
        valueLabel->setObjectName(QString::fromUtf8("valueLabel"));

        gridLayoutBE->addWidget(valueLabel, 14, 0, 1, 1);

        txLabel = new QLabel(layoutWidgetBE2);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));

        gridLayoutBE->addWidget(txLabel, 13, 0, 1, 1);

        diffBox = new QLabel(layoutWidgetBE2);
        diffBox->setObjectName(QString::fromUtf8("diffBox"));
        diffBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(diffBox, 9, 1, 1, 1);

        txID = new QLabel(layoutWidgetBE2);
        txID->setObjectName(QString::fromUtf8("txID"));
        txID->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(txID, 13, 1, 1, 1);

        inputBox = new QLabel(layoutWidgetBE2);
        inputBox->setObjectName(QString::fromUtf8("inputBox"));
        inputBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        inputBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(inputBox, 17, 1, 1, 1);

        valueBox = new QLabel(layoutWidgetBE2);
        valueBox->setObjectName(QString::fromUtf8("valueBox"));
        valueBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(valueBox, 14, 1, 1, 1);

        diffLabel = new QLabel(layoutWidgetBE2);
        diffLabel->setObjectName(QString::fromUtf8("diffLabel"));

        gridLayoutBE->addWidget(diffLabel, 9, 0, 1, 1);

        heightBox = new QSpinBox(layoutWidgetBE2);
        heightBox->setObjectName(QString::fromUtf8("heightBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(heightBox->sizePolicy().hasHeightForWidth());
        heightBox->setSizePolicy(sizePolicy2);
        heightBox->setMaximum(99999999);

        gridLayoutBE->addWidget(heightBox, 1, 0, 1, 1);

        heightLabelBE2 = new QLabel(layoutWidgetBE2);
        heightLabelBE2->setObjectName(QString::fromUtf8("heightLabelBE2"));

        gridLayoutBE->addWidget(heightLabelBE2, 3, 0, 1, 1);

        timeBox = new QLabel(layoutWidgetBE2);
        timeBox->setObjectName(QString::fromUtf8("timeBox"));
        timeBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(timeBox, 8, 1, 1, 1);

        blockButton = new QPushButton(layoutWidgetBE2);
        blockButton->setObjectName(QString::fromUtf8("blockButton"));

        gridLayoutBE->addWidget(blockButton, 1, 1, 1, 1);

        merkleLabel = new QLabel(layoutWidgetBE2);
        merkleLabel->setObjectName(QString::fromUtf8("merkleLabel"));

        gridLayoutBE->addWidget(merkleLabel, 5, 0, 1, 1);

        hashLabel = new QLabel(layoutWidgetBE2);
        hashLabel->setObjectName(QString::fromUtf8("hashLabel"));

        gridLayoutBE->addWidget(hashLabel, 4, 0, 1, 1);

        feesBox = new QLabel(layoutWidgetBE2);
        feesBox->setObjectName(QString::fromUtf8("feesBox"));
        feesBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(feesBox, 15, 1, 1, 1);

        hashRateLabel = new QLabel(layoutWidgetBE2);
        hashRateLabel->setObjectName(QString::fromUtf8("hashRateLabel"));

        gridLayoutBE->addWidget(hashRateLabel, 10, 0, 1, 1);

        heightLabelBE1 = new QLabel(layoutWidgetBE2);
        heightLabelBE1->setObjectName(QString::fromUtf8("heightLabelBE1"));
        heightLabelBE1->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(heightLabelBE1, 3, 1, 1, 1);

        feesLabel = new QLabel(layoutWidgetBE2);
        feesLabel->setObjectName(QString::fromUtf8("feesLabel"));

        gridLayoutBE->addWidget(feesLabel, 15, 0, 1, 1);

        bitsLabel = new QLabel(layoutWidgetBE2);
        bitsLabel->setObjectName(QString::fromUtf8("bitsLabel"));

        gridLayoutBE->addWidget(bitsLabel, 7, 0, 1, 1);

        bitsBox = new QLabel(layoutWidgetBE2);
        bitsBox->setObjectName(QString::fromUtf8("bitsBox"));
        bitsBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(bitsBox, 7, 1, 1, 1);

        merkleBox = new QLabel(layoutWidgetBE2);
        merkleBox->setObjectName(QString::fromUtf8("merkleBox"));
        merkleBox->setMinimumSize(QSize(187, 0));
        merkleBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(merkleBox, 5, 1, 1, 1);

        outputLabel = new QLabel(layoutWidgetBE2);
        outputLabel->setObjectName(QString::fromUtf8("outputLabel"));
        outputLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayoutBE->addWidget(outputLabel, 16, 0, 1, 1);

        outputBox = new QLabel(layoutWidgetBE2);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));
        outputBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        outputBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(outputBox, 16, 1, 1, 1);

        nonceLabel = new QLabel(layoutWidgetBE2);
        nonceLabel->setObjectName(QString::fromUtf8("nonceLabel"));

        gridLayoutBE->addWidget(nonceLabel, 6, 0, 1, 1);

        nonceBox = new QLabel(layoutWidgetBE2);
        nonceBox->setObjectName(QString::fromUtf8("nonceBox"));
        nonceBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(nonceBox, 6, 1, 1, 1);

        timeLabel = new QLabel(layoutWidgetBE2);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));

        gridLayoutBE->addWidget(timeLabel, 8, 0, 1, 1);

        hashBox = new QLabel(layoutWidgetBE2);
        hashBox->setObjectName(QString::fromUtf8("hashBox"));
        hashBox->setEnabled(true);
        sizePolicy.setHeightForWidth(hashBox->sizePolicy().hasHeightForWidth());
        hashBox->setSizePolicy(sizePolicy);
        hashBox->setMinimumSize(QSize(0, 0));
        hashBox->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        gridLayoutBE->addWidget(hashBox, 4, 1, 1, 1);

        txBox = new QLineEdit(layoutWidgetBE2);
        txBox->setObjectName(QString::fromUtf8("txBox"));
        sizePolicy2.setHeightForWidth(txBox->sizePolicy().hasHeightForWidth());
        txBox->setSizePolicy(sizePolicy2);

        gridLayoutBE->addWidget(txBox, 12, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayoutBE->addItem(verticalSpacer_2, 11, 0, 1, 1);


        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(BlockBrowser);

        QMetaObject::connectSlotsByName(BlockBrowser);
    } // setupUi

    void retranslateUi(QDialog *BlockBrowser)
    {
        BlockBrowser->setWindowTitle(QApplication::translate("BlockBrowser", "Block Browser", 0, QApplication::UnicodeUTF8));
        labelBlockExplorer->setText(QApplication::translate("BlockBrowser", "Block Browser", 0, QApplication::UnicodeUTF8));
        txButton->setText(QApplication::translate("BlockBrowser", "Decode Transaction", 0, QApplication::UnicodeUTF8));
        inputLabel->setText(QApplication::translate("BlockBrowser", "Inputs:", 0, QApplication::UnicodeUTF8));
        hashRateBox->setText(QApplication::translate("BlockBrowser", "0000 MH/s", 0, QApplication::UnicodeUTF8));
        valueLabel->setText(QApplication::translate("BlockBrowser", "Value out:", 0, QApplication::UnicodeUTF8));
        txLabel->setText(QApplication::translate("BlockBrowser", "Transaction ID:", 0, QApplication::UnicodeUTF8));
        diffBox->setText(QApplication::translate("BlockBrowser", "0.00", 0, QApplication::UnicodeUTF8));
        txID->setText(QApplication::translate("BlockBrowser", "000", 0, QApplication::UnicodeUTF8));
        inputBox->setText(QString());
        valueBox->setText(QString());
        diffLabel->setText(QApplication::translate("BlockBrowser", "Block Difficulty:", 0, QApplication::UnicodeUTF8));
        heightLabelBE2->setText(QApplication::translate("BlockBrowser", "Block Height:", 0, QApplication::UnicodeUTF8));
        timeBox->setText(QApplication::translate("BlockBrowser", "0", 0, QApplication::UnicodeUTF8));
        blockButton->setText(QApplication::translate("BlockBrowser", "Jump to Block", 0, QApplication::UnicodeUTF8));
        merkleLabel->setText(QApplication::translate("BlockBrowser", "Block Merkle:", 0, QApplication::UnicodeUTF8));
        hashLabel->setText(QApplication::translate("BlockBrowser", "Block Hash:", 0, QApplication::UnicodeUTF8));
        feesBox->setText(QString());
        hashRateLabel->setText(QApplication::translate("BlockBrowser", "Block Hashrate:", 0, QApplication::UnicodeUTF8));
        heightLabelBE1->setText(QApplication::translate("BlockBrowser", "0", 0, QApplication::UnicodeUTF8));
        feesLabel->setText(QApplication::translate("BlockBrowser", "Fees:", 0, QApplication::UnicodeUTF8));
        bitsLabel->setText(QApplication::translate("BlockBrowser", "Block nBits:", 0, QApplication::UnicodeUTF8));
        bitsBox->setText(QApplication::translate("BlockBrowser", "0", 0, QApplication::UnicodeUTF8));
        merkleBox->setText(QApplication::translate("BlockBrowser", "0x0", 0, QApplication::UnicodeUTF8));
        outputLabel->setText(QApplication::translate("BlockBrowser", "Outputs:", 0, QApplication::UnicodeUTF8));
        outputBox->setText(QString());
        nonceLabel->setText(QApplication::translate("BlockBrowser", "Block nNonce:", 0, QApplication::UnicodeUTF8));
        nonceBox->setText(QApplication::translate("BlockBrowser", "0", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QApplication::translate("BlockBrowser", "Block Timestamp:", 0, QApplication::UnicodeUTF8));
        hashBox->setText(QApplication::translate("BlockBrowser", "0x0", 0, QApplication::UnicodeUTF8));
        txBox->setInputMask(QString());
        txBox->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class BlockBrowser: public Ui_BlockBrowser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKBROWSER_H
