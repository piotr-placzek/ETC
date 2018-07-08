#ifndef ETC_LIB_GLOBAL_H
#define ETC_LIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ETC_LIB_LIBRARY)
#  define ETC_LIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ETC_LIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ETC_LIB_GLOBAL_H
