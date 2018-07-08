#-------------------------------------------------
#
# Project created by QtCreator 2018-07-04T11:34:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ETC_client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    clientctrl.cpp

HEADERS += \
        mainwindow.h \
    clientctrl.h

FORMS +=

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ETC_lib/release/ -lETC_lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ETC_lib/debug/ -lETC_lib
else:unix:!macx: LIBS += -L$$OUT_PWD/../ETC_lib/ -lETC_lib

INCLUDEPATH += $$PWD/../ETC_lib
DEPENDPATH += $$PWD/../ETC_lib
