#include "searchwindow.h"
#include "ui_searchwindow.h"

SearchWindow::SearchWindow(QWidget* parent) : QDialog(parent), ui(new Ui::SearchWindow)
{
    ui->setupUi(this);        // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("Search"); // установка имени окна
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::on_btnOK_clicked() // слот нажатия на "OK"
{
    hide(); // закрытие текущего окна
}

void SearchWindow::setUi() // метод передачи результатов поиска для отображения
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

void SearchWindow::resetUi() // метод очистки окна отображения результатов поиска
{
    iter.setIter(list.peekHead()); // установка итератора на начало контейнера
    list.clear();                  // очистка контейнера
    ui->listWidget->clear();       // очистка окна вывода результатов поиска
}
