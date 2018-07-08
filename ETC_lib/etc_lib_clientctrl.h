#ifndef ETC_LIB_CLIENTCTRL_H
#define ETC_LIB_CLIENTCTRL_H


#include "abstract_etc_lib_sidectrl.h"

class ETC_lib_ClientCtrl : public Abstract_ETC_lib_SideCtrl
{
public:
    ETC_lib_ClientCtrl();

    // Abstract_ETC_lib_SideCtrl interface
public:
    void start(const QString &hostAddress, const quint16 &port);
    void stop();
    QString currentHost();
    quint16 currentPort();

signals:
    void connected();
    void disconnected();
    void errorOccured(const QString &errorText);
};

#endif // ETC_LIB_CLIENTCTRL_H
