QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/modules/copyingModule/copyingmodule.cpp \
    src/modules/creatingModule/creatingmodule.cpp \
    src/modules/infoBarModule/infobarmodule.cpp \
    src/modules/mainModule/mainmodule.cpp \
    src/modules/namingModules/namingNotSymbolLinkModule/namingnotsymbollinkmodule.cpp \
    src/modules/namingModules/namingSymbolLinkModule/namingsymbollinkmodule.cpp \
    src/modules/namingModules/namingmodule.cpp \
    src/modules/navigationBarModule/navigationbarmodule.cpp \
    src/modules/removingModule/removingmodule.cpp \
    src/modules/replacingModule/replacingmodule.cpp \
    src/modules/searchingBarModule/searchingbarmodule.cpp \
    src/modules/searchingModule/searchingmodule.cpp \
    src/modules/toolBarModule/toolbarmodule.cpp \
    src/modules/viewingBarModule/viewingbarmodule.cpp \
    src/services/copyingService/copyingservice.cpp \
    src/services/creatingService/creatingservice.cpp \
    src/services/exceptionService/exceptionservice.cpp \
    src/services/removingService/removingservice.cpp \
    src/services/searchingService/searchingservice.cpp

HEADERS += \
    src/modules/copyingModule/copyingmodule.h \
    src/modules/creatingModule/creatingmodule.h \
    src/modules/infoBarModule/infobarmodule.h \
    src/modules/mainModule/mainmodule.h \
    src/modules/namingModules/namingNotSymbolLinkModule/namingnotsymbollinkmodule.h \
    src/modules/namingModules/namingSymbolLinkModule/namingsymbollinkmodule.h \
    src/modules/namingModules/namingmodule.h \
    src/modules/navigationBarModule/navigationbarmodule.h \
    src/modules/removingModule/removingmodule.h \
    src/modules/replacingModule/replacingmodule.h \
    src/modules/searchingBarModule/searchingbarmodule.h \
    src/modules/searchingModule/searchingmodule.h \
    src/modules/toolBarModule/toolbarmodule.h \
    src/modules/viewingBarModule/viewingbarmodule.h \
    src/services/copyingService/copyingservice.h \
    src/services/creatingService/creatingservice.h \
    src/services/exceptionService/exceptionservice.h \
    src/services/removingService/removingservice.h \
    src/services/searchingService/searchingservice.h

FORMS += \
    src/modules/creatingModule/creatingmodule.ui \
    src/modules/infoBarModule/infobarmodule.ui \
    src/modules/mainModule/mainmodule.ui \
    src/modules/namingModules/namingNotSymbolLinkModule/namingnotsymbollinkmodule.ui \
    src/modules/namingModules/namingSymbolLinkModule/namingsymbollinkmodule.ui \
    src/modules/navigationBarModule/navigationbarmodule.ui \
    src/modules/searchingBarModule/searchingbarmodule.ui \
    src/modules/searchingModule/searchingmodule.ui \
    src/modules/toolBarModule/toolbarmodule.ui \
    src/modules/viewingBarModule/viewingbarmodule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
