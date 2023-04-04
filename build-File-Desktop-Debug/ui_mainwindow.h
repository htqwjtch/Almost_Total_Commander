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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btnCreate;
    QPushButton *btnCopy;
    QPushButton *btnDelete;
    QPushButton *btnRename;
    QPushButton *btnReplace;
    QGroupBox *groupBox_2;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QListView *lvSource;
    QGridLayout *gridLayout_3;
    QLabel *lblSize;
    QLabel *lblDate;
    QLabel *lblType;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(716, 742);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png-clipart-computer-icons-file-explorer-internet-explorer-internet-explorer-blue-angle__2_-removebg-preview (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnCreate = new QPushButton(groupBox);
        btnCreate->setObjectName("btnCreate");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2044254-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCreate->setIcon(icon1);
        btnCreate->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnCreate, 0, 0, 1, 1);

        btnCopy = new QPushButton(groupBox);
        btnCopy->setObjectName("btnCopy");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/png-transparent-paper-computer-icons-cut-copy-and-paste-symbol-user-interface-symbol-miscellaneous-angle-text-thumbnail-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCopy->setIcon(icon2);
        btnCopy->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnCopy, 0, 2, 1, 1);

        btnDelete = new QPushButton(groupBox);
        btnDelete->setObjectName("btnDelete");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/pngegg.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelete->setIcon(icon3);
        btnDelete->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnDelete, 0, 1, 1, 1);

        btnRename = new QPushButton(groupBox);
        btnRename->setObjectName("btnRename");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRename->setIcon(icon4);
        btnRename->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnRename, 0, 4, 1, 1);

        btnReplace = new QPushButton(groupBox);
        btnReplace->setObjectName("btnReplace");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/1827319.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReplace->setIcon(icon5);
        btnReplace->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnReplace, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        listWidget = new QListWidget(groupBox_2);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 0, 674, 36));

        verticalLayout_2->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lvSource = new QListView(groupBox);
        lvSource->setObjectName("lvSource");

        horizontalLayout->addWidget(lvSource);


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        lblSize = new QLabel(groupBox);
        lblSize->setObjectName("lblSize");

        gridLayout_3->addWidget(lblSize, 0, 2, 1, 1);

        lblDate = new QLabel(groupBox);
        lblDate->setObjectName("lblDate");

        gridLayout_3->addWidget(lblDate, 0, 0, 1, 1);

        lblType = new QLabel(groupBox);
        lblType->setObjectName("lblType");

        gridLayout_3->addWidget(lblType, 0, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineSearch = new QLineEdit(groupBox);
        lineSearch->setObjectName("lineSearch");

        gridLayout_2->addWidget(lineSearch, 0, 1, 1, 1);

        btnSearch = new QPushButton(groupBox);
        btnSearch->setObjectName("btnSearch");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon6);
        btnSearch->setIconSize(QSize(20, 20));

        gridLayout_2->addWidget(btnSearch, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 716, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        btnCreate->setText(QString());
        btnCopy->setText(QString());
        btnDelete->setText(QString());
        btnRename->setText(QString());
        btnReplace->setText(QString());
        groupBox_2->setTitle(QString());
        lblSize->setText(QString());
        lblDate->setText(QString());
        lblType->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "   Enter name:", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
