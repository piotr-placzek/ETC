#ifndef SERVERCTLR_H
#define SERVERCTLR_H

#include <QObject>
#include <QDebug>
#include "etc_lib.h"

class ServerCtrl : public QObject
{
    Q_OBJECT
public:
    explicit ServerCtrl(QObject *parent = nullptr);

signals:

public slots:

private slots:
    // Abstract_ETC_lib_SideCtrl interface
    void onConnected();
    void onDisconnected();
    void onErrorOccured(const QString &errorText);

private:
    ETC_lib *server;
};

#endif // SERVERCTLR_H
