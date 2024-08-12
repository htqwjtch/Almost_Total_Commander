QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form/form.cpp \
    linkedPath/linkedpath.cpp \
    main.cpp \
    mainWindow/mainwindow.cpp \
    newName/newname.cpp \
    searchResult/searchresult.cpp \
    src/modules/creatingModule/creatingmodule.cpp \
    src/modules/namingModule/namingNotSymbolLinkModule/namingnotsymbollinkmodule.cpp \
    src/modules/namingModule/namingSymbolLinkModule/namingsymbollinkmodule.cpp \
    src/modules/namingModule/namingmodule.cpp \
    sysElem/syselem.cpp \
    thToCopy/threadtocpy.cpp \
    thToRemove/threadtoremove.cpp \
    thToReplace/threadtoreplace.cpp \
    thToSearch/threadtosearch.cpp

HEADERS += \
    form/form.h \
    form/other_functions.h \
    linkedPath/linkedpath.h \
    mainWindow/mainwindow.h \
    newName/newname.h \
    searchResult/searchresult.h \
    src/localException/localexception.h \
    src/modules/creatingModule/creatingmodule.h \
    src/modules/namingModule/namingNotSymbolLinkModule/namingnotsymbollinkmodule.h \
    src/modules/namingModule/namingSymbolLinkModule/namingsymbollinkmodule.h \
    src/modules/namingModule/namingmodule.h \
    sysElem/syselem.h \
    thToCopy/threadtocpy.h \
    thToRemove/threadtoremove.h \
    thToReplace/threadtoreplace.h \
    thToSearch/threadtosearch.h

FORMS += \
    form/form.ui \
    linkedPath/linkedpath.ui \
    mainWindow/mainwindow.ui \
    newName/newname.ui \
    searchResult/searchresult.ui \
    src/modules/creatingModule/creationmodule.ui \
    src/modules/namingModule/namingNotSymbolLinkModule/namingnotsymbollinkmodule.ui \
    src/modules/namingModule/namingSymbolLinkModule/namingsymbollinkmodule.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc
