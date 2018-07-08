#include "mainwindow.h"
#include "clientctrl.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ClientCtrl clientCtrl;

    QObject::connect(&w,SIGNAL(connectWithHost(QString,quint16)),&clientCtrl,SLOT(onConnectWithHost(QString,quint16)));
    QObject::connect(&w,SIGNAL(disconnectFromHost()),&clientCtrl,SLOT(onDisconnectFromHost()));
    QObject::connect(&w,SIGNAL(refreshData()),&clientCtrl,SLOT(onRefreshData()));

    QObject::connect(&clientCtrl,SIGNAL(connected()),&w,SLOT(onConnected()));
    QObject::connect(&clientCtrl,SIGNAL(disconnected()),&w,SLOT(onDisconnected()));

    return a.exec();
}

