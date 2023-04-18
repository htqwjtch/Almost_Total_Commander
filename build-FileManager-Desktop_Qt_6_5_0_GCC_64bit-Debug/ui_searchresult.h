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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SearchResult
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QPushButton *btnOK;

    void setupUi(QDialog *SearchResult)
    {
        if (SearchResult->objectName().isEmpty())
            SearchResult->setObjectName("SearchResult");
        SearchResult->resize(450, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/kisspng-computer-icons-search-icon-5b30c8ad36d571.3385379615299237572246-removebg-preview.png"), QSize(), QIcon::Normal, QIcon::Off);
        SearchResult->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(SearchResult);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(SearchResult);
        listWidget->setObjectName("listWidget");

        horizontalLayout->addWidget(listWidget);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        btnOK = new QPushButton(SearchResult);
        btnOK->setObjectName("btnOK");

        gridLayout->addWidget(btnOK, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(SearchResult);

        QMetaObject::connectSlotsByName(SearchResult);
    } // setupUi

    void retranslateUi(QDialog *SearchResult)
    {
        SearchResult->setWindowTitle(QCoreApplication::translate("SearchResult", "Dialog", nullptr));
        btnOK->setText(QCoreApplication::translate("SearchResult", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchResult: public Ui_SearchResult {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHRESULT_H
