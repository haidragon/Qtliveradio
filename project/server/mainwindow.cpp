#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHostAddress>
#include<QTcpSocket>
#include"clientsocket.h"
#include<QThread>
#include"socketmanager.h"
#include<QMetaType>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //第一步：创建套接字管理对象
    server = new QTcpServer(this);

    //第三步：关联来自客户端的信号槽
    QObject::connect(server, SIGNAL(newConnection()),
                             this, SLOT(onNewConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(server->isListening()){
        ui->textEdit->append("已经在监听");
        return;
    }
    //第二步：启动监听
    bool ret = server->listen(QHostAddress::Any, 8888);
    if(ret == true){
        ui->textEdit->append("监听成功");
    }
    else{
        ui->textEdit->append("监听失败");
    }
}

void MainWindow::onNewConnection()
{
    ui->textEdit->append("有客户端连接上服务器");
    QTcpSocket *client = server->nextPendingConnection();
    ClientSocket *cs = new ClientSocket(client);

    QThread *th = new QThread(this);
    QObject::connect(client, SIGNAL(disconnected()),
                    cs, SLOT(deleteLater()));
    QObject::connect(client, SIGNAL(disconnected()),
                    th, SLOT(quit()));
    qRegisterMetaType<user_t>("user_t");    //完成结构体注册
    QObject::connect(cs, SIGNAL(sigWrite(QTcpSocket*,user_t,int)),
                     this, SLOT(onSigWrite(QTcpSocket*,user_t,int)));
    cs->moveToThread(th);
    th->start();

    SocketManager *sockets = SocketManager::getInstance ();
    sockets->insertSocket (cs);
}

void MainWindow::onSigWrite(QTcpSocket *socket, user_t user, int len)
{
    socket->write((char *)&user, len);
}
