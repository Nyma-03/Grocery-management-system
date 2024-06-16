#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include "product.h"
// #include <QStack>
// Include necessary headers for Product class

class Node {
public:
    Product data;
    Node* next;

    Node(const Product &product) : data(product), next(nullptr) {}
};

class ProductList {
public:
    ProductList();
    ~ProductList();

    void addProduct(const Product &product);
    bool deleteProduct(const QString &name);
    Product* searchProduct(const QString &name);
    void printProducts() const;
     void sortProducts();
    void bubbleSortByName();
     double calculateTotalPayments() const; // Added method for calculating total payments
    bool checkoutProduct(const QString &name, int quantityToCheckout);
     // bool undoLastAdd();
     Node* getHead() const;

private:
     // QStack<Product> productStack;
    Node* head;
};

#endif // PRODUCTLIST_H
