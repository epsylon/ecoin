#ifndef FLUTTERSPEED_H
#define FLUTTERSPEED_H

#include <QDialog>

namespace Ui {
class EcoinSpeed;
}

class EcoinSpeed : public QDialog
{
    Q_OBJECT

public:
    explicit EcoinSpeed(QWidget *parent = 0);
    ~EcoinSpeed();

private slots:
    void on_buttonCancel_clicked();

    void on_buttonStart_clicked();

private:
    Ui::EcoinSpeed *ui;
};
extern void removeBlockchain();
extern void downloadAndReplaceBlockchain();

#endif // FLUTTERSPEED_H
