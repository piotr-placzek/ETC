#ifndef CLIENTCTRL_H
#define CLIENTCTRL_H

#include <QObject>
#include <QDebug>
#include <QMessageBox>
#include "etc_lib.h"

class ClientCtrl : public QObject
{
    Q_OBJECT
public:
    explicit ClientCtrl(QObject *parent = nullptr);

signals:
    void connected();
    void disconnected();

public slots:
    void onConnectWithHost(const QString &hostName, const quint16 &port);
    void onDisconnectFromHost();
    void onRefreshData();
    void onCreateNewElement(const quint64 &timestamp, const quint8 &priority, const QString &description);

private slots:
    void onConnected();
    void onDisconnected();
    void onErrorOccured(const QString &errorText);

private:
    ETC_lib *client;
};

#endif // CLIENTCTRL_H
