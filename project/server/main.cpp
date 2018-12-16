#include "mainwindow.h"
#include <QApplication>
#include<QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));

    MainWindow w;
    w.show();

    return a.exec();
}
