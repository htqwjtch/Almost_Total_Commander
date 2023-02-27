/********************************************************************************
** Form generated from reading UI file 'confirmdelete.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDELETE_H
#define UI_CONFIRMDELETE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDelete
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label;
    QPushButton *btnOK;

    void setupUi(QDialog *ConfirmDelete)
    {
        if (ConfirmDelete->objectName().isEmpty())
            ConfirmDelete->setObjectName("ConfirmDelete");
        ConfirmDelete->resize(400, 141);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/pngegg.png"), QSize(), QIcon::Normal, QIcon::Off);
        ConfirmDelete->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(ConfirmDelete);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 381, 121));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 2, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName("groupBox");
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 341, 20));

        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnOK = new QPushButton(gridLayoutWidget);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 1, 1, 1, 1);


        retranslateUi(ConfirmDelete);

        QMetaObject::connectSlotsByName(ConfirmDelete);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDelete)
    {
        ConfirmDelete->setWindowTitle(QCoreApplication::translate("ConfirmDelete", "Dialog", nullptr));
        btnCancel->setText(QCoreApplication::translate("ConfirmDelete", "Cancel", nullptr));
        groupBox->setTitle(QString());
        label_2->setText(QCoreApplication::translate("ConfirmDelete", "            Do you want to perform <<Delete>> operation?", nullptr));
        label->setText(QString());
        btnOK->setText(QCoreApplication::translate("ConfirmDelete", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDelete: public Ui_ConfirmDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDELETE_H
