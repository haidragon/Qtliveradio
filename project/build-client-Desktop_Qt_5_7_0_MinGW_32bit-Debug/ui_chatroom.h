/********************************************************************************
** Form generated from reading UI file 'chatroom.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATROOM_H
#define UI_CHATROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChatRoom
{
public:
    QTextEdit *textEdit;
    QPushButton *send;
    QLabel *label;
    QPushButton *chatlist_btn;
    QTextBrowser *textBrowser;
    QPushButton *video;
    QPushButton *audio;
    QPushButton *bs;
    QPushButton *gift;
    QListWidget *listWidget;
    QLabel *cur_user;
    QLabel *videosurface;
    QLabel *textscroll;
    QLabel *audioinput;

    void setupUi(QDialog *ChatRoom)
    {
        if (ChatRoom->objectName().isEmpty())
            ChatRoom->setObjectName(QStringLiteral("ChatRoom"));
        ChatRoom->resize(747, 435);
        textEdit = new QTextEdit(ChatRoom);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(20, 320, 491, 61));
        send = new QPushButton(ChatRoom);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(420, 390, 81, 31));
        label = new QLabel(ChatRoom);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(530, 40, 71, 16));
        chatlist_btn = new QPushButton(ChatRoom);
        chatlist_btn->setObjectName(QStringLiteral("chatlist_btn"));
        chatlist_btn->setGeometry(QRect(670, 30, 51, 41));
        textBrowser = new QTextBrowser(ChatRoom);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(25, 10, 481, 241));
        video = new QPushButton(ChatRoom);
        video->setObjectName(QStringLiteral("video"));
        video->setGeometry(QRect(40, 270, 71, 41));
        audio = new QPushButton(ChatRoom);
        audio->setObjectName(QStringLiteral("audio"));
        audio->setGeometry(QRect(140, 270, 71, 41));
        bs = new QPushButton(ChatRoom);
        bs->setObjectName(QStringLiteral("bs"));
        bs->setGeometry(QRect(260, 270, 71, 41));
        gift = new QPushButton(ChatRoom);
        gift->setObjectName(QStringLiteral("gift"));
        gift->setGeometry(QRect(370, 270, 71, 41));
        listWidget = new QListWidget(ChatRoom);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(530, 70, 201, 351));
        cur_user = new QLabel(ChatRoom);
        cur_user->setObjectName(QStringLiteral("cur_user"));
        cur_user->setGeometry(QRect(540, 0, 151, 21));
        videosurface = new QLabel(ChatRoom);
        videosurface->setObjectName(QStringLiteral("videosurface"));
        videosurface->setGeometry(QRect(20, 10, 481, 241));
        textscroll = new QLabel(ChatRoom);
        textscroll->setObjectName(QStringLiteral("textscroll"));
        textscroll->setGeometry(QRect(20, 10, 481, 241));
        audioinput = new QLabel(ChatRoom);
        audioinput->setObjectName(QStringLiteral("audioinput"));
        audioinput->setGeometry(QRect(140, 10, 231, 231));

        retranslateUi(ChatRoom);

        QMetaObject::connectSlotsByName(ChatRoom);
    } // setupUi

    void retranslateUi(QDialog *ChatRoom)
    {
        ChatRoom->setWindowTitle(QApplication::translate("ChatRoom", "Dialog", 0));
        send->setText(QApplication::translate("ChatRoom", "\345\217\221\351\200\201", 0));
        label->setText(QApplication::translate("ChatRoom", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600; color:#aa0000;\">\347\224\250\346\210\267\345\210\227\350\241\250&gt;&gt;&gt;</span></p></body></html>", 0));
        chatlist_btn->setText(QString());
        video->setText(QApplication::translate("ChatRoom", "\347\233\264\346\222\255", 0));
        audio->setText(QApplication::translate("ChatRoom", "\350\257\255\351\237\263", 0));
        bs->setText(QApplication::translate("ChatRoom", "\345\274\271\345\271\225", 0));
        gift->setText(QApplication::translate("ChatRoom", "\351\200\201\347\244\274", 0));
        cur_user->setText(QApplication::translate("ChatRoom", "TextLabel", 0));
        videosurface->setText(QString());
        textscroll->setText(QApplication::translate("ChatRoom", "<html><head/><body><p align=\"center\"><br/></p></body></html>", 0));
        audioinput->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ChatRoom: public Ui_ChatRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATROOM_H
