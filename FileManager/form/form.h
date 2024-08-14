#ifndef FORM_H
#define FORM_H

#include "../src/modules/searchingModule/searchingmodule.h"
#include "../sysElem/syselem.h"
#include "../thToCopy/threadtocpy.h"
#include "../thToRemove/threadtoremove.h"
#include "../thToReplace/threadtoreplace.h"

#include <QDateTime>
#include <QDir>
#include <QFileSystemModel>
#include <QListView>
#include <QString>
#include <QThread>
#include <QWidget>
#include <QUrl>

namespace Ui
{
    class Form;
}

class Form : public QWidget
{
    Q_OBJECT

    Ui::Form* ui;
    QFileSystemModel* model; //указатель для связи с моделью данных для файловой системы
    //объекты для копирования, удаления, перемещения, поиска в отдельном потоке
    QThread* threadCopy;
    QThread* threadRemove;
    QThread* threadReplace;

    QListView* view; // список элементов файловой системы, которые пользователь видит сейчас (одна из панелей (левая или правая) коммандера)

    ThreadToCopy* thCopy;
    ThreadToRemove* thRemove;
    ThreadToReplace* thReplace;
    SearchingModule* searchingModule;

    File f; //объект класса File для выполнения операций с текстовыми файлами
    Dir d;  //объект класса Dir для выполнения операций с директориями

    SysElem* file = &f;
    SysElem* dir = &d;

    QString filePath = "";
    QString dirPath = "";

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

    void remove_is_not_performed();

    void copy_is_not_performed();

    void replace_is_not_performed();

    void ready_to_remove();

    void ready_to_copy();

    void ready_to_replace();

    void readyToSearching();

public:
    explicit Form(QWidget* parent = nullptr);
    ~Form();

    //методы-обертки для слотов
    void btn_create();
    void btn_remove();
    void btn_copy();
    void btn_replace();
    void btn_rename();
    void btn_search();

signals:
    void start_copy(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void start_remove(SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void start_replace(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath);
    void start_search(QString, QString, QString);
};

#endif // FORM_H
