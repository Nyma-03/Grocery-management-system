#ifndef DELETEPRODUCTFORM_H
#define DELETEPRODUCTFORM_H

#include <QDialog>
#include "productlist.h"

namespace Ui {
class DeleteProductForm;
}

class DeleteProductForm : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteProductForm(ProductList *productList, QWidget *parent = nullptr);
    ~DeleteProductForm();

private slots:
    void on_deleteButton_clicked();

private:
    Ui::DeleteProductForm *ui;
    ProductList *productList;
};

#endif // DELETEPRODUCTFORM_H
