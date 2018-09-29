#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

}

AddDialog::~AddDialog()
{
    delete ui;
}


//se setea la clase Product y se retorna un objeto de su tipo
Product AddDialog::addProduct()
{
   Product p;
   QString product;
    int value;
    product=ui->productNamelineEdit->text();
    value=ui->valueSpinBox->value();
    p.setNameProduct(product);
    p.setValueProduct(value);

    return p;

}



int AddDialog::response()
{
    return res;

}





void AddDialog::on_addPushButton_clicked()
{
    res=1;
    this->close();
}

void AddDialog::on_pushButtonBack_clicked()
{
    res=0;
    this->close();
}
