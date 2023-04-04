/********************************************************************************
** Form generated from reading UI file 'createchoise.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECHOISE_H
#define UI_CREATECHOISE_H

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

class Ui_CreateChoise
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QPushButton *btnFile;
    QPushButton *btnDir;
    QPushButton *btnSymLink;

    void setupUi(QDialog *CreateChoise)
    {
        if (CreateChoise->objectName().isEmpty())
            CreateChoise->setObjectName("CreateChoise");
        CreateChoise->resize(260, 267);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/w256h2561390727869addfile256.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateChoise->setWindowIcon(icon);
        gridLayoutWidget = new QWidget(CreateChoise);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 10, 241, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        btnCancel = new QPushButton(gridLayoutWidget);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 1, 1, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName("groupBox");
        btnFile = new QPushButton(groupBox);
        btnFile->setObjectName("btnFile");
        btnFile->setGeometry(QRect(20, 20, 201, 41));
        btnDir = new QPushButton(groupBox);
        btnDir->setObjectName("btnDir");
        btnDir->setGeometry(QRect(20, 80, 201, 41));
        btnSymLink = new QPushButton(groupBox);
        btnSymLink->setObjectName("btnSymLink");
        btnSymLink->setGeometry(QRect(20, 140, 201, 41));

        gridLayout->addWidget(groupBox, 0, 0, 1, 2);


        retranslateUi(CreateChoise);

        QMetaObject::connectSlotsByName(CreateChoise);
    } // setupUi

    void retranslateUi(QDialog *CreateChoise)
    {
        CreateChoise->setWindowTitle(QCoreApplication::translate("CreateChoise", "Dialog", nullptr));
        label->setText(QString());
        btnCancel->setText(QCoreApplication::translate("CreateChoise", "Cancel", nullptr));
        groupBox->setTitle(QString());
        btnFile->setText(QCoreApplication::translate("CreateChoise", "File", nullptr));
        btnDir->setText(QCoreApplication::translate("CreateChoise", "Directory", nullptr));
        btnSymLink->setText(QCoreApplication::translate("CreateChoise", "Symbol Link", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateChoise: public Ui_CreateChoise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECHOISE_H
