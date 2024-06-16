
#ifndef LOGINFORM_H
#define LOGINFORM_H
#include <QDialog>
#include <QMessageBox>
#include "adminpanel.h"
#include "ui_loginform.h" // Include generated UI header
#include "adminpanel.h" // Include AdminPanel header
#include "productlist.h"
class AdminPanel;
namespace Ui {
class LoginForm;
}

class LoginForm : public QDialog
{
    Q_OBJECT

public:
    explicit LoginForm(QWidget *parent = nullptr);
    ~LoginForm();

private slots:
    void on_loginButton_clicked();

private:
    Ui::LoginForm *ui;
    AdminPanel *adminPanel;
};

#endif // LOGINFORM_H
