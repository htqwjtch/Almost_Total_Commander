#ifndef FORM_H
#define FORM_H

#include "../searchResult/searchresult.h"
#include "../sysElem/syselem.h"
#include "../thToCopy/threadtocpy.h"
#include "../thToRemove/threadtoremove.h"
#include "../thToReplace/threadtoreplace.h"
#include "../thToSearch/threadtosearch.h"

#include <QDir>
#include <QFileSystemModel>
#include <QListView>
#include <QString>
#include <QThread>
#include <QWidget>

namespace Ui
{
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

    Ui::Form* ui;
    QFileSystemModel* model; //указатель для связи с моделью данных для файловой системы

    QThread* threadCopy;
    QThread* threadRemove;
    QThread* threadReplace;
    QThread* threadSearch;

    QListView* view;
    SearchResult* window;

    ThreadToCopy* thCopy;
    ThreadToRemove* thRemove;
    ThreadToReplace* thReplace;
    ThreadToSearch* thSearch;

    File f; //объект класса File для выполнения операций с текстовыми файлами
    Dir d;  //объект класса dir для выполнения операций с директориями

    SysElem* file = &f; //указатель на объект класса System для получения адреса объекта класса File
    SysElem* dir = &d; //указатель на объект класса System для получения адреса объекта класса dir

    QString filePath = ""; //переменная для хранения пути выбранного файла

    QString dirPath = ""; //переменная для хранения пути выбранной директории

    QString searchName = "";

private slots:
    void on_lvLeft_clicked(const QModelIndex& index);

    void on_lvLeft_doubleClicked(const QModelIndex& index);

    void on_btnCreate_clicked();

    void on_btnRemove_clicked();

    void on_btnCopy_clicked();

    void on_btnReplace_clicked();

    void on_btnRename_clicked();

    void on_lineSearch_textEdited(const QString& arg1);

    void on_btnSearch_clicked();

    void on_leftPath_textEdited(const QString& arg1);

public:
    explicit Form(QWidget* parent = nullptr);
    ~Form();

    void onBtnCreateClicked();
    void onBtnRemoveClicked();
    void onBtnCopyClicked();
    void onBtnReplaceClicked();
    void onBtnRenameClicked();
    void onBtnSearchClicked();

signals:
    void startCopy(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void startRemove(SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void startReplace(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void startSearch(QString, QString, QString);
};

#endif // FORM_H
