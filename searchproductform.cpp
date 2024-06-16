#include "searchproductform.h"
#include "ui_searchproductform.h"
#include <QMessageBox>

SearchProductForm::SearchProductForm(ProductList *productList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchProductForm),
    productList(productList)
{
    ui->setupUi(this);

    connect(ui->searchButton, &QPushButton::clicked, this, &SearchProductForm::on_searchButton_clicked);
}

SearchProductForm::~SearchProductForm()
{
    delete ui;
}

void SearchProductForm::on_searchButton_clicked()
{
    QString productName = ui->productNameLineEdit->text();
    Product* product = productList->searchProduct(productName);
    if (product) {
        QString productInfo = QString("Name: %1\nPrice: %2\nQuantity: %3")
                                  .arg(product->getName())
                                  .arg(product->getPrice())
                                  .arg(product->getQuantity());
        ui->resultLabel->setText(productInfo);
    } else {
        QMessageBox::warning(this, "Product Not Found", "The product does not exist.");
    }
}
