QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    apartment.cpp \
    apartmentpanel.cpp \
    base.cpp \
    date.cpp \
    dossier.cpp \
    house.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    nuser.cpp \
    nvilla.cpp \
    rentdossier.cpp \
    rentdosspanel.cpp \
    request.cpp \
    requestpanel.cpp \
    selldossier.cpp \
    selldosspanel.cpp \
    signup.cpp \
    svilla.cpp \
    unit.cpp \
    unitpanel.cpp \
    user.cpp \
    villa.cpp \
    villapanel.cpp

HEADERS += \
    apartment.h \
    apartmentpanel.h \
    base.h \
    date.h \
    dossier.h \
    house.h \
    login.h \
    mainwindow.h \
    manager.h \
    nuser.h \
    nvilla.h \
    rentdossier.h \
    rentdosspanel.h \
    request.h \
    requestpanel.h \
    selldossier.h \
    selldosspanel.h \
    signup.h \
    svilla.h \
    ui_login.h \
    ui_signup.h \
    unit.h \
    unitpanel.h \
    user.h \
    villa.h \
    villapanel.h

FORMS += \
    apartmentpanel.ui \
    login.ui \
    rentdosspanel.ui \
    requestpanel.ui \
    selldosspanel.ui \
    signup.ui \
    unitpanel.ui \
    villapanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
