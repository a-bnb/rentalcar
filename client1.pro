QT       += core gui sql network

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
    chat.cpp \
    contdata.cpp \
    content.cpp \
    main.cpp \
    login.cpp \
    mainpage.cpp \
    member.cpp \
    rentalcar.cpp \
    rentalcar_.cpp \
    reserv_.cpp \
    reservation.cpp \
    resr_add.cpp \
    signup.cpp \
    thread.cpp \
    user.cpp

HEADERS += \
    chat.h \
    contdata.h \
    content.h \
    database.h \
    login.h \
    mainpage.h \
    member.h \
    rentalcar.h \
    rentalcar_.h \
    reserv_.h \
    reservation.h \
    resr_add.h \
    signup.h \
    tcp.h \
    thread.h \
    user.h

FORMS += \
    chat.ui \
    contdata.ui \
    content.ui \
    login.ui \
    mainpage.ui \
    member.ui \
    rentalcar.ui \
    rentalcar_.ui \
    reserv_.ui \
    reservation.ui \
    resr_add.ui \
    signup.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    client1.pro.user \
    client1.pro.user.4.8-pre1
