#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "product.h"

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();
Product addProduct();
int response();
private slots:





void on_addPushButton_clicked();

void on_pushButtonBack_clicked();

private:
    Ui::AddDialog *ui;
    int res;

};

#endif // ADDDIALOG_H
