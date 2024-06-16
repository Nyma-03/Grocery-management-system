#include "seeproductsform.h"
#include "ui_seeproductsform.h"
#include "seeproductsform.h"
#include "ui_seeproductsform.h"
#include <QListWidget> // Include QListWidget header


SeeProductsForm::SeeProductsForm(ProductList* productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SeeProductsForm),
    productList(productList)
{
    ui->setupUi(this);
Q_ASSERT(qobject_cast<QListWidget*>(ui->productListWidget));
    // Populate the QListWidget with the products
    Node* current = productList->getHead(); // Use the getHead() method
    while (current != nullptr) {
        const Product& product = current->data;
        ui->productListWidget->addItem("Product:    " + product.getName() +
                                       "---------    Price:    " + QString::number(product.getPrice()) +
                                       "   --------- Quantity:    " + QString::number(product.getQuantity()));
        current = current->next;
    }
}

SeeProductsForm::~SeeProductsForm()
{
    delete ui;
}
