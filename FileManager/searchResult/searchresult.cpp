#include "searchresult.h"
#include "ui_searchresult.h"

SearchResult::SearchResult(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchResult)
{
    ui->setupUi(this);
    setWindowTitle("Search"); // установка имени окна
}

SearchResult::~SearchResult()
{
    delete ui;
}

void SearchResult::setUi() // метод передачи результатов поиска для отображения
{
    if (list.isEmpty()) // если контейнер пуст
        ui->listWidget->addItem("There are no results with this name! Please try again");
    else
    {
        iter.setIter(list.peekHead()); // установка итератора на начало контейнера
        // цикл добавления элементов контейнера в окно отображения результато поиска
        do
        {
            ui->listWidget->addItem((*iter)->info);
        } while (++iter);
    }
}

void SearchResult::resetUi() // метод очистки окна отображения результатов поиска
{
    iter.setIter(list.peekHead()); // установка итератора на начало контейнера
    list.clear();                  // очистка контейнера
    ui->listWidget->clear();       // очистка окна вывода результатов поиска
}

void SearchResult::on_btnOK_clicked()
{
    hide(); // закрытие текущего окна
}

