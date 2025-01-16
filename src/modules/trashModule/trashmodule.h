#ifndef TRASHMODULE_H
#define TRASHMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "../colorDelegate/colordelegate.h"
#include "../removingModule/removingmodule.h"

#include <QDebug>
#include <QDesktopServices>
#include <QDialog>
#include <QFile>
#include <QFileSystemModel>
#include <QMap>
#include <QMessageBox>
#include <QUrl>

namespace Ui
{
class TrashModule;
}

class TrashModule : public QDialog
{
    Q_OBJECT

  public:
    explicit TrashModule(QWidget *parent = nullptr);
    ~TrashModule();
    bool checkTrash();
    void moveToTrash(const QStringList &);
    void removePermanently(const QStringList &);
    void restore(const QStringList &);

  private:
    void setFileSystemModel();
    void setUserInterFace();
    void setTableView();
    void setToolTips();
    void setButtonStyleSheets();

    void setCurrentFileInfo(QFileInfo);
    void setLabelGridLayoutForFolder();
    void setTypeLabel();
    void setSizeLabelForFolder();
    void setLastModeDateLabel();
    void setLabelGridLayoutForFile();
    void setSizeLabelForFile();

    void setRemovingModule();

  private slots:
    void on_restoringButton_clicked();

    void on_removingButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void removingFailed();
    void removingCompleted();

    void on_aboveButton_clicked();

  private:
    Ui::TrashModule *ui;

    QFileSystemModel *fileSystemModel;

    QString rootPath = QDir::homePath() + "/.local/share/Trash/files";

    QFileInfo currentFileInfo;

    RemovingModule *removingModule;

  signals:
    void removingCompletedSignal();
    void removingFailedSignal();
    void movingToTrashCompletedSignal(QStringList);
    void movingToTrashFailedSignal(QStringList);
};

#endif // TRASHMODULE_H
