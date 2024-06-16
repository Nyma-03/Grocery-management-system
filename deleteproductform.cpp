#include "deleteproductform.h"
#include "ui_deleteproductform.h"
#include <QMessageBox>

DeleteProductForm::DeleteProductForm(ProductList *productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteProductForm),
    productList(productList)
{
    ui->setupUi(this);
}

DeleteProductForm::~DeleteProductForm()
{
    delete ui;
}

void DeleteProductForm::on_deleteButton_clicked()
{
    QString productName = ui->productNameLineEdit->text();
    if (productList->deleteProduct(productName)) {
        QMessageBox::information(this, "Success", "Product deleted successfully.");
    } else {
        QMessageBox::warning(this, "Error", "Product not found.");
    }
}
