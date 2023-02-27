/********************************************************************************
** Form generated from reading UI file 'createchoise.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateChoise
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnFile;
    QPushButton *btnFolder;
    QLabel *label;
    QPushButton *btnCancel;
    QLabel *label_2;

    void setupUi(QDialog *CreateChoise)
    {
        if (CreateChoise->objectName().isEmpty())
            CreateChoise->setObjectName("CreateChoise");
        CreateChoise->resize(260, 198);
        CreateChoise->setMinimumSize(QSize(260, 198));
        CreateChoise->setMaximumSize(QSize(260, 198));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/w256h2561390727869addfile256.png"), QSize(), QIcon::Normal, QIcon::Off);
        CreateChoise->setWindowIcon(icon);
        gridLayout = new QGridLayout(CreateChoise);
        gridLayout->setObjectName("gridLayout");
        groupBox = new QGroupBox(CreateChoise);
        groupBox->setObjectName("groupBox");
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        btnFile = new QPushButton(groupBox);
        btnFile->setObjectName("btnFile");
        btnFile->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(btnFile);

        btnFolder = new QPushButton(groupBox);
        btnFolder->setObjectName("btnFolder");
        btnFolder->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(btnFolder);


        gridLayout->addWidget(groupBox, 0, 0, 1, 2);

        label = new QLabel(CreateChoise);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        btnCancel = new QPushButton(CreateChoise);
        btnCancel->setObjectName("btnCancel");

        gridLayout->addWidget(btnCancel, 2, 1, 1, 1);

        label_2 = new QLabel(CreateChoise);
        label_2->setObjectName("label_2");
        label_2->setMaximumSize(QSize(300, 30));

        gridLayout->addWidget(label_2, 1, 0, 1, 2);


        retranslateUi(CreateChoise);

        QMetaObject::connectSlotsByName(CreateChoise);
    } // setupUi

    void retranslateUi(QDialog *CreateChoise)
    {
        CreateChoise->setWindowTitle(QCoreApplication::translate("CreateChoise", "Dialog", nullptr));
        groupBox->setTitle(QString());
        btnFile->setText(QCoreApplication::translate("CreateChoise", "File", nullptr));
        btnFolder->setText(QCoreApplication::translate("CreateChoise", "Directory", nullptr));
        label->setText(QString());
        btnCancel->setText(QCoreApplication::translate("CreateChoise", "Cancel", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateChoise: public Ui_CreateChoise {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECHOISE_H
