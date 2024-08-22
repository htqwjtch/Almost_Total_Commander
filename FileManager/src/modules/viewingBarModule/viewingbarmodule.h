#ifndef VIEWINGBARMODULE_H
#define VIEWINGBARMODULE_H

#include "../../services/exceptionService/exceptionservice.h"

#include <QDesktopServices>
#include <QFileSystemModel>
#include <QTableView>
#include <QUrl>
#include <QWidget>

namespace Ui
{
    class ViewingBarModule;
}

class ViewingBarModule : public QWidget
{
    Q_OBJECT

public:
    explicit ViewingBarModule(QWidget* parent = nullptr);
    ~ViewingBarModule();

private:
    void setTableViewsFolders();
    void setCurrentTableView(QTableView*);
    void setCurrentFileInfo(QFileInfo);
    void setClickedFolderPath(const QString&);
    void setClickedFilePath(const QString&);

private slots:
    void on_leftTableView_clicked(const QModelIndex& index);
    void on_leftTableView_doubleClicked(const QModelIndex& index);

private:
    Ui::ViewingBarModule* ui;

    QFileSystemModel* fileSystemModel;

    QDir leftTableViewFolder;
    QDir rightTableViewFolder;
    QDir currentFolder;

    QTableView* currentTableView;

    QFileInfo currentFileInfo;

    QString clickedFolderPath = "";
    QString clickedFilePath = "";
};

#endif // VIEWINGBARMODULE_H
