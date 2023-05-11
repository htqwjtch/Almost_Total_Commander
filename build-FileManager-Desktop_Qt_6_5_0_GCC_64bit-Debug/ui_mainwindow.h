/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *CtrlN;
    QAction *CtrlDel;
    QAction *CtrlC;
    QAction *CtrlX;
    QAction *CtrlR;
    QAction *CtrlT;
    QAction *CtrlD;
    QAction *CtrlLeft;
    QAction *CtrlRight;
    QAction *CtrlEsc;
    QAction *CtrlF;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 800);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png-clipart-computer-icons-file-explorer-internet-explorer-internet-explorer-blue-angle__2_-removebg-preview (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        CtrlN = new QAction(MainWindow);
        CtrlN->setObjectName("CtrlN");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2044254-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlN->setIcon(icon1);
        CtrlDel = new QAction(MainWindow);
        CtrlDel->setObjectName("CtrlDel");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pngegg.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlDel->setIcon(icon2);
        CtrlC = new QAction(MainWindow);
        CtrlC->setObjectName("CtrlC");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/png-transparent-paper-computer-icons-cut-copy-and-paste-symbol-user-interface-symbol-miscellaneous-angle-text-thumbnail-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlC->setIcon(icon3);
        CtrlX = new QAction(MainWindow);
        CtrlX->setObjectName("CtrlX");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/1827319.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlX->setIcon(icon4);
        CtrlR = new QAction(MainWindow);
        CtrlR->setObjectName("CtrlR");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlR->setIcon(icon5);
        CtrlT = new QAction(MainWindow);
        CtrlT->setObjectName("CtrlT");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/png-transparent-creative-commons-license-copyright-symbol-attribution-copyright-trademark-words-phrases-wikimedia-commons-thumbnail-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlT->setIcon(icon6);
        CtrlD = new QAction(MainWindow);
        CtrlD->setObjectName("CtrlD");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/png-transparent-cancel-delete-remove-close-cross-circle-ink-alert-icon-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlD->setIcon(icon7);
        CtrlLeft = new QAction(MainWindow);
        CtrlLeft->setObjectName("CtrlLeft");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/77-773183_left-arrow-comments-instagram-plus-icon-png-transparent-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlLeft->setIcon(icon8);
        CtrlRight = new QAction(MainWindow);
        CtrlRight->setObjectName("CtrlRight");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlRight->setIcon(icon9);
        CtrlEsc = new QAction(MainWindow);
        CtrlEsc->setObjectName("CtrlEsc");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/pngimg.com - exit_PNG42.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlEsc->setIcon(icon10);
        CtrlF = new QAction(MainWindow);
        CtrlF->setObjectName("CtrlF");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        CtrlF->setIcon(icon11);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabsClosable(true);
        tab = new QWidget();
        tab->setObjectName("tab");
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuInfo->menuAction());
        menuInfo->addAction(CtrlN);
        menuInfo->addAction(CtrlDel);
        menuInfo->addAction(CtrlC);
        menuInfo->addAction(CtrlX);
        menuInfo->addAction(CtrlR);
        menuInfo->addAction(CtrlF);
        menuInfo->addAction(CtrlT);
        menuInfo->addAction(CtrlD);
        menuInfo->addAction(CtrlLeft);
        menuInfo->addAction(CtrlRight);
        menuInfo->addAction(CtrlEsc);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        CtrlN->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
#if QT_CONFIG(tooltip)
        CtrlN->setToolTip(QCoreApplication::translate("MainWindow", "Create", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        CtrlN->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlDel->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
#if QT_CONFIG(tooltip)
        CtrlDel->setToolTip(QCoreApplication::translate("MainWindow", "Remove", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        CtrlDel->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Del", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlC->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        CtrlC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlX->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
#if QT_CONFIG(shortcut)
        CtrlX->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlR->setText(QCoreApplication::translate("MainWindow", "Rename", nullptr));
#if QT_CONFIG(shortcut)
        CtrlR->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlT->setText(QCoreApplication::translate("MainWindow", "Add Tab", nullptr));
#if QT_CONFIG(shortcut)
        CtrlT->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+T", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlD->setText(QCoreApplication::translate("MainWindow", "Close Tab", nullptr));
#if QT_CONFIG(shortcut)
        CtrlD->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlLeft->setText(QCoreApplication::translate("MainWindow", "Tab before", nullptr));
#if QT_CONFIG(shortcut)
        CtrlLeft->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Left", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlRight->setText(QCoreApplication::translate("MainWindow", "Tab after", nullptr));
#if QT_CONFIG(shortcut)
        CtrlRight->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Right", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlEsc->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        CtrlEsc->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Esc", nullptr));
#endif // QT_CONFIG(shortcut)
        CtrlF->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
#if QT_CONFIG(shortcut)
        CtrlF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        tabWidget->setTabText(tabWidget->indexOf(tab), QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QString());
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
