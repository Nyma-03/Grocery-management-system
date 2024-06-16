#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product {
public:
    Product(const QString &name = "", double price = 0.0, int quantity = 0);

    QString getName() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(const QString &name);
    void setPrice(double price);
    void setQuantity(int quantity);

private:
    QString name;
    double price;
    int quantity;
};

#endif // PRODUCT_H
