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
#include <QListView>
#include <QMessageBox>
#include <QString>
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
    void setUserInterface();
    void setListViewsModels();
    void setListViewsDirectories();
    void setListViewsDirectoriesAsHomeDirectories();
    void setListViewsRootIndexes();
    void setLineEditsTexts();
    void setToolTipsForButtons();
    void setButtonsStyleSheets();
    void connectSignalsWithSlots();
    void connectListViewsSignalsWithSlots();
    void connectLineEditsSignalsWithSlots();
    void setCurrenListView(QListView*);
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
    void on_leftListView_clicked(const QModelIndex& index);
    void on_leftListView_doubleClicked(const QModelIndex& index);
    void on_leftLineEdit_textEdited(const QString& arg1);
    void on_searchingLineEdit_textEdited(const QString& arg1);
    void on_searchingLineEdit_returnPressed();
    void on_searchingButton_clicked();
    void on_creatingButton_clicked();
    void on_removingButton_clicked();
    void on_copyingButton_clicked();
    void on_replacingButton_clicked();
    void on_renamingButton_clicked();

    void copyingFailed(const QString&);
    void copyingCompleted();
    void removingFailed(const QString&);
    void removingCompleted();
    void replacingFailed(const QString&);
    void replacingCompleted();
    void searchingCompleted();

private:
    Ui::TabModule* ui;

    QFileSystemModel* fileSystemModel;

    QDir leftListViewDirectory;
    QDir rightListViewDirectory;
    QDir currentDirectory;

    QFileInfo currentFileInfo;

    QListView* currentListView;
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
