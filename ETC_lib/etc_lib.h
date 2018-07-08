#ifndef ETC_LIB_H
#define ETC_LIB_H

#include "abstract_etc_lib.h"
#include "abstract_etc_lib_sidectrl.h"
#include "etc_lib_global.h"
#include "etc_lib_serverctrl.h"
#include "etc_lib_clientctrl.h"

class ETC_LIBSHARED_EXPORT ETC_lib : public QObject, public Abstract_ETC_lib
{
    Q_OBJECT
public:
    // Abstract_ETC_lib interface
    ETC_lib(const LibRole &role, QObject *parent = nullptr);
    // Abstract_ETC_lib_SideCtrl interface
    void start(const QString &hostAddress, const quint16 &port);
    void stop();
    QString currentHost();
    quint16 currentPort();

signals:
    // Abstract_ETC_lib_SideCtrl interface
    void connected();
    void disconnected();
    void errorOccured(const QString &errorText);

private:
    Abstract_ETC_lib_SideCtrl *mainCtrl;
    LibRole _role;
};

#endif // ETC_LIB_H
