/********************************************************************************
** Form generated from reading UI file 'additionalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITIONALWINDOW_H
#define UI_ADDITIONALWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdditionalWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QListView *listView;
    QPushButton *btnOK;
    QLabel *label;
    QPushButton *btnCancel;
    QLabel *label_2;

    void setupUi(QDialog *AdditionalWindow)
    {
        if (AdditionalWindow->objectName().isEmpty())
            AdditionalWindow->setObjectName("AdditionalWindow");
        AdditionalWindow->resize(572, 526);
        AdditionalWindow->setMinimumSize(QSize(572, 526));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/png-clipart-computer-icons-file-explorer-internet-explorer-internet-explorer-blue-angle__2_-removebg-preview (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        AdditionalWindow->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(AdditionalWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 551, 501));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        listView = new QListView(gridLayoutWidget);
        listView->setObjectName("listView");

        gridLayout->addWidget(listView, 0, 0, 1, 3);

        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 3);


        retranslateUi(AdditionalWindow);

        QMetaObject::connectSlotsByName(AdditionalWindow);
    } // setupUi

    void retranslateUi(QDialog *AdditionalWindow)
    {
        AdditionalWindow->setWindowTitle(QCoreApplication::translate("AdditionalWindow", "Dialog", nullptr));
        btnOK->setText(QCoreApplication::translate("AdditionalWindow", "OK", nullptr));
        label->setText(QString());
        btnCancel->setText(QCoreApplication::translate("AdditionalWindow", "Cancel", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdditionalWindow: public Ui_AdditionalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITIONALWINDOW_H
