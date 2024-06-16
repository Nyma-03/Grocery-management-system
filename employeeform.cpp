// employeeform.cpp
#include "employeeform.h"
#include "ui_employeeform.h"

EmployeeForm::EmployeeForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeForm)
{
    ui->setupUi(this);

    // Connect buttons to their respective slots
    connect(ui->addEmployeeButton, &QPushButton::clicked, this, &EmployeeForm::on_addEmployeeButton_clicked);
    connect(ui->removeEmployeeButton, &QPushButton::clicked, this, &EmployeeForm::on_removeEmployeeButton_clicked);
}

EmployeeForm::~EmployeeForm()
{
    delete ui;
}

void EmployeeForm::on_addEmployeeButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString status = ui->statusLineEdit->text();

    if (!name.isEmpty() && !status.isEmpty()) {
        Employee employee(name, status);
        employeeStack.push(employee);
        updateEmployeeList();
    }
}

void EmployeeForm::on_removeEmployeeButton_clicked()
{
    employeeStack.pop();
    updateEmployeeList();
}

void EmployeeForm::updateEmployeeList()
{
    ui->employeeNameListWidget->clear();
    ui->employeeStatusListWidget->clear();

    const QStack<Employee>& stack = employeeStack.getStack();
    int index = 1;
    for (const Employee& employee : stack) {
        ui->employeeNameListWidget->addItem(QString::number(index) + ". " + employee.getName());
        ui->employeeStatusListWidget->addItem(QString::number(index) + ". " + employee.getStatus());
        index++;
    }
}
