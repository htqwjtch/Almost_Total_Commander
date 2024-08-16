#ifndef FORM_H
#define FORM_H

#include "../src/modules/copyingModule/copyingmodule.h"
#include "../src/modules/removingModule/removingmodule.h"
#include "../src/modules/replacingModule/replacingmodule.h"
#include "../src/modules/searchingModule/searchingmodule.h"

#include <QDateTime>
#include <QFileSystemModel>
#include <QListView>
#include <QString>
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

    QListView* view; // список элементов файловой системы, которые пользователь видит сейчас (одна из панелей (левая или правая) коммандера)

    CopyingModule* copyingModule;
    RemovingModule* removingModule;
    ReplacingModule* replacingModule;
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

    void copyingIsPerformed();
    void copyingIsNotPerformed();
    void removingIsPerformed();
    void removingIsNotPerformed();
    void replacingIsPerformed();
    void replacingIsNotPerformed();
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
};

#endif // FORM_H
