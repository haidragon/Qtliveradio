/********************************************************************************
** Form generated from reading UI file 'gift.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GIFT_H
#define UI_GIFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gift
{
public:
    QRadioButton *socket;
    QRadioButton *dollar;
    QRadioButton *good;
    QRadioButton *mua;
    QPushButton *send;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QWidget *Gift)
    {
        if (Gift->objectName().isEmpty())
            Gift->setObjectName(QStringLiteral("Gift"));
        Gift->resize(300, 160);
        socket = new QRadioButton(Gift);
        socket->setObjectName(QStringLiteral("socket"));
        socket->setGeometry(QRect(30, 10, 89, 16));
        dollar = new QRadioButton(Gift);
        dollar->setObjectName(QStringLiteral("dollar"));
        dollar->setGeometry(QRect(30, 50, 89, 16));
        good = new QRadioButton(Gift);
        good->setObjectName(QStringLiteral("good"));
        good->setGeometry(QRect(30, 90, 89, 16));
        mua = new QRadioButton(Gift);
        mua->setObjectName(QStringLiteral("mua"));
        mua->setGeometry(QRect(30, 130, 89, 16));
        send = new QPushButton(Gift);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(190, 100, 75, 23));
        spinBox = new QSpinBox(Gift);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(190, 40, 91, 22));
        label = new QLabel(Gift);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 10, 54, 12));

        retranslateUi(Gift);

        QMetaObject::connectSlotsByName(Gift);
    } // setupUi

    void retranslateUi(QWidget *Gift)
    {
        Gift->setWindowTitle(QApplication::translate("Gift", "Form", 0));
        socket->setText(QApplication::translate("Gift", "\347\201\253\347\256\255", 0));
        dollar->setText(QApplication::translate("Gift", "\351\207\221\345\270\201", 0));
        good->setText(QApplication::translate("Gift", "\347\202\271\350\265\236", 0));
        mua->setText(QApplication::translate("Gift", "\344\271\210\344\271\210\345\223\222", 0));
        send->setText(QApplication::translate("Gift", "\350\265\240\351\200\201", 0));
        label->setText(QApplication::translate("Gift", "\346\225\260\351\207\217", 0));
    } // retranslateUi

};

namespace Ui {
    class Gift: public Ui_Gift {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GIFT_H
