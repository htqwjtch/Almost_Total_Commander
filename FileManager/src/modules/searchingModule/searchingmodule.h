#ifndef SEARCHINGMODULE_H
#define SEARCHINGMODULE_H

#include "../../services/searchingService/searchingservice.h"

#include <QClipboard>
#include <QDialog>
#include <QListWidgetItem>
#include <QStringList>

namespace Ui
{
    class SearchingModule;
}

class SearchingModule : public QDialog
{
    Q_OBJECT

public:
    SearchingModule(QWidget* parent = nullptr);
    ~SearchingModule();
    void search();
    void setCurrentDirectoryPath(const QString&);
    void setSearchingName(const QString&);

private:
    void setUserInterface();
    void clearSearchingResultWidget();

private slots:
    void fillSearchingResultWidget(QStringList);
    void on_searchingResultWidget_itemClicked(QListWidgetItem* item);
    void on_okButton_clicked();

private:
    Ui::SearchingModule* ui;
    QThread* threadForSearching;
    SearchingService* searchingService;
    QString currentDirectoryPath = "";
    QString searchingName = "";

signals:
    void startSearching(QString, QString);
    void searchingFinished();
};

#endif // SEARCHINGMODULE_H
