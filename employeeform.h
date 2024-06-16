// employeeform.h
#ifndef EMPLOYEEFORM_H
#define EMPLOYEEFORM_H

#include <QDialog>
#include "employeestack.h"

namespace Ui {
class EmployeeForm;
}

class EmployeeForm : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeForm(QWidget *parent = nullptr);
    ~EmployeeForm();

private slots:
    void on_addEmployeeButton_clicked();
    void on_removeEmployeeButton_clicked();

private:
    void updateEmployeeList();

    Ui::EmployeeForm *ui;
    EmployeeStack employeeStack;
};

#endif // EMPLOYEEFORM_H
