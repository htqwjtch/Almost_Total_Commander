#ifndef TRASHMODULE_H
#define TRASHMODULE_H

#include "../removingModule/removingmodule.h"

#include <QDialog>

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

  private:
    void setRemovingModule();

  private slots:
    void on_restoringButton_clicked();

    void on_removingButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void removingFailed(const QString &);
    void removingCompleted();

  private:
    Ui::TrashModule *ui;

    RemovingModule *removingModule;

  signals:
    void removingCompletedSignal();
    void removingFailedSignal(QString);
};

#endif // TRASHMODULE_H
