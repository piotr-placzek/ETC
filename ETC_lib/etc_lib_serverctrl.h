#ifndef ETC_LIB_SERVERCTRL_H
#define ETC_LIB_SERVERCTRL_H

#include "abstract_etc_lib_sidectrl.h"
#include <QTcpSocket>
#include <QTcpServer>
#include <QThread>
#include <QNetworkInterface>

class ETC_lib_ServerCtrl : public QTcpServer, public Abstract_ETC_lib_SideCtrl
{
    Q_OBJECT
public:
    ETC_lib_ServerCtrl();

    // Abstract_ETC_lib_SideCtrl interface
    void start(const QString &hostAddress, const quint16 &port);
    virtual void stop(){};
    QString currentHost();
    quint16 currentPort();

signals:
    // Abstract_ETC_lib_SideCtrl interface
    void connected();
    void disconnected();
    void errorOccured(const QString &errorText);

protected slots:
    void incomingConnection(qintptr socketDescriptor) override;

private:

};

class ServerClient : public QObject{
    Q_OBJECT
public:
    ServerClient(int socketDescriptor, QObject *parent);
signals:
    void finished();
private slots:
    void readyRead();
    void onConnectionAbort();
private:
    QTcpSocket socket;
    QByteArray byteArray;
};

#endif // ETC_LIB_SERVERCTRL_H
