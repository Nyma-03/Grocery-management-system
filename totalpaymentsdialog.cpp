#include "totalpaymentsdialog.h"
#include "ui_totalpaymentsdialog.h"

TotalPaymentsDialog::TotalPaymentsDialog(double totalPayments, ProductList *productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TotalPaymentsDialog)
{
    ui->setupUi(this);

    // Set total payments label text
    ui->totalPaymentsLabel->setText(QString("Total Payments: $%1").arg(totalPayments));

    // Populate product details in QTextEdit
    Node* current = productList->getHead();
    while (current != nullptr) {
        const Product& product = current->data;
        QString productName = QString("%1").arg(product.getName());
        QString productPrice = QString("$%1").arg(product.getPrice());
        QString productQuantity = QString("%1").arg(product.getQuantity());

        // Append product details to QTextEdit
        ui->productNameTextEdit->append(productName);
        ui->productPriceTextEdit->append(productPrice);
        ui->productQuantityTextEdit->append(productQuantity);

        current = current->next;
    }
}

TotalPaymentsDialog::~TotalPaymentsDialog()
{
    delete ui;
}
