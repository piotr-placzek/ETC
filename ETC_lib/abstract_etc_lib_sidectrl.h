#ifndef ABSTRACT_ETC_LIB_SIDECTRL_H
#define ABSTRACT_ETC_LIB_SIDECTRL_H

#include <QObject>

class Abstract_ETC_lib_SideCtrl{
  public:
    virtual void start(const QString &hostAddress, const quint16 &port) = 0;
    virtual void stop() = 0;
    virtual QString currentHost() = 0;
    virtual quint16 currentPort() = 0;

signals:
    virtual void connected() = 0;
    virtual void disconnected() = 0;
    virtual void errorOccured(const QString &errorText) = 0;
};
#endif // ABSTRACT_ETC_LIB_SIDECTRL_H
