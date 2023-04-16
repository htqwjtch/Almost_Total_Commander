/********************************************************************************
** Form generated from reading UI file 'searchresult.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHRESULT_H
#define UI_SEARCHRESULT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchResult
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnOK;
    QListWidget *listWidget;

    void setupUi(QDialog *SearchResult)
    {
        if (SearchResult->objectName().isEmpty())
            SearchResult->setObjectName("SearchResult");
        SearchResult->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        SearchResult->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SearchResult);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(SearchResult);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_2 = new QLabel(SearchResult);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        btnOK = new QPushButton(SearchResult);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 1, 2, 1, 1);

        listWidget = new QListWidget(SearchResult);
        listWidget->setObjectName("listWidget");

        gridLayout->addWidget(listWidget, 0, 0, 1, 3);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(SearchResult);

        QMetaObject::connectSlotsByName(SearchResult);
    } // setupUi

    void retranslateUi(QDialog *SearchResult)
    {
        SearchResult->setWindowTitle(QCoreApplication::translate("SearchResult", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        btnOK->setText(QCoreApplication::translate("SearchResult", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchResult: public Ui_SearchResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULT_H
