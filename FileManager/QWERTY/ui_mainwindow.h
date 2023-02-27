/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
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
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnRename;
    QPushButton *btnCopy;
    QLabel *label1;
    QPushButton *btnCreate;
    QPushButton *btnDelete;
    QPushButton *btnReplace;
    QLabel *label2;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QListView *lvSource;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *lineSearch;
    QPushButton *btnSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(734, 810);
        MainWindow->setMinimumSize(QSize(734, 810));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/png-clipart-computer-icons-file-explorer-internet-explorer-internet-explorer-blue-angle__2_-removebg-preview (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(24, 24));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(734, 767));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnRename = new QPushButton(groupBox);
        btnRename->setObjectName("btnRename");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRename->setIcon(icon1);
        btnRename->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnRename, 1, 4, 1, 1);

        btnCopy = new QPushButton(groupBox);
        btnCopy->setObjectName("btnCopy");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/png-transparent-paper-computer-icons-cut-copy-and-paste-symbol-user-interface-symbol-miscellaneous-angle-text-thumbnail-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCopy->setIcon(icon2);
        btnCopy->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnCopy, 1, 2, 1, 1);

        label1 = new QLabel(groupBox);
        label1->setObjectName("label1");

        gridLayout->addWidget(label1, 0, 0, 1, 5);

        btnCreate = new QPushButton(groupBox);
        btnCreate->setObjectName("btnCreate");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/w256h2561390727869addfile256.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCreate->setIcon(icon3);
        btnCreate->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnCreate, 1, 0, 1, 1);

        btnDelete = new QPushButton(groupBox);
        btnDelete->setObjectName("btnDelete");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/pngegg.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDelete->setIcon(icon4);
        btnDelete->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnDelete, 1, 1, 1, 1);

        btnReplace = new QPushButton(groupBox);
        btnReplace->setObjectName("btnReplace");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/1827319.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReplace->setIcon(icon5);
        btnReplace->setIconSize(QSize(32, 32));

        gridLayout->addWidget(btnReplace, 1, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label2 = new QLabel(groupBox);
        label2->setObjectName("label2");

        verticalLayout->addWidget(label2);

        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName("listWidget");
        listWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setMaximumSize(QSize(16777215, 24));

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lvSource = new QListView(groupBox);
        lvSource->setObjectName("lvSource");

        horizontalLayout->addWidget(lvSource);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(-1, 0, -1, -1);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 0, 2, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        gridLayout_3->addWidget(label_4, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(84, 24));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineSearch = new QLineEdit(groupBox);
        lineSearch->setObjectName("lineSearch");

        gridLayout_2->addWidget(lineSearch, 0, 1, 1, 2);

        btnSearch = new QPushButton(groupBox);
        btnSearch->setObjectName("btnSearch");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon6);
        btnSearch->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(btnSearch, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        horizontalLayout_2->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 734, 21));
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
        btnRename->setText(QString());
        btnCopy->setText(QString());
        label1->setText(QString());
        btnCreate->setText(QString());
        btnDelete->setText(QString());
        btnReplace->setText(QString());
        label2->setText(QString());
        label_5->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", " Enter name:", nullptr));
        btnSearch->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
