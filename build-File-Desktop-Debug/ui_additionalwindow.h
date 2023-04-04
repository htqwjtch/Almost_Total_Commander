/********************************************************************************
** Form generated from reading UI file 'additionalwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDITIONALWINDOW_H
#define UI_ADDITIONALWINDOW_H

#include <QtCore/QVariant>
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
    QPushButton *btnCancel;
    QPushButton *btnOK;
    QLabel *label;
    QListView *listView;

    void setupUi(QDialog *AdditionalWindow)
    {
        if (AdditionalWindow->objectName().isEmpty())
            AdditionalWindow->setObjectName("AdditionalWindow");
        AdditionalWindow->resize(551, 536);
        gridLayoutWidget = new QWidget(AdditionalWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 531, 511));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 2, 2, 1, 1);

        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        listView = new QListView(gridLayoutWidget);
        listView->setObjectName("listView");

        gridLayout->addWidget(listView, 0, 0, 1, 3);


        retranslateUi(AdditionalWindow);

        QMetaObject::connectSlotsByName(AdditionalWindow);
    } // setupUi

    void retranslateUi(QDialog *AdditionalWindow)
    {
        AdditionalWindow->setWindowTitle(QCoreApplication::translate("AdditionalWindow", "Dialog", nullptr));
        btnCancel->setText(QCoreApplication::translate("AdditionalWindow", "Cancel", nullptr));
        btnOK->setText(QCoreApplication::translate("AdditionalWindow", "OK", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdditionalWindow: public Ui_AdditionalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDITIONALWINDOW_H
