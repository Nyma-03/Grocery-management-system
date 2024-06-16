
#include "addproductform.h"
#include "ui_addproductform.h"
#include "productlist.h"
#include <QMessageBox>



AddProductForm::AddProductForm(ProductList* productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProductForm),
    productList(productList) // Initialize the product list
{
    ui->setupUi(this);
}

AddProductForm::~AddProductForm()
{
    delete ui;
}

void AddProductForm::on_submitButton_clicked()
{
    QString name = ui->productNameLineEdit->text();
    double price = ui->productPriceLineEdit->text().toDouble();
    int quantity = ui->productQuantityLineEdit->text().toInt();

    if (name.isEmpty() || price <= 0 || quantity <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please provide valid product details.");
        return;
    }

    // Add the product to the product list
    productList->addProduct(Product(name, price, quantity));

    accept(); // Close the form after submission
}

void AddProductForm::on_cancelButton_clicked()
{
    reject(); // Close the form without submitting
}
// #include "addproductform.h"
// #include "ui_addproductform.h"
// #include "productlist.h"
// #include <QMessageBox>

// AddProductForm::AddProductForm(ProductList* productList, QWidget *parent) :
//     QDialog(parent),
//     ui(new Ui::AddProductForm),
//     productList(productList) // Initialize the product list
// {
//     connect(ui->undoButton, &QPushButton::clicked, this, &AddProductForm::on_undoButton_clicked);  // Connect the undo button
//     ui->setupUi(this);
// }

// AddProductForm::~AddProductForm()
// {
//     delete ui;
// }

// void AddProductForm::on_submitButton_clicked()
// {
//     QString name = ui->productNameLineEdit->text();
//     double price = ui->productPriceLineEdit->text().toDouble();
//     int quantity = ui->productQuantityLineEdit->text().toInt();

//     if (name.isEmpty() || price <= 0 || quantity <= 0) {
//         QMessageBox::warning(this, "Invalid Input", "Please provide valid product details.");
//         return;
//     }

//     // Add the product to the product list
//     productList->addProduct(Product(name, price, quantity));

//     accept(); // Close the form after submission
// }

// void AddProductForm::on_cancelButton_clicked()
// {
//     reject(); // Close the form without submitting
// }

// void AddProductForm::on_undoButton_clicked()
// {
//     if (productList->undoLastAdd()) {
//         QMessageBox::information(this, "Undo", "Last product addition undone.");
//     } else {
//         QMessageBox::warning(this, "Undo", "No product addition to undo.");
//     }
// }
