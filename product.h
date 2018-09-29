#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>

class Product
{
public:
    Product(QString name, int value);
    Product();
    QString name();
    int value();

   QString nameProduct;
    int valueProduct;
    void setNameProduct(const QString &value);
    void setValueProduct(int value);
};

#endif // PRODUCT_H
