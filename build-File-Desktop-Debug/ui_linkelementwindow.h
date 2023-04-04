/********************************************************************************
** Form generated from reading UI file 'linkelementwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKELEMENTWINDOW_H
#define UI_LINKELEMENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkElementWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *path;

    void setupUi(QDialog *LinkElementWindow)
    {
        if (LinkElementWindow->objectName().isEmpty())
            LinkElementWindow->setObjectName("LinkElementWindow");
        LinkElementWindow->resize(419, 161);
        gridLayoutWidget = new QWidget(LinkElementWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 9, 401, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 1, 1, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName("groupBox");
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 20, 391, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        path = new QLineEdit(gridLayoutWidget_2);
        path->setObjectName("path");

        gridLayout_2->addWidget(path, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);


        retranslateUi(LinkElementWindow);

        QMetaObject::connectSlotsByName(LinkElementWindow);
    } // setupUi

    void retranslateUi(QDialog *LinkElementWindow)
    {
        LinkElementWindow->setWindowTitle(QCoreApplication::translate("LinkElementWindow", "Dialog", nullptr));
        btnOK->setText(QCoreApplication::translate("LinkElementWindow", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("LinkElementWindow", "Cancel", nullptr));
        label->setText(QString());
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("LinkElementWindow", "   Enter path :", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinkElementWindow: public Ui_LinkElementWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKELEMENTWINDOW_H
