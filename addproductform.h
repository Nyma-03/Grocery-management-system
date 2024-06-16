#ifndef ADDPRODUCTFORM_H
#define ADDPRODUCTFORM_H

#include <QDialog>
#include "productlist.h"
// #include "product.h"
// #include "loginform.h"
// #include "ui_loginform.h"
// #include "adminpanel.h"
#include <QMessageBox>

namespace Ui {
class AddProductForm;
}

class AddProductForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddProductForm(ProductList* productList, QWidget *parent = nullptr);
    ~AddProductForm();

private slots:
    void on_submitButton_clicked();
    void on_cancelButton_clicked();
    // void on_undoButton_clicked(); // Ensure this is declared

private:
    Ui::AddProductForm *ui;
    ProductList *productList; // Add a member to store the product list
};

#endif // ADDPRODUCTFORM_H
