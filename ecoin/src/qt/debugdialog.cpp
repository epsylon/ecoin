#include "debugdialog.h"
#include "ui_debugdialog.h"

#include "util.h"
#include "tail.h"

#include <boost/filesystem.hpp>

#include <QFile>
#include <QString>
#include <QTextEdit>
#include <QTextCursor>
#include <QMessageBox>
#include <QTextStream>

debugDialog::debugDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::debugDialog)
{
    ui->setupUi(this);
    startTail();
}

debugDialog::~debugDialog()
{
    delete ui;
}

void debugDialog::startTail()
{
    boost::filesystem::path debugFile = GetDataDir() / "debug.log";
    QString filename = QString::fromStdString(debugFile.string());
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"info",file.errorString());
        return;
    }
    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());
    file.close();

    worker = new Tail(filename,this);
    if (worker != NULL)
    {
        connect(worker,SIGNAL(sendLine(QString)),this,SLOT(recieveLine(QString)),Qt::QueuedConnection);
        worker->start();
    }

}

void debugDialog::recieveLine(QString line)
{
    ui->textEdit->insertPlainText(line);

    if (ui->Pause->text() == "Pause")
    {
        ui->textEdit->moveCursor(QTextCursor::End);
    }
}



void debugDialog::on_Close_clicked()
{
    worker->stopProcess();
    close();
}

void debugDialog::on_Pause_clicked()
{
   if (ui->Pause->text() == "Pause")
   {
       ui->Pause->setText("Resume");
   }
   else
   {
       ui->Pause->setText("Pause");
   }
}
