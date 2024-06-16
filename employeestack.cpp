#include "employeestack.h"


EmployeeStack::EmployeeStack() {}

EmployeeStack::~EmployeeStack() {}

void EmployeeStack::addEmployee(const Employee &employee)
{
    queue.enqueue(employee);
}

void EmployeeStack::removeEmployee()
{
    if (!queue.isEmpty()) {
        queue.dequeue();
    }
}

bool EmployeeStack::isEmpty() const
{
    return queue.isEmpty();
}

QQueue<Employee> EmployeeStack::getQueue() const
{
    return queue;
}
