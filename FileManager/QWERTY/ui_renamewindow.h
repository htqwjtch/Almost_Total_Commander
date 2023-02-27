/********************************************************************************
** Form generated from reading UI file 'renamewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEWINDOW_H
#define UI_RENAMEWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RenameWindow
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QLabel *label_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *name;
    QLabel *label;

    void setupUi(QDialog *RenameWindow)
    {
        if (RenameWindow->objectName().isEmpty())
            RenameWindow->setObjectName("RenameWindow");
        RenameWindow->resize(419, 161);
        RenameWindow->setMinimumSize(QSize(419, 161));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        RenameWindow->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(RenameWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 401, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 2, 1, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 2, 2, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName("groupBox");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-110, 0, 129, 57));
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 19, 391, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(gridLayoutWidget_2);
        name->setObjectName("name");

        gridLayout_2->addWidget(name, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 3);


        retranslateUi(RenameWindow);

        QMetaObject::connectSlotsByName(RenameWindow);
    } // setupUi

    void retranslateUi(QDialog *RenameWindow)
    {
        RenameWindow->setWindowTitle(QCoreApplication::translate("RenameWindow", "Dialog", nullptr));
        btnOK->setText(QCoreApplication::translate("RenameWindow", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("RenameWindow", "Cancel", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QString());
        label->setText(QCoreApplication::translate("RenameWindow", "  Enter Name: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RenameWindow: public Ui_RenameWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEWINDOW_H
