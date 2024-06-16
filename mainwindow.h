// mainwindow.h
#include "ui_mainwindow.h"
#include "loginform.h"
#include "productlist.h"
#include "adminpanel.h"
#include "product.h"
#include "addproductform.h"

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_adminButton_clicked();
    // void on_userButton_clicked();

private:
    Ui::MainWindow *ui;
    LoginForm *loginForm;
};


#endif // MAINWINDOW_H
