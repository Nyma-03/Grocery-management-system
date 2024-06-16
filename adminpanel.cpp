#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "addproductform.h"
#include "seeproductsform.h"
#include "sortedproductsform.h"
#include "employeemanagementdialog.h"
#include "checkoutform.h"

#include <QDebug>

AdminPanel::AdminPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPanel),
    productList(new ProductList) ,
    searchProductForm(nullptr),

    deleteProductForm(nullptr)
// Initialize the ProductList pointer
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->searchProductButton, &QPushButton::clicked, this, &AdminPanel::on_searchProductButton_clicked);
    connect(ui->sortProductButton, &QPushButton::clicked, this, &AdminPanel::on_sortProductButton_clicked);
    connect(ui->deleteProductButton, &QPushButton::clicked, this, &AdminPanel::on_deleteProductButton_clicked);
    connect(ui->addProductButton, &QPushButton::clicked, this, &AdminPanel::on_addProductButton_clicked);
    connect(ui->totalPaymentsButton, &QPushButton::clicked, this, &AdminPanel::on_totalPaymentsButton_clicked);
    connect(ui->seeProductsButton, &QPushButton::clicked, this, &AdminPanel::on_seeProductsButton_clicked);
    connect(ui->setProductQuantityPriceButton, &QPushButton::clicked, this, &AdminPanel::on_setProductQuantityPriceButton_clicked);
    connect(ui->checkoutButton, &QPushButton::clicked, this, &AdminPanel::on_checkoutButton_clicked);
}

AdminPanel::~AdminPanel()
{
    delete productList; // Clean up the ProductList pointer
    delete ui;
    if (deleteProductForm) {
        delete deleteProductForm;
    }
}

void AdminPanel::on_searchProductButton_clicked()
{

    if (!searchProductForm) {
        searchProductForm = new SearchProductForm(productList, this);
    }
    searchProductForm->show();

}

void AdminPanel::on_sortProductButton_clicked()
{
    productList->bubbleSortByName();  // Sort products in ProductList

    // Open SortedProductsForm to display sorted products
    SortedProductsForm sortedProductsForm(productList, this);
    sortedProductsForm.exec();

    qDebug() << "Products sorted by name.";
}

void AdminPanel::on_deleteProductButton_clicked()
{
    if (!deleteProductForm) {
        deleteProductForm = new DeleteProductForm(productList, this);
    }
    deleteProductForm->show();
}

void AdminPanel::on_addProductButton_clicked()
{
    AddProductForm addProductForm(productList, this); // Pass the product list to the form
    if (addProductForm.exec() == QDialog::Accepted) {
        qDebug() << "Product added successfully.";
        // TODO: Refresh the product list in the AdminPanel if needed
    } else {
        qDebug() << "Add product cancelled.";
    }
    qDebug() << "Add Product button clicked!";
}

void AdminPanel::on_totalPaymentsButton_clicked()
{
    // Implement the functionality for displaying the total payments of today
    qDebug() << "Total Payments button clicked!";

    double totalPayments = productList->calculateTotalPayments();

    // Show TotalPaymentsDialog with total payments and product details from queue
    TotalPaymentsDialog totalPaymentsDialog(totalPayments, productList, this);
    totalPaymentsDialog.exec();
}

void AdminPanel::on_seeProductsButton_clicked()
{
    // Implement the functionality for seeing all products
    productList->printProducts();
    SeeProductsForm seeProductsForm(productList, this);
    seeProductsForm.exec();
    qDebug() << "See Products button clicked!";
}

void AdminPanel::on_setProductQuantityPriceButton_clicked()
{
    // Implement the functionality for setting the product quantity and price
    qDebug() << "Set Product Quantity and Price button clicked!";
    EmployeeManagementDialog employeeDialog(this);
    employeeDialog.exec();


}

void AdminPanel::on_checkoutButton_clicked()
{
    // Implement the functionality for checkout
    qDebug() << "Checkout button clicked!";

    CheckoutForm checkoutForm(productList, this);
    checkoutForm.exec();
}
