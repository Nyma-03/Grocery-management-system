#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QDialog>
#include "productlist.h"
#include "deleteproductform.h"
#include "searchproductform.h"
#include "totalpaymentsdialog.h"
// Include the header file for ProductList

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

private slots:
    void on_searchProductButton_clicked();
    void on_sortProductButton_clicked();
    void on_deleteProductButton_clicked();
    void on_addProductButton_clicked();
    void on_totalPaymentsButton_clicked();
    void on_seeProductsButton_clicked();
    void on_setProductQuantityPriceButton_clicked();
    void on_checkoutButton_clicked();

private:
    Ui::AdminPanel *ui;
    ProductList *productList;
    DeleteProductForm *deleteProductForm;
    SearchProductForm *searchProductForm;

    // Declare ProductList pointer
};

#endif // ADMINPANEL_H

