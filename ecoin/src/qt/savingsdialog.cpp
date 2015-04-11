#include "savingsdialog.h"
#include "ui_savingsdialog.h"

#include "walletmodel.h"
#include "base58.h"
#include "addressbookpage.h"
#include "init.h"
#include "smessage.h"

#include <QLineEdit>
#include <QDateTime>
#include <QMessageBox>
#include <QInputDialog>

AutoSavingsDialog::AutoSavingsDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AutoSavingsDialog),
    model(0)
{
    ui->setupUi(this);

    ui->label_2->setFocus();

    // turn off custom change address in ecoinshare --ofeefee 
    ui->savingsChangeAddressEdit->setVisible(false);
    ui->changeAddressBookButton->setVisible(false);

    // setup nam so we can do some URL stuff
    namTimer = new QNetworkAccessManager(this);
    connect(namTimer,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyTimerFinished(QNetworkReply*)));

    nam = new QNetworkAccessManager(this);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));

    // setup timer so we can kickoff events
    freeTimer = new QTimer(this);
    connect(freeTimer, SIGNAL(timeout()), this, SLOT(freeDoHttpPost()));
}

AutoSavingsDialog::~AutoSavingsDialog()
{
    delete ui;
}

void AutoSavingsDialog::setModel(WalletModel *model)
{
    this->model = model;


    CBitcoinAddress strAddress;
    CBitcoinAddress strChangeAddress;
    int nPer;
    int64 nMin;
    int64 nMax;

    model->getAutoSavings(nPer, strAddress, strChangeAddress, nMin, nMax);

    if (strAddress.IsValid() && nPer > 0 )
    {
        ui->savingsAddressEdit->setText(strAddress.ToString().c_str());
        ui->savingsPercentEdit->setText(QString::number(nPer));
        if (strChangeAddress.IsValid())
            ui->savingsChangeAddressEdit->setText(strChangeAddress.ToString().c_str());
        if (nMin > 0 && nMin != MIN_TX_FEE)
            ui->savingsMinEdit->setText(QString::number(nMin/COIN));
        if (nMax > 0 && nMax != MAX_MONEY)
            ui->savingsMaxEdit->setText(QString::number(nMax/COIN));
        ui->message->setStyleSheet("QLabel { color: green; }");
        ui->message->setText(tr("You are now sending to: ") + strAddress.ToString().c_str() + tr("."));
    }
}

void AutoSavingsDialog::setAddress(const QString &address)
{
    setAddress(address, ui->savingsAddressEdit);
}

void AutoSavingsDialog::setAddress(const QString &address, QLineEdit *addrEdit)
{
    addrEdit->setText(address);
    addrEdit->setFocus();
}

void AutoSavingsDialog::on_addressBookButton_clicked()
{
    if (model && model->getAddressTableModel())
    {
        AddressBookPage dlg(AddressBookPage::ForSending, AddressBookPage::SendingTab, this);
        dlg.setModel(model->getAddressTableModel());
        if (dlg.exec())
            setAddress(dlg.getReturnValue(), ui->savingsAddressEdit);
    }
}

void AutoSavingsDialog::on_freeAddressBookButton_clicked()
{
    if (model && model->getAddressTableModel())
    {
        AddressBookPage dlg(AddressBookPage::ForSending, AddressBookPage::ReceivingTab, this);
        dlg.setModel(model->getAddressTableModel());
        if (dlg.exec())
            setAddress(dlg.getReturnValue(), ui->freeAddressEdit);
    }
}

void AutoSavingsDialog::on_freeRequestButton_clicked()
{
    CBitcoinAddress address = ui->freeAddressEdit->text().toStdString();
    if (!address.IsValid())
    {
        ui->freeMessage->setStyleSheet("QLabel { color: red; }");
        ui->freeMessage->setText(tr("Please enter a valid Ecoin address."));
        ui->freeAddressEdit->clear();
        ui->freeAddressEdit->setFocus();
        return;
    }
    if (!model->isMine(address))
    {
        ui->freeMessage->setStyleSheet("QLabel { color: red; }");
        ui->freeMessage->setText(tr("Ecoin address is not owned."));
        ui->freeAddressEdit->clear();
        ui->freeAddressEdit->setFocus();
        return;
    }

    // kick off post request in 8 hours
    freeTimer->start(8*60*60*1000);
    QDateTime timePost = QDateTime::currentDateTime().addMSecs(8*60*60*1000);

    // update message so user knows they are good to go
    ui->freeMessage->setStyleSheet("QLabel { color: green; }");
    ui->freeMessage->setText(tr("Leave your application running! Next request at ") + timePost.toString() + tr("."));
}

void AutoSavingsDialog::on_freeDisableButton_clicked()
{
    ui->freeAddressEdit->clear();
    ui->freeMessage->clear();
    freeTimer->stop();
}

void AutoSavingsDialog::on_freeReferButton_clicked()
{
    CBitcoinAddress address = ui->freeAddressEdit->text().toStdString();
    if (!address.IsValid() || (!model->isMine(address)))
    {
        ui->freeMessage->setStyleSheet("QLabel { color: red; }");
        ui->freeMessage->setText(tr("You must enable before setting a referral."));
        return;
    }
    bool ok;
    QString userAddress = ui->freeAddressEdit->text();
    QString referAddress = QInputDialog::getText(this, tr("Enter Referral Address"),
                                         "", QLineEdit::Normal, "", &ok);
    if (ok && !referAddress.isEmpty())
    {
        address = referAddress.toStdString();
        if (!address.IsValid())
        {
            QMessageBox::warning(this, tr("Invalid Address"), tr("The address entered is not a valid Ecoin address."));
            return;
        }
        if (model->isMine(address))
        {
            QMessageBox::warning(this, tr("Invalid Address"), tr("You cannot use you own addresses as a referral."));
            return;
        }
        freeDoReferHttpPost(userAddress, referAddress);
    }
}

void AutoSavingsDialog::freeDoReferHttpPost(const QString &userAddress, const QString &referAddress)
{
    // set URL
    QString url = "http://myecoin.net/index.php";

    // add ecoin address
    QUrl params;
    params.addQueryItem("uAddress", userAddress);
    params.addQueryItem("rAddress", referAddress);

    // send post
    nam->post(QNetworkRequest(QUrl(url)), params.encodedQuery());
}

void AutoSavingsDialog::freeDoHttpPost()
{
    CBitcoinAddress address = ui->freeAddressEdit->text().toStdString();
    if (!address.IsValid() || (!model->isMine(address)))
    {
        ui->freeAddressEdit->clear();
        ui->freeMessage->clear();
        freeTimer->stop();
        ui->freeMessage->setStyleSheet("QLabel { color: red; }");
        ui->freeMessage->setText(tr("Address is not valid or not owned. Please update!"));
        return;
    }

    std::string userAddress = address.ToString();
    std::string userPublicKey;

    // set URL
    QString url = "http://myecoin.net/index.php";

    // add ecoin address 
    QUrl params;
    params.addQueryItem("userAddress", QString::fromStdString(userAddress));

    // add ecoin address pubkey
    if (SecureMsgGetLocalPublicKey(userAddress, userPublicKey) == 0)
        params.addQueryItem("userPublicKey", QString::fromStdString(userPublicKey));

    // send post
    namTimer->post(QNetworkRequest(QUrl(url)), params.encodedQuery());
}

void AutoSavingsDialog::replyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QMessageBox::information(this, tr("Success"), tr("The data was sent successfully."));
    }
    else
    {
        QMessageBox::critical(this, tr("Server Error"), tr("There was a server error, please try again later."));
    }
}

void AutoSavingsDialog::replyTimerFinished(QNetworkReply* reply)
{
    // error handling on reply
    if (reply->error() == QNetworkReply::NoError)
    {
        QString response = reply->readAll();
        QString match = "wait 24 hours";
        QString maintenance = "maintenance mode";
        if (response.contains(match))
        {
            //already requested, try again in 4 hours
            freeTimer->start(4*60*60*1000);
            ui->freeMessage->setStyleSheet("QLabel { color: red; }");
            ui->freeMessage->setText(tr("Request was too early. Retrying in 4 hours."));
        }
        else if (response.contains(maintenance))
        {
            //system in maintenance mode, retry 1 hour
            freeTimer->start(1*60*60*1000);
            ui->freeMessage->setStyleSheet("QLabel { color: red; }");
            ui->freeMessage->setText(tr("System is in maintenance mode. Retrying in 1 hour."));
        }
        else
        {
            // do another in 24.1 hours
            freeTimer->start(24.1*60*60*1000);
            QDateTime timePost = QDateTime::currentDateTime().addMSecs(24.1*60*60*1000);
            ui->freeMessage->setStyleSheet("QLabel { color: green; }");
            ui->freeMessage->setText(tr("Request was good. Next request at ") + timePost.toString() + tr("."));
        }
    }
    else
    {
        // retry again in an hour
        freeTimer->start(1*60*60*1000);
        ui->freeMessage->setStyleSheet("QLabel { color: red; }");
        ui->freeMessage->setText(tr("Request had a problem. Retrying in 1 hour."));
    }
}

void AutoSavingsDialog::on_changeAddressBookButton_clicked()
{
    if (model && model->getAddressTableModel())
    {
        AddressBookPage dlg(AddressBookPage::ForSending, AddressBookPage::ReceivingTab, this);
        dlg.setModel(model->getAddressTableModel());
        if (dlg.exec())
            setAddress(dlg.getReturnValue(), ui->savingsChangeAddressEdit);
    }
}

void AutoSavingsDialog::on_enableButton_clicked()
{
    if(model->getEncryptionStatus() == WalletModel::Locked)
    {
        ui->message->setStyleSheet("QLabel { color: black; }");
        ui->message->setText(tr("Please unlock wallet before starting auto savings."));
        return;
    }

    bool fValidConversion = false;
    int64 nMinAmount = MIN_TXOUT_AMOUNT;
    int64 nMaxAmount = MAX_MONEY;
    CBitcoinAddress changeAddress = "";

    CBitcoinAddress address = ui->savingsAddressEdit->text().toStdString();
    if (!address.IsValid())
    {
        ui->message->setStyleSheet("QLabel { color: red; }");
        ui->message->setText(tr("The entered address: ") + ui->savingsAddressEdit->text() + tr(" is invalid."));
        ui->savingsAddressEdit->setFocus();
        return;
    }

    int nSavingsPercent = ui->savingsPercentEdit->text().toInt(&fValidConversion, 10);
    if (!fValidConversion || nSavingsPercent > 50 || nSavingsPercent <= 0)
    {
        ui->message->setStyleSheet("QLabel { color: red; }");
        ui->message->setText(tr("Please Enter 1 - 50 for percent."));
        ui->savingsPercentEdit->setFocus();
        return;
    }

    if (!ui->savingsMinEdit->text().isEmpty())
    {
        nMinAmount = ui->savingsMinEdit->text().toDouble(&fValidConversion) * COIN;
        if(!fValidConversion || nMinAmount <= MIN_TXOUT_AMOUNT || nMinAmount >= MAX_MONEY  )
        {
            ui->message->setStyleSheet("QLabel { color: red; }");
            ui->message->setText(tr("Min Amount out of Range, please re-enter."));
            ui->savingsMinEdit->setFocus();
            return;
        }
    }

    if (!ui->savingsMaxEdit->text().isEmpty())
    {
        nMaxAmount = ui->savingsMaxEdit->text().toDouble(&fValidConversion) * COIN;
        if(!fValidConversion || nMaxAmount <= MIN_TXOUT_AMOUNT || nMaxAmount >= MAX_MONEY  )
        {
            ui->message->setStyleSheet("QLabel { color: red; }");
            ui->message->setText(tr("Max Amount out of Range, please re-enter."));
            ui->savingsMaxEdit->setFocus();
            return;
        }
    }

    if (nMinAmount >= nMaxAmount)
    {
        ui->message->setStyleSheet("QLabel { color: red; }");
        ui->message->setText(tr("Min Amount > Max Amount, please re-enter."));
        ui->savingsMinEdit->setFocus();
        return;
    }

    if (!ui->savingsChangeAddressEdit->text().isEmpty())
    {
        changeAddress = ui->savingsChangeAddressEdit->text().toStdString();
        if (!changeAddress.IsValid())
        {
            ui->message->setStyleSheet("QLabel { color: red; }");
            ui->message->setText(tr("The entered change address:\n") + ui->savingsChangeAddressEdit->text() + tr(" is invalid.\nPlease check the address and try again."));
            ui->savingsChangeAddressEdit->setFocus();
            return;
        }
        else if (!model->isMine(changeAddress))
        {
            ui->message->setStyleSheet("QLabel { color: red; }");
            ui->message->setText(tr("The entered change address:\n") + ui->savingsChangeAddressEdit->text() + tr(" is not owned.\nPlease check the address and try again."));
            ui->savingsChangeAddressEdit->setFocus();
            return;
        }
    }

    model->setAutoSavings(true, nSavingsPercent, address, changeAddress, nMinAmount, nMaxAmount);
    ui->message->setStyleSheet("QLabel { color: green; }");
    ui->message->setText(tr("You are now sending to: ") + QString(address.ToString().c_str()) + tr("."));
    return;
}

void AutoSavingsDialog::on_disableButton_clicked()
{
    int nSavingsPercent = 0;
    CBitcoinAddress address = "";
    CBitcoinAddress changeAddress = "";
    int64 nMinAmount = MIN_TXOUT_AMOUNT;
    int64 nMaxAmount = MAX_MONEY;

    model->setAutoSavings(false, nSavingsPercent, address, changeAddress, nMinAmount, nMaxAmount);
    ui->savingsAddressEdit->clear();
    ui->savingsMaxEdit->clear();
    ui->savingsMinEdit->clear();
    ui->savingsPercentEdit->clear();
    ui->message->setStyleSheet("QLabel { color: black; }");
    ui->message->setText(tr("EcoinShare is now off"));
    return;
}

void AutoSavingsDialog::on_pushButton_copy_clicked()
{
     ui->savingsAddressEdit->setText("EgAiyRYKKsQEDsbkYuML9d48WUm5DMTdAw");
}
