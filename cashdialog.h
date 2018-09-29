#ifndef CASHDIALOG_H
#define CASHDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class CashDialog;
}

class CashDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CashDialog(int total,QWidget *parent = 0);

    ~CashDialog();

private slots:
    void on_pushButtonOk_clicked();

    void on_spinBoxEfectivo_valueChanged(int arg1);

private:
    Ui::CashDialog *ui;
    int efectivo;
    int cambio;
    int total;

};

#endif // CASHDIALOG_H
