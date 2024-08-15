#ifndef FORM_H
#define FORM_H

#include "../src/modules/copyingModule/copyingmodule.h"
#include "../src/modules/searchingModule/searchingmodule.h"
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
    QThread* threadRemove;
    QThread* threadReplace;

    QListView* view; // список элементов файловой системы, которые пользователь видит сейчас (одна из панелей (левая или правая) коммандера)

    ThreadToRemove* thRemove;
    ThreadToReplace* thReplace;

    CopyingModule* copyingModule;
    SearchingModule* searchingModule;

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
    void replace_is_not_performed();
    void ready_to_remove();
    void ready_to_replace();

    void copyingIsPerformed();
    void copyingIsNotPerformed();
    void searchingIsPerformed();

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
    void start_remove(QString, QString);
    void start_replace(QDir, QString, QString);
};

#endif // FORM_H
