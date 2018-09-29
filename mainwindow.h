#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include <QPushButton>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
static int total;


private slots:
    void on_addPushButton_clicked();

    void on_okPushButton_clicked();

    void on_cancelPushButton_clicked();

    void createButtonCancel(int fila);

    void removeRow();

private:
    Ui::MainWindow *ui;
    QPushButton* btn_cancelar;


    enum Columnas
    {
      PRODUCTO, VALOR, CANCELAR
    };
};

#endif // MAINWINDOW_H
