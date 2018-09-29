#include "cashdialog.h"
#include "ui_cashdialog.h"


CashDialog::CashDialog(int total, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CashDialog)
{
    ui->setupUi(this);
    ui->spinBoxTotal->setValue(total);
}


CashDialog::~CashDialog()
{
    delete ui;
}

void CashDialog::on_pushButtonOk_clicked()
{


    this->close();
}

void CashDialog::on_spinBoxEfectivo_valueChanged(int arg1)
{

    total=ui->spinBoxTotal->value();
    efectivo=ui->spinBoxEfectivo->value();
    if(total<efectivo && efectivo !=0){
        cambio=efectivo-total;
        ui->spinBoxCambio->setValue(cambio);
    }
}
