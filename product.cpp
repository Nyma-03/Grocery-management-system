#include "product.h"

Product::Product(const QString &name, double price, int quantity)
    : name(name), price(price), quantity(quantity) {}

QString Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setName(const QString &name) {
    this->name = name;
}

void Product::setPrice(double price) {
    this->price = price;
}

void Product::setQuantity(int quantity) {
    this->quantity = quantity;
}
