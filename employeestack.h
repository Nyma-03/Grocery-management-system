#ifndef EMPLOYEESTACK_H
#define EMPLOYEESTACK_H

#include <QQueue>
#include "employee.h" // Include Employee class if not already included

class EmployeeStack {
public:
    EmployeeStack();
    ~EmployeeStack();

    void addEmployee(const Employee &employee);
    void removeEmployee();
    bool isEmpty() const;
    QQueue<Employee> getQueue() const; // Added to retrieve the queue for display

private:
    QQueue<Employee> queue;
};

#endif // EMPLOYEESTACK_H
