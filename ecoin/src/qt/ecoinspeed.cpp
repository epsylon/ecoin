#include "ecoinspeed.h"
#include "ui_ecoinspeed.h"

#include "init.h"

#include "optionsmodel.h"

EcoinSpeed::EcoinSpeed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EcoinSpeed)
{
    ui->setupUi(this);
}

EcoinSpeed::~EcoinSpeed()
{
    delete ui;
}

void EcoinSpeed::on_buttonCancel_clicked()
{
    close();
}

void EcoinSpeed::on_buttonStart_clicked()
{

	OptionsModel om;
	om.setDownloadChain();
	uiInterface.QueueShutdown();

}

