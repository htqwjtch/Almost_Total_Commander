QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additionalwindow.cpp \
    confirmdelete.cpp \
    container.cpp \
    createchoice.cpp \
    linkedpathwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    renamewindow.cpp \
    searchwindow.cpp \
    systemfiles.cpp

HEADERS += \
    additionalwindow.h \
    confirmdelete.h \
    container.h \
    createchoice.h \
    exception.h \
    linkedpathwindow.h \
    mainwindow.h \
    renamewindow.h \
    searchwindow.h \
    systemfiles.h

FORMS += \
    additionalwindow.ui \
    confirmdelete.ui \
    createchoice.ui \
    linkedpathwindow.ui \
    mainwindow.ui \
    renamewindow.ui \
    searchwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    resources/1827319.png \
    resources/2044254-200.png \
    resources/5261910.png \
    resources/gratis-png-formato-de-archivo-de-documento-iconos-de-computadora-hoja-de-papel-removebg-preview.png \
    resources/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png \
    resources/png-clipart-computer-icons-file-explorer-internet-explorer-internet-explorer-blue-angle__2_-removebg-preview (1).png \
    resources/png-transparent-paper-computer-icons-cut-copy-and-paste-symbol-user-interface-symbol-miscellaneous-angle-text-thumbnail-removebg-preview.png \
    resources/pngegg.png \
    resources/w256h2561390727869addfile256.png
