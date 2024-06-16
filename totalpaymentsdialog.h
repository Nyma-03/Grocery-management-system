#ifndef TOTALPAYMENTSDIALOG_H
#define TOTALPAYMENTSDIALOG_H

#include <QDialog>
#include <queue>
#include "productlist.h" // Include necessary headers for ProductList

namespace Ui {
class TotalPaymentsDialog;
}

class TotalPaymentsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TotalPaymentsDialog(double totalPayments, ProductList *productList, QWidget *parent = nullptr);
    ~TotalPaymentsDialog();

private:
    Ui::TotalPaymentsDialog *ui;
    std::queue<QString> productDetailsQueue;
};

#endif // TOTALPAYMENTSDIALOG_H
