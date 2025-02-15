QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addproductwindow.cpp \
    addshopwindow.cpp \
    connection.cpp \
    deleteproductwindow.cpp \
    deleteshopwindow.cpp \
    findproductwindow.cpp \
    findshopwindow.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp

HEADERS += \
    addproductwindow.h \
    addshopwindow.h \
    connection.h \
    deleteproductwindow.h \
    deleteshopwindow.h \
    findproductwindow.h \
    findshopwindow.h \
    header.h \
    mainmenu.h \
    mainwindow.h

FORMS += \
    addproductwindow.ui \
    addshopwindow.ui \
    deleteproductwindow.ui \
    deleteshopwindow.ui \
    findproductwindow.ui \
    findshopwindow.ui \
    mainmenu.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resour.qrc
