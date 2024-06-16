#ifndef SORTEDPRODUCTSFORM_H
#define SORTEDPRODUCTSFORM_H

#include <QDialog>
#include "productlist.h"  // Include your ProductList header file

namespace Ui {
class SortedProductsForm;
}

class SortedProductsForm : public QDialog
{
    Q_OBJECT

public:
    explicit SortedProductsForm(ProductList *productList, QWidget *parent = nullptr);
    ~SortedProductsForm();

private:
    Ui::SortedProductsForm *ui;
    ProductList *productList;

    void updateProductListWidget();
    void bubbleSortByName();
};

#endif // SORTEDPRODUCTSFORM_H
