/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QListWidget *chatroom;
    QPushButton *destory;
    QPushButton *exit_btn;
    QLabel *list;
    QPushButton *roomlist_btn;
    QListWidget *user;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(302, 541);
        chatroom = new QListWidget(Dialog);
        chatroom->setObjectName(QStringLiteral("chatroom"));
        chatroom->setGeometry(QRect(10, 120, 281, 351));
        destory = new QPushButton(Dialog);
        destory->setObjectName(QStringLiteral("destory"));
        destory->setGeometry(QRect(44, 492, 71, 41));
        exit_btn = new QPushButton(Dialog);
        exit_btn->setObjectName(QStringLiteral("exit_btn"));
        exit_btn->setGeometry(QRect(194, 492, 71, 41));
        list = new QLabel(Dialog);
        list->setObjectName(QStringLiteral("list"));
        list->setGeometry(QRect(20, 100, 111, 16));
        roomlist_btn = new QPushButton(Dialog);
        roomlist_btn->setObjectName(QStringLiteral("roomlist_btn"));
        roomlist_btn->setGeometry(QRect(180, 80, 51, 41));
        user = new QListWidget(Dialog);
        user->setObjectName(QStringLiteral("user"));
        user->setGeometry(QRect(10, 0, 281, 81));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        destory->setText(QApplication::translate("Dialog", "\346\263\250\351\224\200", 0));
        exit_btn->setText(QApplication::translate("Dialog", "\351\200\200\345\207\272", 0));
        list->setText(QApplication::translate("Dialog", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">\350\201\212\345\244\251\345\256\244\345\210\227\350\241\250&gt;&gt;&gt;</span></p></body></html>", 0));
        roomlist_btn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
