#ifndef CHECKOUTFORM_H
#define CHECKOUTFORM_H

#include <QDialog>
#include "productlist.h"

namespace Ui {
class CheckoutForm;
}

class CheckoutForm : public QDialog
{
    Q_OBJECT

public:
    explicit CheckoutForm(ProductList *productList, QWidget *parent = nullptr);
    ~CheckoutForm();

private slots:
    void on_checkoutButton_clicked(); // Slot to handle checkout button click

private:
    Ui::CheckoutForm *ui; // User interface object
    ProductList *productList; // Pointer to ProductList object
};

#endif // CHECKOUTFORM_H
