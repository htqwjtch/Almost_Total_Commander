#ifndef TABMODULE_H
#define TABMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "../../services/tabService/tabservice.h"
#include "../copyingModule/copyingmodule.h"
#include "../creatingModule/creatingmodule.h"
#include "../namingModules/namingmodule.h"
#include "../removingModule/removingmodule.h"
#include "../replacingModule/replacingmodule.h"
#include "../searchingModule/searchingmodule.h"

#include <QDateTime>
#include <QDesktopServices>
#include <QDialog>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QString>
#include <QTableView>
#include <QUrl>
#include <QWidget>

namespace Ui
{
    class TabModule;
}

class TabModule : public QDialog
{
    Q_OBJECT

public:
    explicit TabModule(QWidget* parent = nullptr);
    ~TabModule();
    void execute(const QString&);

private:
    void setFileSystemModel();
    void setSortFilterModel();
    void setUserInterface();
    void setTableViewsModels();
    void setTableViews();
    void setTableViewsDirectories();
    void setTableViewsDirectoriesAsHomeDirectories();
    void setTableViewsRootIndexes();
    void setLineEditsTexts();
    void setSortingButton();
    void setToolTipsForButtons();
    void setButtonsStyleSheets();
    void connectSignalsWithSlots();
    void connectTableViewsSignalsWithSlots();
    void connectLineEditsSignalsWithSlots();
    void setCurrenTableView(QTableView*);
    void setCurrentFileInfo(QFileInfo);
    bool isDot(QFileInfo&);
    bool isDotDot(QFileInfo&);
    void setLabelGridLayoutForDirectory(QFileInfo&);
    void setLastModeDateLabel(QFileInfo&);
    void setTypeLabelForDirectory();
    void setSizeLabelForDirectory(QFileInfo&);
    void setLabelGridLayoutForFile(QFileInfo&);
    void setTypeLabelForFile(QFileInfo&);
    void setSizeLabelForFile(QFileInfo&);
    void setClickedFilePath(const QString&);
    void setClickedDirectoryPath(const QString&);
    void openFile();
    void openDirectory(const QString&);
    void openDot();
    void openDotDot();
    void setCurrentLineEdit(QLineEdit*);
    void selectFile(QFileInfo&);
    void selectDirectory(QFileInfo&);
    void checkCurrentDirectory();
    void setCurrentDirectory(QDir&);
    void setSearchingModule();
    void setRemovingModule();
    void setCopyingModule();
    void setReplacingModule();

private slots:
    void on_leftTableView_clicked(const QModelIndex& index);
    void on_leftTableView_doubleClicked(const QModelIndex& index);
    void on_leftLineEdit_textEdited(const QString& arg1);
    void on_searchingLineEdit_textEdited(const QString& arg1);
    void on_searchingLineEdit_returnPressed();
    void on_searchingButton_clicked();
    void searchingCompleted();
    void on_creatingButton_clicked();
    void on_removingButton_clicked();
    void removingFailed(const QString&);
    void removingCompleted();
    void on_copyingButton_clicked();
    void copyingFailed(const QString&);
    void copyingCompleted();
    void on_replacingButton_clicked();
    void replacingFailed(const QString&);
    void replacingCompleted();
    void on_renamingButton_clicked();
    void on_showHiddenButton_clicked();
    void on_sortingBox_currentIndexChanged(int index);

private:
    Ui::TabModule* ui;

    QFileSystemModel* fileSystemModel;
    QSortFilterProxyModel* sortFilterModel;

    QDir leftTableViewDirectory;
    QDir rightTableViewDirectory;
    QDir currentDirectory;

    QFileInfo currentFileInfo;

    QTableView* currentTableView;
    QLineEdit* currentLineEdit;

    CopyingModule* copyingModule;
    RemovingModule* removingModule;
    ReplacingModule* replacingModule;
    SearchingModule* searchingModule;

    QString clickedFilePath = "";
    QString clickedDirectoryPath = "";

    QString searchingName = "";
};

#endif // TABMODULE_H
