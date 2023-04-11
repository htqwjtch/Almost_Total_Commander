#ifndef FORM_H
#define FORM_H

#include "searchwindow.h"
#include "systemfiles.h"
#include "threadtocopy.h"
#include "threadtoremove.h"
#include "threadtosearch.h"

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
    QThread* threadSearch;

    QListView* view;
    SearchWindow* window;

    ThreadToCopy* thCopy;
    ThreadToRemove* thRemove;
    ThreadToSearch* thSearch;

    File f; //объект класса File для выполнения операций с текстовыми файлами
    Dir d;  //объект класса dir для выполнения операций с директориями
    Link l;

    System* file = &f; //указатель на объект класса System для получения адреса объекта класса File
    System* dir = &d; //указатель на объект класса System для получения адреса объекта класса dir
    System* link = &l;

    QString filePath = ""; //переменная для хранения пути выбранного файла
    QString fileName = ""; //переменная для хранения имени выбранного файла

    QString dirPath = ""; //переменная для хранения пути выбранной директории
    QString dirName = ""; //переменная для хранения имени выбранной директории

    QString linkPath = "";
    QString linkName = "";

    QString searchName = "";

private slots:
    void on_lvLeft_clicked(const QModelIndex& index);

    void on_lvLeft_doubleClicked(const QModelIndex& index);

    void on_btnCreate_clicked();

    void on_btnDelete_clicked();

    void on_btnCopy_clicked();

    void on_btnReplace_clicked();

    void on_btnRename_clicked();

    void on_lineSearch_textEdited(const QString& arg1);

    void on_btnSearch_clicked();

public:
    explicit Form(QWidget* parent = nullptr);
    ~Form();

    void onBtnCreateClicked();
    void onBtnDeleteClicked();
    void onBtnCopyClicked();
    void onBtnReplaceClicked();
    void onBtnRenameClicked();
    void onBtnSearchClicked();

signals:
    void startCopy(QDir lDir, QDir rDir, System* file, System* dir, System* link, QString dirName);
    void startRemove(System* file, System* dir, System* link, QString dirPath);
    void startSearch(QString, QString, QString);
};

#endif // FORM_H
