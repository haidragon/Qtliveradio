#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHostAddress>
#include<string.h>
#include<QDebug>
#include"user.h"
#include<QByteArray>
#include"clientsocket.h"
#include<QThread>
#include<QMetaType>


/*
函数功能：构造函数
参数：QWidget *parent
返回值：无
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet ("background-image:url(:/image/image/pic1.jpg)");
    ui->name->setStyleSheet ("background-image:url()");
    ui->passwd->setStyleSheet ("background-image:url()");
    ui->login->setFlat (true);
    ui->reg->setFlat (true);

    ui->login->setStyleSheet("border-radius:10px;padding:2px 4px;");
    ui->reg->setStyleSheet("border-radius:10px;padding:2px 4px;");

    socket = new QTcpSocket(this);
    //连接服务器出错时执行槽函数
    QObject::connect(socket, SIGNAL(error(QAbstractSocket::SocketError)),
                     this, SLOT(onError(QAbstractSocket::SocketError)));

    qRegisterMetaType<user_t>("user_t");        //向Qt注册user_t结构体

    cs = new ClientSocket(socket);
    QThread *th = new QThread();

    //连接断开时删除子线程的内存
    QObject::connect(socket, SIGNAL(disconnected()),
                    cs, SLOT(deleteLater()));
    //连接断开时结束子线程
    QObject::connect(socket, SIGNAL(disconnected()),
                    th, SLOT(quit()));
    //接收到子线程返回的注册信息
    QObject::connect(cs,SIGNAL(sigReg(user_t)),
                     this, SLOT(onSigReg(user_t)));
    //接收到子线程返回的登录信息
    QObject::connect(cs, SIGNAL(sigLogin(user_t)),
                     this, SLOT(onSigLogin(user_t)));

    cs->moveToThread(th);   //客户端创建线程，在子线程执行读操作
    th->start();

//    QHostAddress addr("192.168.1.103");
//    socket->connectToHost(addr, 8888);
    socket->connectToHost(QHostAddress::LocalHost, 8888);
    ui->passwd->setEchoMode(QLineEdit::Password);   //设置密码加密
}


/*
函数功能：析构函数
参数：无
返回值：无
*/
MainWindow::~MainWindow()
{
    delete ui;
}


/*
函数功能：网络链接错误处理
参数：QAbstractSocket::SocketError socketError
返回值：无
*/
void MainWindow::onError(QAbstractSocket::SocketError socketError)
{
    box.warning(this, "警告", "连接服务器失败");
}


/*
函数功能：注册按钮
参数：无
返回值：无
*/
void MainWindow::on_reg_clicked()
{
    user_t user;
    memset(&user, 0, sizeof(user_t));
    QString name = ui->name->text();
    if(name.isEmpty()){
        box.warning(this, "警告", "请输入用户名");
        return;
    }
    ui->name->clear();
    char* pname = name.toLocal8Bit().data();
    strncpy(user.username, pname, 20);

    QString passwd = ui->passwd->text();
    if(passwd.isEmpty()){
        box.warning(this, "警告", "请输入密码");
        return;
    }
    ui->passwd->clear();
    char* ppasswd = passwd.toLocal8Bit().data();
    strncpy(user.userpasswd, ppasswd, 20);
    user.type = REG;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：登录按钮
参数：无
返回值：无
*/
void MainWindow::on_login_clicked()
{
    user_t user;
    memset(&user, 0, sizeof(user_t));
    QString name = ui->name->text();
    ui->name->clear();
    char* pname = name.toLocal8Bit().data();
    strncpy(user.username, pname, 20);

    QString passwd = ui->passwd->text();
    ui->passwd->clear();
    char* ppasswd = passwd.toLocal8Bit().data();
    strncpy(user.userpasswd, ppasswd, 20);
    user.type = LOGIN;
    socket->write((char*)&user, sizeof(user));
}


/*
函数功能：注册
参数：user_t user
返回值：无
*/
void MainWindow::onSigReg(user_t user)
{
    QString text = user.data;
    if(text != "注册成功"){
        box.warning(this, "警告", text);
    }
    else{
        box.information(this, "提示", text);
    }
}


/*
函数功能：登录
参数：user_t user
返回值：无
*/
void MainWindow::onSigLogin(user_t user)
{
    QString text = user.data;
    if(text != "登陆成功"){
        box.warning(this, "警告", text);
    }
    else{
        box.information(this, "提示", text);
        dialog = new Dialog(cs, socket, user, this);

        QString str = QString::fromLocal8Bit (user.username);
        str += ", 欢迎来到江山悦播";
        dialog->setWindowTitle (str);
      //  dialog->move (1000,60);
        this->hide();
        dialog->show();
    }
}
