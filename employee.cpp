#include "employee.h"

Employee::Employee(const QString &name, const QString &status)
    : name(name), status(status) {}

QString Employee::getName() const {
    return name;
}

QString Employee::getStatus() const {
    return status;
}

void Employee::setName(const QString &name) {
    this->name = name;
}

void Employee::setStatus(const QString &status) {
    this->status = status;
}
