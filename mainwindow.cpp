// // mainwindow.cpp

// #include "mainwindow.h"
// #include "ui_mainwindow.h"
// #include "ui_mainwindow.h"
// #include "loginform.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginform.h"
#include "adminpanel.h"
#include "productlist.h"
#include "product.h"





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect button clicks to slots
    connect(ui->adminButton, &QPushButton::clicked, this, &MainWindow::on_adminButton_clicked);
    // connect(ui->userButton, &QPushButton::clicked, this, &MainWindow::on_userButton_clicked);
    loginForm = new LoginForm(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_adminButton_clicked()
{
    // Handle admin button click
    // For now, let's just print a message
    loginForm->show();
}

