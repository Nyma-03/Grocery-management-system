#include "employeemanagementdialog.h"
#include "ui_employeemanagementdialog.h"

EmployeeManagementDialog::EmployeeManagementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeManagementDialog)
{
    ui->setupUi(this);
    connect(ui->cancelButton, &QPushButton::clicked, this, &EmployeeManagementDialog::onCancelClicked);

    // Example: Populate UI with existing employees
    updateEmployeeList();
}

EmployeeManagementDialog::~EmployeeManagementDialog()
{
    delete ui;
}

void EmployeeManagementDialog::onCancelClicked()
{
    reject(); // Close the dialog without making any changes
}

void EmployeeManagementDialog::on_addEmployeeButton_clicked()
{
    QString name = ui->nameLineEdit->text();
    QString status = ui->statusLineEdit->text();

    Employee employee(name, status);
    employeeQueue.enqueue(employee);

    updateEmployeeList();
}

void EmployeeManagementDialog::on_removeEmployeeButton_clicked()
{
    if (!employeeQueue.isEmpty()) {
        employeeQueue.dequeue();
        updateEmployeeList();
    }
}

void EmployeeManagementDialog::updateEmployeeList()
{
    ui->employeeListWidget->clear();

    QQueue<Employee> tempQueue = employeeQueue;

    while (!tempQueue.isEmpty()) {
        Employee employee = tempQueue.dequeue();
        ui->employeeListWidget->addItem(QString("%1 - %2").arg(employee.getName()).arg(employee.getStatus()));
    }
}
