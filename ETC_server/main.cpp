#include <QCoreApplication>
#include "serverctrl.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ServerCtrl sCtrl;
    return a.exec();
}
