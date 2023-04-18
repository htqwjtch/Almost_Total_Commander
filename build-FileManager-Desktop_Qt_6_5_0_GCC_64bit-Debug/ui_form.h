/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *btnCopy;
    QPushButton *btnCreate;
    QPushButton *btnRemove;
    QPushButton *btnReplace;
    QPushButton *btnRename;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLineEdit *leftPath;
    QLineEdit *rightPath;
    QHBoxLayout *horizontalLayout;
    QListView *lvLeft;
    QListView *lvRight;
    QGridLayout *gridLayout_3;
    QLabel *lblType;
    QLabel *lblDate;
    QLabel *lblSize;
    QGridLayout *gridLayout_4;
    QLineEdit *lineSearch;
    QLabel *enterName;
    QPushButton *btnSearch;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(880, 690);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btnCopy = new QPushButton(Form);
        btnCopy->setObjectName("btnCopy");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/png-transparent-paper-computer-icons-cut-copy-and-paste-symbol-user-interface-symbol-miscellaneous-angle-text-thumbnail-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCopy->setIcon(icon);
        btnCopy->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnCopy, 0, 2, 1, 1);

        btnCreate = new QPushButton(Form);
        btnCreate->setObjectName("btnCreate");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/2044254-200.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnCreate->setIcon(icon1);
        btnCreate->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnCreate, 0, 0, 1, 1);

        btnRemove = new QPushButton(Form);
        btnRemove->setObjectName("btnRemove");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/pngegg.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRemove->setIcon(icon2);
        btnRemove->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnRemove, 0, 1, 1, 1);

        btnReplace = new QPushButton(Form);
        btnReplace->setObjectName("btnReplace");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/1827319.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReplace->setIcon(icon3);
        btnReplace->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnReplace, 0, 3, 1, 1);

        btnRename = new QPushButton(Form);
        btnRename->setObjectName("btnRename");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/5261910.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRename->setIcon(icon4);
        btnRename->setIconSize(QSize(30, 30));

        gridLayout->addWidget(btnRename, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        label = new QLabel(Form);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        leftPath = new QLineEdit(Form);
        leftPath->setObjectName("leftPath");

        gridLayout_2->addWidget(leftPath, 0, 0, 1, 1);

        rightPath = new QLineEdit(Form);
        rightPath->setObjectName("rightPath");

        gridLayout_2->addWidget(rightPath, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lvLeft = new QListView(Form);
        lvLeft->setObjectName("lvLeft");

        horizontalLayout->addWidget(lvLeft);

        lvRight = new QListView(Form);
        lvRight->setObjectName("lvRight");

        horizontalLayout->addWidget(lvRight);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        lblType = new QLabel(Form);
        lblType->setObjectName("lblType");

        gridLayout_3->addWidget(lblType, 0, 1, 1, 1);

        lblDate = new QLabel(Form);
        lblDate->setObjectName("lblDate");

        gridLayout_3->addWidget(lblDate, 0, 0, 1, 1);

        lblSize = new QLabel(Form);
        lblSize->setObjectName("lblSize");

        gridLayout_3->addWidget(lblSize, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        lineSearch = new QLineEdit(Form);
        lineSearch->setObjectName("lineSearch");

        gridLayout_4->addWidget(lineSearch, 0, 1, 1, 1);

        enterName = new QLabel(Form);
        enterName->setObjectName("enterName");
        enterName->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(enterName, 0, 0, 1, 1);

        btnSearch = new QPushButton(Form);
        btnSearch->setObjectName("btnSearch");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSearch->setIcon(icon5);
        btnSearch->setIconSize(QSize(16, 16));

        gridLayout_4->addWidget(btnSearch, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        btnCopy->setText(QString());
#if QT_CONFIG(tooltip)
        btnCreate->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        btnCreate->setText(QString());
        btnRemove->setText(QString());
        btnReplace->setText(QString());
        btnRename->setText(QString());
        label->setText(QString());
        lblType->setText(QString());
        lblDate->setText(QString());
        lblSize->setText(QString());
        enterName->setText(QCoreApplication::translate("Form", "Enter name :", nullptr));
        btnSearch->setText(QCoreApplication::translate("Form", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
