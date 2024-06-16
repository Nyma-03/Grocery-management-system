#ifndef SEARCHPRODUCTFORM_H
#define SEARCHPRODUCTFORM_H

#include <QDialog>
#include "productlist.h"

namespace Ui {
class SearchProductForm;
}

class SearchProductForm : public QDialog
{
    Q_OBJECT

public:
    explicit SearchProductForm(ProductList *productList, QWidget *parent = nullptr);
    ~SearchProductForm();

private slots:
    void on_searchButton_clicked();

private:
    Ui::SearchProductForm *ui;
    ProductList *productList;
};

#endif // SEARCHPRODUCTFORM_H
