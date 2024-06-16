QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproductform.cpp \
    adminpanel.cpp \
    checkoutform.cpp \
    deleteproductform.cpp \
    employee.cpp \
    employeemanagementdialog.cpp \
    employeestack.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    product.cpp \
    productlist.cpp \
    searchproductform.cpp \
    seeproductsform.cpp \
    sortedproductsform.cpp \
    totalpaymentsdialog.cpp

HEADERS += \
    addproductform.h \
    adminpanel.h \
    checkoutform.h \
    deleteproductform.h \
    employee.h \
    employeemanagementdialog.h \
    employeestack.h \
    loginform.h \
    mainwindow.h \
    product.h \
    productlist.h \
    searchproductform.h \
    seeproductsform.h \
    sortedproductsform.h \
    totalpaymentsdialog.h

FORMS += \
    addproductform.ui \
    adminpanel.ui \
    checkoutform.ui \
    deleteproductform.ui \
    employeemanagementdialog.ui \
    loginform.ui \
    mainwindow.ui \
    searchproductform.ui \
    seeproductsform.ui \
    sortedproductsform.ui \
    totalpaymentsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
