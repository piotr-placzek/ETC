#ifndef ABSTRACT_ETC_LIB_H
#define ABSTRACT_ETC_LIB_H

#include <QObject>
#include "abstract_etc_lib_sidectrl.h"

class Abstract_ETC_lib : public Abstract_ETC_lib_SideCtrl{
public:
    enum LibRole{CLIENT, SERVER};
};

#endif // ABSTRACT_ETC_LIB_H
