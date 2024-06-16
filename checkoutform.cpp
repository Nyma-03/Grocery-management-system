#include "checkoutform.h"
#include "ui_checkoutform.h"
#include <QMessageBox>

CheckoutForm::CheckoutForm(ProductList *productList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CheckoutForm)
    , productList(productList)
{
    ui->setupUi(this); // Initialize UI components from Qt Designer
}

CheckoutForm::~CheckoutForm()
{
    delete ui; // Clean up UI resources
}

void CheckoutForm::on_checkoutButton_clicked()
{
    // Get input data from the form
    QString productName = ui->productNameLineEdit->text();
    int quantityToCheckout = ui->quantitySpinBox->value();

    // Validate input
    if (productName.isEmpty() || quantityToCheckout <= 0) {
        QMessageBox::warning(this, "Error", "Please enter valid product name and quantity.");
        return;
    }

    // Call ProductList method to checkout product
    bool success = productList->checkoutProduct(productName, quantityToCheckout);

    // Provide feedback to user
    if (success) {
        QMessageBox::information(this, "Success", "Product checked out successfully.");
        accept(); // Close the dialog if checkout is successful
    } else {
        QMessageBox::warning(this, "Error", "Failed to checkout product. Please check quantity.");
    }
}
