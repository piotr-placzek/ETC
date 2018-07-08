#include "etc_lib.h"


ETC_lib::ETC_lib(const LibRole &role, QObject *parent) :
    QObject(parent),
    mainCtrl(0),
    _role(role)
{
    switch (_role) {
    case CLIENT:
        mainCtrl = new ETC_lib_ClientCtrl();
        break;
    case SERVER:
        mainCtrl = new ETC_lib_ServerCtrl();
        break;
    default:
        break;
    }

    if(mainCtrl!=0){
        connect(dynamic_cast<QObject*>(mainCtrl),SIGNAL(connected()),this,SIGNAL(connected()));
        connect(dynamic_cast<QObject*>(mainCtrl),SIGNAL(disconnected()),this,SIGNAL(disconnected()));
        connect(dynamic_cast<QObject*>(mainCtrl),SIGNAL(errorOccured(QString)),this,SIGNAL(errorOccured(QString)));
    }
}

void ETC_lib::start(const QString &hostAddress, const quint16 &port)
{
    Q_ASSERT_X(mainCtrl!=0, "ETC_lib::start()", "ETC_lib mainCtrl is null");
    mainCtrl->start(hostAddress,port);
}

void ETC_lib::stop()
{
    Q_ASSERT_X(mainCtrl!=0, "ETC_lib::stop()", "ETC_lib mainCtrl is null");
    mainCtrl->stop();
}

QString ETC_lib::currentHost()
{
    Q_ASSERT_X(mainCtrl!=0, "ETC_lib::currentHost()", "ETC_lib mainCtrl is null");
    return mainCtrl->currentHost();
}

quint16 ETC_lib::currentPort()
{
    Q_ASSERT_X(mainCtrl!=0, "ETC_lib::currentPort()", "ETC_lib mainCtrl is null");
    return mainCtrl->currentPort();
}
