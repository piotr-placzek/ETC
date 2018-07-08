#include "serverctrl.h"

ServerCtrl::ServerCtrl(QObject *parent) : QObject(parent)
{
    server = new ETC_lib(Abstract_ETC_lib::SERVER,this);
    connect(server,SIGNAL(connected()),SLOT(onConnected()));
    connect(server,SIGNAL(disconnected()),SLOT(onDisconnected()));
    connect(server,SIGNAL(errorOccured(QString)),SLOT(onErrorOccured(QString)));

    qDebug() << "Starting..." << endl;
    server->start(QString(),0);
}

void ServerCtrl::onConnected()
{
    qDebug() << "IP: "
             << server->currentHost()
             << "\nPORT: "
             << server->currentPort()
             << endl;
}

void ServerCtrl::onDisconnected()
{
    qDebug() << "disconnected" << endl;
}

void ServerCtrl::onErrorOccured(const QString &errorText)
{
    qDebug() << "Error: " << errorText << endl;
}
