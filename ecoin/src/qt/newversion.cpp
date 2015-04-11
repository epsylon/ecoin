#include "newversion.h"
#include "ui_newversion.h"

NewVersion::NewVersion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewVersion)
{
    ui->setupUi(this);
}

NewVersion::~NewVersion()
{
    delete ui;
}

void NewVersion::on_pushButton_clicked()
{
    close();
}
