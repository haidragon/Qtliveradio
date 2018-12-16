#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include"user.h"
#include"dialog.h"
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void onError(QAbstractSocket::SocketError socketError);//网络连接错误信息
    void on_reg_clicked();//注册按钮
    void on_login_clicked();//登录按钮
    void onSigReg(user_t user);//注册
    void onSigLogin(user_t user);//登录

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    Dialog *dialog;
    ClientSocket *cs;
    QMessageBox box;
};

#endif // MAINWINDOW_H
