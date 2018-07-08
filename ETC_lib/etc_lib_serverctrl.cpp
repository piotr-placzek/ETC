#include "etc_lib_serverctrl.h"

ETC_lib_ServerCtrl::ETC_lib_ServerCtrl()
{
//    abort();
}

void ETC_lib_ServerCtrl::start(const QString &hostAddress, const quint16 &port)
{
    Q_UNUSED(hostAddress)
    Q_UNUSED(port)
    if(this->listen()){
        emit connected();
    }
    else{
        emit errorOccured(errorString());
    }
}

QString ETC_lib_ServerCtrl::currentHost()
{
    QString ipAddress;

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();

    return ipAddress;
    //    return this->serverAddress().toString();
}

quint16 ETC_lib_ServerCtrl::currentPort()
{
    return this->serverPort();
}

void ETC_lib_ServerCtrl::incomingConnection(qintptr socketDescriptor)
{
    QThread *thread = new QThread;
    ServerClient *client = new ServerClient(socketDescriptor,nullptr); //QObject::moveToThread: Cannot move objects with a parent
    client->moveToThread(thread);
    QObject::connect(client,SIGNAL(finished()),thread,SLOT(quit()));
    QObject::connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
    thread->start();
}

ServerClient::ServerClient(int socketDescriptor, QObject *parent):
    QObject(parent),
    byteArray(QByteArray(3,0xA))
{
    this->socket.setSocketDescriptor(socketDescriptor);
    connect(&socket,SIGNAL(disconnected()),SLOT(onConnectionAbort()));
    connect(&socket,SIGNAL(readyRead()),SLOT(readyRead()));
}

void ServerClient::readyRead()
{
    qDebug() << socket.readAll();
//    socket.write(socket.readAll());
}

void ServerClient::onConnectionAbort()
{
    emit finished();
}
