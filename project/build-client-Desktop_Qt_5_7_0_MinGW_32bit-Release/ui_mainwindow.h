/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *name;
    QLineEdit *passwd;
    QLabel *lb_name;
    QLabel *lb_passwd;
    QPushButton *reg;
    QPushButton *login;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(421, 305);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        name = new QLineEdit(centralWidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(160, 70, 141, 20));
        passwd = new QLineEdit(centralWidget);
        passwd->setObjectName(QStringLiteral("passwd"));
        passwd->setGeometry(QRect(160, 110, 141, 20));
        lb_name = new QLabel(centralWidget);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(90, 70, 54, 12));
        lb_passwd = new QLabel(centralWidget);
        lb_passwd->setObjectName(QStringLiteral("lb_passwd"));
        lb_passwd->setGeometry(QRect(90, 110, 54, 12));
        reg = new QPushButton(centralWidget);
        reg->setObjectName(QStringLiteral("reg"));
        reg->setGeometry(QRect(80, 160, 75, 23));
        login = new QPushButton(centralWidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(230, 160, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 421, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\261\237\345\261\261\346\202\246\346\222\255", 0));
        lb_name->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\345\220\215", 0));
        lb_passwd->setText(QApplication::translate("MainWindow", "\345\257\206   \347\240\201", 0));
        reg->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", 0));
        login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
