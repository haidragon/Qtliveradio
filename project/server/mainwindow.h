#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpServer>
#include"user.h"

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
    void on_pushButton_clicked();
    void onNewConnection();
    void onSigWrite(QTcpSocket *socket, user_t user, int len);
private:
    Ui::MainWindow *ui;
    QTcpServer *server;
};

#endif // MAINWINDOW_H
