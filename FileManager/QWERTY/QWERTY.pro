QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    .cpp/additionalwindow.cpp \
    .cpp/confirmdelete.cpp \
    .cpp/container.cpp \
    .cpp/createchoise.cpp \
    .cpp/mainwindow.cpp \
    .cpp/renamewindow.cpp \
    .cpp/searchwindow.cpp \
    .cpp/systemfiles.cpp \
    main.cpp

HEADERS += \
    .h/additionalwindow.h \
    .h/confirmdelete.h \
    .h/container.h \
    .h/createchoise.h \
    .h/exception.h \
    .h/mainwindow.h \
    .h/renamewindow.h \
    .h/searchwindow.h \
    .h/systemfiles.h

FORMS += \
    .ui/additionalwindow.ui \
    .ui/confirmdelete.ui \
    .ui/createchoise.ui \
    .ui/mainwindow.ui \
    .ui/renamewindow.ui \
    .ui/searchwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
