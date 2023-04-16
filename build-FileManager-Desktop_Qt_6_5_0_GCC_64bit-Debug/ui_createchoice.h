/********************************************************************************
** Form generated from reading UI file 'createchoice.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECHOICE_H
#define UI_CREATECHOICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateChoice
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnCancel;
    QWidget *widget;
    QPushButton *btnFile;
    QPushButton *btnDir;
    QPushButton *btnLink;

    void setupUi(QDialog *CreateChoice)
    {
        if (CreateChoice->objectName().isEmpty())
            CreateChoice->setObjectName("CreateChoice");
        CreateChoice->resize(300, 250);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/2044254-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateChoice->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(CreateChoice);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(CreateChoice);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 1);

        label_2 = new QLabel(CreateChoice);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        btnCancel = new QPushButton(CreateChoice);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 2, 1, 1);

        widget = new QWidget(CreateChoice);
        widget->setObjectName("widget");
        btnFile = new QPushButton(widget);
        btnFile->setObjectName("btnFile");
        btnFile->setGeometry(QRect(40, 20, 210, 40));
        btnDir = new QPushButton(widget);
        btnDir->setObjectName("btnDir");
        btnDir->setGeometry(QRect(40, 80, 210, 40));
        btnLink = new QPushButton(widget);
        btnLink->setObjectName("btnLink");
        btnLink->setGeometry(QRect(40, 140, 210, 40));

        gridLayout->addWidget(widget, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(CreateChoice);

        QMetaObject::connectSlotsByName(CreateChoice);
    } // setupUi

    void retranslateUi(QDialog *CreateChoice)
    {
        CreateChoice->setWindowTitle(QCoreApplication::translate("CreateChoice", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        btnCancel->setText(QCoreApplication::translate("CreateChoice", "Cancel", nullptr));
        btnFile->setText(QCoreApplication::translate("CreateChoice", "File", nullptr));
        btnDir->setText(QCoreApplication::translate("CreateChoice", "Directory", nullptr));
        btnLink->setText(QCoreApplication::translate("CreateChoice", "Symbol Link", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateChoice: public Ui_CreateChoice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECHOICE_H
