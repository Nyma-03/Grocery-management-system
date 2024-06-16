#ifndef EMPLOYEEMANAGEMENTDIALOG_H
#define EMPLOYEEMANAGEMENTDIALOG_H

#include <QDialog>
#include <QQueue> // Include necessary headers
#include "employee.h" // Adjust according to your Employee class

namespace Ui {
class EmployeeManagementDialog;
}

class EmployeeManagementDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeManagementDialog(QWidget *parent = nullptr);
    ~EmployeeManagementDialog();

private slots:
    void onCancelClicked();
    void on_addEmployeeButton_clicked();
    void on_removeEmployeeButton_clicked();
    void updateEmployeeList();

private:
    Ui::EmployeeManagementDialog *ui;
    QQueue<Employee> employeeQueue; // Use QQueue to store employees
};

#endif // EMPLOYEEMANAGEMENTDIALOG_H
