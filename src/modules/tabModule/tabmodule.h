#ifndef TABMODULE_H
#define TABMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "../colorDelegate/colordelegate.h"
#include "../copyingModule/copyingmodule.h"
#include "../creatingModule/creatingmodule.h"
#include "../namingModules/namingmodule.h"
#include "../replacingModule/replacingmodule.h"
#include "../searchingModule/searchingmodule.h"
#include "../trashModule/trashmodule.h"

#include <QDateTime>
#include <QDesktopServices>
#include <QDialog>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QPair>
#include <QSortFilterProxyModel>
#include <QStack>
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
    explicit TabModule(QWidget *parent = nullptr);
    ~TabModule();
    void execute(const QString &);

  private:
    void setFileSystemModel();
    void setUserInterFace();
    void setTableViewModels();
    void setTableViews();
    void setTableViewFolders();
    void setTableViewRootIndexes();
    void setTableViewDelegates();
    void setLineEditTexts();
    void setToolTips();
    void setButtonStyleSheets();
    void connectSignalsWithSlots();
    void setCurrenTableView(QTableView *);
    void setTrashModule();
    void setChangeStack();

    void revertChanges();

    void setCurrentFileInfo(QFileInfo);
    void setClickedFolderPath(const QString &);
    void openParentFolder();
    void openFolder(const QString &);
    void setCurrentLineEdit(QLineEdit *);
    void resetLabelGridLayout();

    void setLabelGridLayoutForFolder();
    void setTypeLabel();
    void setSizeLabelForFolder();
    void setLastModeDateLabel();
    void setLabelGridLayoutForFile();
    void setSizeLabelForFile();
    void setClickedFilePath(const QString &);

    void clearSelectionModels();
    void resetClickedPathes();

    void selectFolder(QFileInfo &);
    void selectFile(QFileInfo &);

    void checkCurrentFolder();
    void setCurrentFolder(QDir &);
    void setSearchingModule();

    void setCreatingModule();

    void checkClickedObjectsPathes();
    void setRemovingModule();

    void setCopyingModule();

    void setReplacingModule();

    void setNamingModule();

  private slots:
    void on_sortingBox_currentIndexChanged(int index);

    void on_leftAboveButton_clicked();
    void on_rightAboveButton_clicked();

    void on_leftTableView_clicked(const QModelIndex &index);
    void on_leftTableView_doubleClicked(const QModelIndex &index);
    void on_leftLineEdit_textEdited(const QString &arg1);

    void on_searchingLineEdit_textEdited(const QString &arg1);
    void on_searchingLineEdit_returnPressed();
    void on_searchingButton_clicked();
    void searchingCompleted();

    void on_creatingButton_clicked();
    void creatingCompleted(const QString &);

    void on_removingButton_clicked();
    void removingFailed();
    void removingCompleted();
    void movingToTrashFailed(const QStringList &);
    void movingToTrashCompleted(const QStringList &);

    void on_copyingButton_clicked();
    void copyingFailed(const QStringList &);
    void copyingCompleted(const QStringList &);

    void on_replacingButton_clicked();
    void replacingFailed(const QStringList &, const QString &);
    void replacingCompleted(const QStringList &, const QString &);

    void on_renamingButton_clicked();
    void namingCompleted(const QString &, const QString &, const QString &);

    void on_showHiddenButton_clicked();

    void on_trashButton_clicked();

  private:
    Ui::TabModule *ui;

    QFileSystemModel *fileSystemModel;
    QSortFilterProxyModel *sortFilterModel;

    QDir leftTableViewFolder;
    QDir rightTableViewFolder;
    QDir currentFolder;

    QFileInfo currentFileInfo;

    QTableView *currentTableView;
    QLineEdit *currentLineEdit;

    QStack<QPair<QStringList, QStringList>> *changeStack;
    bool isRevertion = false;

    TrashModule *trashModule;

    CreatingModule *creatingModule;

    CopyingModule *copyingModule;
    ReplacingModule *replacingModule;
    SearchingModule *searchingModule;

    NamingModule *namingModule;

    QString clickedFilePath = "";
    QString clickedFolderPath = "";

    QString searchingName = "";
};

#endif // TABMODULE_H
