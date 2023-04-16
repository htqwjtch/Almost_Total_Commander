/********************************************************************************
** Form generated from reading UI file 'newname.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWNAME_H
#define UI_NEWNAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewName
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QWidget *widget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *name;
    QLabel *label_3;

    void setupUi(QDialog *NewName)
    {
        if (NewName->objectName().isEmpty())
            NewName->setObjectName("NewName");
        NewName->resize(400, 160);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        NewName->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(NewName);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(NewName);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnOK = new QPushButton(NewName);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 1, 2, 1, 1);

        btnCancel = new QPushButton(NewName);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 1, 1, 1);

        widget = new QWidget(NewName);
        widget->setObjectName("widget");
        gridLayoutWidget_2 = new QWidget(widget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(-1, 19, 381, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        name = new QLineEdit(gridLayoutWidget_2);
        name->setObjectName("name");

        gridLayout_2->addWidget(name, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(NewName);

        QMetaObject::connectSlotsByName(NewName);
    } // setupUi

    void retranslateUi(QDialog *NewName)
    {
        NewName->setWindowTitle(QCoreApplication::translate("NewName", "Dialog", nullptr));
        label->setText(QString());
        btnOK->setText(QCoreApplication::translate("NewName", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("NewName", "Cancel", nullptr));
        label_2->setText(QCoreApplication::translate("NewName", "Enter name :", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class NewName: public Ui_NewName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWNAME_H
