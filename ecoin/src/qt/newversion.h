#ifndef NEWVERSION_H
#define NEWVERSION_H

#include <QDialog>

namespace Ui {
class NewVersion;
}

class NewVersion : public QDialog
{
    Q_OBJECT

public:
    explicit NewVersion(QWidget *parent = 0);
    ~NewVersion();

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewVersion *ui;
};

#endif // NEWVERSION_H
