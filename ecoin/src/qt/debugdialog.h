#ifndef DEBUGDIALOG_H
#define DEBUGDIALOG_H

#include <QDialog>
#include <QString>

#include "tail.h"

namespace Ui {
class debugDialog;
}

class debugDialog : public QDialog
{
    Q_OBJECT
    Tail* worker;

public:
    explicit debugDialog(QWidget *parent = 0);
    ~debugDialog();

private slots:

    void on_Close_clicked();

    void on_Pause_clicked();

private:
    Ui::debugDialog *ui;
    void startTail();

public slots:
    void recieveLine(QString line);

};

#endif // DEBUGDIALOG_H
