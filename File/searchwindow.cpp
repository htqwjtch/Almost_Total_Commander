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

void SearchWindow::setName(QString name)
{
        searchName = name;
}

void SearchWindow::search(QDir& dir)
{
    // проход по текущему диску для поиска объектов с введенным именем
    foreach (QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.fileName() == searchName)               // сравнение элементов по имени
            list.push(dir.absoluteFilePath(searchName)); // добавление элемента в контейнер
        if (info.isFile() || info.isSymLink())           // если элемент - файл, переходим к след файлу
            continue;
        if (info.isDir()) // если дошли до этого момента, значит элемент - директория
        {
            dir.cd(info.fileName()); // заходим в нее
            search(dir);             // рекурсивно ищем различия
            dir.cdUp();              // возврат
        }
    }
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
