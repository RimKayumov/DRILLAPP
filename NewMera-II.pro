QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

RC_FILE = ico.rc

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    Converter.cpp \
    ParsysX.cpp \
    PipeParameters.cpp \
    logicModule.cpp \
    main.cpp \
    mainwindow.cpp \
    storeModule.cpp

HEADERS += \
    Converter.h \
    ParsysX.h \
    PipeParameters.h \
    WorkTimer.h \
    enumParameter.h \
    logicModule.h \
    mainwindow.h \
    storeModule.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    NewMera-II_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
