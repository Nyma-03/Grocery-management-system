#include "sortedproductsform.h"
#include "ui_sortedproductsform.h"
#include <QDebug>

SortedProductsForm::SortedProductsForm(ProductList *productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortedProductsForm),
    productList(productList)
{
    ui->setupUi(this);

    // Ensure productList is not null before using
    if (productList) {
        bubbleSortByName();  // Sort products by name initially
        updateProductListWidget();  // Update UI with sorted products
    } else {
        qDebug() << "Error: ProductList is null.";
    }
}

SortedProductsForm::~SortedProductsForm()
{
    delete ui;
}

void SortedProductsForm::updateProductListWidget()
{
    // Clear existing items in the list widget
    ui->productListWidget->clear();

    // Populate list widget with sorted products
    Node *current = productList->getHead();
    while (current != nullptr) {
        const Product &product = current->data;
        QString itemText = "Product: " + product.getName() +
                           ", Price: " + QString::number(product.getPrice()) +
                           ", Quantity: " + QString::number(product.getQuantity());
        ui->productListWidget->addItem(itemText);
        current = current->next;
    }
}

void SortedProductsForm::bubbleSortByName()
{
    if (!productList || !productList->getHead()) {
        qDebug() << "Error: ProductList or list head is null.";
        return;
    }

    bool swapped;
    Node *ptr;
    Node *lptr = nullptr;

    do {
        swapped = false;
        ptr = productList->getHead();

        while (ptr->next != lptr) {
            if (ptr->data.getName() > ptr->next->data.getName()) {
                // Swap data of adjacent nodes
                Product temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
