#ifndef SEEPRODUCTSFORM_H
#define SEEPRODUCTSFORM_H

#include <QDialog>
#include "productlist.h"

namespace Ui {
class SeeProductsForm;
}

class SeeProductsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SeeProductsForm(ProductList* productList, QWidget *parent = nullptr);
    ~SeeProductsForm();

private:
    Ui::SeeProductsForm *ui;
    ProductList* productList; // Pointer to the product list
};

#endif // SEEPRODUCTSFORM_H
