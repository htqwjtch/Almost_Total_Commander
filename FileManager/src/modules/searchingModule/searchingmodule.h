#ifndef SEARCHINGMODULE_H
#define SEARCHINGMODULE_H

#include "../../services/searchingService/searchingservice.h"

#include <QClipboard>
#include <QDialog>
#include <QListWidgetItem>
#include <QStringList>
#include <QThread>

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
    void search(const QString&, const QString&);

private:
    void setUserInterface();
    void allocateMemory();
    void connectSignalsWithSlots();
    void setThreadForSearching();
    void clearSearchingResultWidget();

private slots:
    void fillSearchingResultWidget(QStringList);
    void on_searchingResultWidget_itemClicked(QListWidgetItem* item);
    void on_okButton_clicked();

private:
    Ui::SearchingModule* ui;
    SearchingService* searchingService;
    QThread* threadForSearching;

signals:
    void startSearchingSignal(QString, QString);
    void searchingCompletedSignal();
};

#endif // SEARCHINGMODULE_H
