#include "searchresult.h"
#include "ui_searchresult.h"

#include <QClipboard>
#include <QFileSystemModel>
#include <QLabel>
#include <QMessageBox>
#include <QStandardItemModel>

SearchResult::SearchResult(QWidget* parent) : QDialog(parent), ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    setWindowTitle("Search"); // установка имени окна
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::setUi(QFileInfoList list) // метод передачи результатов поиска для отображения
{
    if (list.isEmpty()) // если контейнер пуст
    {
        ui->listWidget->addItem("There are no results with this name! Please try again");
        return;
    }
    foreach (QFileInfo info, list)
        ui->listWidget->addItem(info.absoluteFilePath());
}

void SearchResult::resetUi() // метод очистки окна отображения результатов поиска
{
    ui->listWidget->clear(); // очистка окна вывода результатов поиска
}

void SearchResult::on_btnOK_clicked()
{
    hide(); // закрытие текущего окна
}

void SearchResult::on_listWidget_itemClicked(QListWidgetItem* item)
{
    QClipboard* pcb = QApplication::clipboard(); //создание объекта для взаимодействия с буфером обмена
    pcb->setText(item->text(), QClipboard::Clipboard); //копирование выбранного текста в буфер обмена
}
