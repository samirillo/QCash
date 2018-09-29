#include "product.h"

Product::Product(QString name, int value)
{
    this->nameProduct = name;
    this->valueProduct = value;
}

Product::Product()
{
    nameProduct="";
    valueProduct=0;
}

QString Product::name()
{
    return nameProduct;
}

int Product::value()
{
    return valueProduct;
}

void Product::setValueProduct(int value)
{
    valueProduct = value;
}

void Product::setNameProduct(const QString &value)
{
    nameProduct = value;
}
