#include "loginform.h"
#include "productlist.h"
#include "ui_loginform.h"
#include "adminpanel.h"
#include <QMessageBox>



LoginForm::LoginForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginForm),
    adminPanel(nullptr)
{
    ui->setupUi(this);
}

LoginForm::~LoginForm()
{
    delete ui;
}

void LoginForm::on_loginButton_clicked()
{
    // Retrieve the text entered by the user from QLineEdit widgets
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    // Perform validation or processing with the username and password
    // For example, you can print them to debug output
    qDebug() << "Username:" << username;
    qDebug() << "Password:" << password;


    // Add your login validation logic here
    if (username == "admin" && password == "password") {
        qDebug() << "Login successful!";
        adminPanel = new AdminPanel();
        adminPanel->show();
        // Proceed with admin access
        accept(); // Close the login dialog with success
    } else {
        qDebug() << "Login failed!";
        // Optionally, show a message box to the user
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password.");

    // Close the login form (optional)
    // this->close();

}
}
