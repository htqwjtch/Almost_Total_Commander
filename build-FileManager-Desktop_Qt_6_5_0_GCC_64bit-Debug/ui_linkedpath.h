/********************************************************************************
** Form generated from reading UI file 'linkedpath.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKEDPATH_H
#define UI_LINKEDPATH_H

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

class Ui_LinkedPath
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnCancel;
    QPushButton *btnOK;
    QWidget *widget;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *path;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *LinkedPath)
    {
        if (LinkedPath->objectName().isEmpty())
            LinkedPath->setObjectName("LinkedPath");
        LinkedPath->resize(400, 160);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        LinkedPath->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(LinkedPath);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(LinkedPath);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnCancel = new QPushButton(LinkedPath);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 1, 1, 1);

        btnOK = new QPushButton(LinkedPath);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 1, 2, 1, 1);

        widget = new QWidget(LinkedPath);
        widget->setObjectName("widget");
        gridLayoutWidget_2 = new QWidget(widget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(-1, 19, 381, 61));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        path = new QLineEdit(gridLayoutWidget_2);
        path->setObjectName("path");

        gridLayout_2->addWidget(path, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 2, 1, 1);


        gridLayout->addWidget(widget, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(LinkedPath);

        QMetaObject::connectSlotsByName(LinkedPath);
    } // setupUi

    void retranslateUi(QDialog *LinkedPath)
    {
        LinkedPath->setWindowTitle(QCoreApplication::translate("LinkedPath", "Dialog", nullptr));
        label->setText(QString());
        btnCancel->setText(QCoreApplication::translate("LinkedPath", "Cancel", nullptr));
        btnOK->setText(QCoreApplication::translate("LinkedPath", "OK", nullptr));
        label_2->setText(QCoreApplication::translate("LinkedPath", "Enter path :", nullptr));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LinkedPath: public Ui_LinkedPath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKEDPATH_H
