#include "searchresult.h"
#include "ui_searchresult.h"

#include <QClipboard>
#include <QFileSystemModel>
#include <QLabel>
#include <QMessageBox>
#include <QStandardItemModel>
#include <QStringListModel>

SearchResult::SearchResult(QWidget* parent) : QDialog(parent), ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    setWindowTitle("Search"); // установка имени окна
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::set_ui(QFileInfoList list) // метод передачи результатов поиска для отображения
{
    //    QStringListModel* model;
    //    if (!(model = new QStringListModel(this))) // выделение памяти под указатель на объект этого класса
    //        QMessageBox::warning(this, "Memory allocation", "Model of QFileSystemModel was not created!");

    //    model->setStringList(list);
    //    ui->leftList->setModel(model);

    if (list.isEmpty()) // если контейнер пуст
    {
        ui->leftList->addItem("No elements");
        return;
    }
    foreach (QFileInfo info, list)
    {
        ui->leftList->addItem(info.absoluteFilePath());
    }
}

void SearchResult::reset_ui() // метод очистки окна отображения результатов поиска
{
    ui->leftList->clear(); // очистка окна вывода результатов поиска
}

void SearchResult::on_btnOK_clicked()
{
    hide(); // закрытие текущего окна
}

void SearchResult::on_leftList_itemClicked(QListWidgetItem* item)
{
    QClipboard* pcb = QApplication::clipboard(); //создание объекта для взаимодействия с буфером обмена
    pcb->setText(item->text(), QClipboard::Clipboard); //копирование выбранного текста в буфер обмена
}
