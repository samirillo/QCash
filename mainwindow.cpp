#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adddialog.h"
#include "cashdialog.h"

int MainWindow::total=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0,300);
    ui->tableWidget->setColumnWidth(1,100);
    ui->tableWidget->setColumnWidth(2,50);

    ui->tableWidget->setFrameStyle(QFrame::Sunken);

}

MainWindow::~MainWindow()
{
    delete ui;
}


/*llama a un adialog adddialog crea un objeto de tipo product el cual es
insertado como una fila en la tabla*/
void MainWindow::on_addPushButton_clicked()
{
    int value;
    int fila;
    QString name;
    AddDialog ad(this);
    ad.setModal(true);
    ad.exec();
    int i=ad.response();

    if(i>0){
        Product p=ad.addProduct();
        name=p.name();
        value=p.value();
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        fila=ui->tableWidget->rowCount() -1;
        ui->tableWidget->setItem(fila,PRODUCTO, new QTableWidgetItem(name));
        ui->tableWidget->setItem(fila, VALOR, new QTableWidgetItem(
                                     QString::number(value)));
        createButtonCancel(fila);
        MainWindow::total=total+value;
        ui->CantProductSpinBox->setValue(ui->tableWidget->rowCount());
        ui->totalSpinBox->setValue(total);
    }

}

//llama a una ventana dialog para hacer el recaudo, limpiano toda la tabla
void MainWindow::on_okPushButton_clicked()
{
    int filas=0;
    CashDialog cd(total);
    cd.exec();
    filas=ui->tableWidget->rowCount();
    while(filas>0){
        ui->tableWidget->removeRow(filas-1);
        filas--;
    }

    ui->totalSpinBox->setValue(0);
    ui->CantProductSpinBox->setValue(0);
}

//borra todos los productos agregados a la tabla
void MainWindow::on_cancelPushButton_clicked()
{
    int filas=0;
    filas=ui->tableWidget->rowCount();
    while(filas>0){
        ui->tableWidget->removeRow(filas-1);
        filas--;
    }
    total=0;
    ui->CantProductSpinBox->setValue(ui->tableWidget->rowCount());
    ui->totalSpinBox->setValue(total);
    
}

//crea un boton que se inserta en la columna 2 de la fila creada
void MainWindow::createButtonCancel(int fila)
{
    QPixmap pixmap(":/images/if_Cancel_131742.png");
    QIcon buttonIcon(pixmap);
    btn_cancelar=new QPushButton();
    btn_cancelar->setIcon(buttonIcon);
    ui->tableWidget->setCellWidget(fila,2,btn_cancelar);
    QObject::connect(btn_cancelar, &QPushButton::clicked, this, &MainWindow::removeRow);

}


//elimina una fila
void MainWindow::removeRow()
{
    int value;

    if(ui->tableWidget->rowCount()==1){

        QTableWidgetItem *item =ui->tableWidget->item(0,1);
        value= item->text().toInt();

        ui->tableWidget->removeRow(0);

        total=total-value;
        ui->CantProductSpinBox->setValue(ui->tableWidget->rowCount());
        ui->totalSpinBox->setValue(total);
    }else{
        QWidget *w = qobject_cast<QWidget *>(sender()->parent());
        if(w){
            int row = ui->tableWidget->indexAt(w->pos()).row();
            int fila=row+1;
            QTableWidgetItem *item =ui->tableWidget->item(fila,1);
            value= item->text().toInt();
            ui->tableWidget->removeRow(fila);
            ui->tableWidget->setCurrentCell(0, 0);


            total=total-value;
            ui->CantProductSpinBox->setValue(ui->tableWidget->rowCount());
            ui->totalSpinBox->setValue(total);
        }


    }



}


