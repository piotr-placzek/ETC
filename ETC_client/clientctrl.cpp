#include "clientctrl.h"

ClientCtrl::ClientCtrl(QObject *parent) : QObject(parent)
{
    client = new ETC_lib(Abstract_ETC_lib::CLIENT,this);
    connect(client,SIGNAL(connected()),SLOT(onConnected()));
    connect(client,SIGNAL(disconnected()),SLOT(onDisconnected()));
    connect(client,SIGNAL(errorOccured(QString)),SLOT(onErrorOccured(QString)));
    onErrorOccured("test");
}

void ClientCtrl::onConnectWithHost(const QString &hostName, const quint16 &port)
{
    client->start(hostName,port);
}

void ClientCtrl::onDisconnectFromHost()
{
    client->stop();
}

void ClientCtrl::onRefreshData()
{
    qDebug() << "void ClientCtrl::onRefreshData()";
}

void ClientCtrl::onCreateNewElement(const quint64 &timestamp, const quint8 &priority, const QString &description)
{
    Q_UNUSED(timestamp)
    Q_UNUSED(priority)
    Q_UNUSED(description)
    qDebug() << "void ClientCtrl::onCreateNewElement(const quint64 &timestamp, const quint8 &priority, const QString &description)";
}

void ClientCtrl::onConnected()
{
    qDebug() << "IP: "
             << client->currentHost()
             << "\nPORT: "
             << client->currentPort()
             << endl;
    emit connected();
}

void ClientCtrl::onDisconnected()
{
    qDebug() << "disconnected" << endl;
    emit disconnected();
}

void ClientCtrl::onErrorOccured(const QString &errorText)
{
    qDebug() << "Error: " << errorText << endl;
    QMessageBox msg(QMessageBox::Warning,tr("TCP connection error"),errorText);
    msg.exec();
}
