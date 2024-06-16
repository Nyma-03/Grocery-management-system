#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee {
public:
    Employee(const QString &name = "", const QString &status = "");

    QString getName() const;
    QString getStatus() const;

    void setName(const QString &name);
    void setStatus(const QString &status);

private:
    QString name;
    QString status;
};

#endif // EMPLOYEE_H
