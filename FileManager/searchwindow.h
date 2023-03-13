#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include "container.h"

#include <QDialog>
#include <QDir>
#include <QListWidget>  //предоставляет виджет списка на основе элементов

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    ~SearchWindow();
    void SetName(const QString);    //метод получения имени для поиска
    void Search(QDir &);            //метод поиска по имени
    void SetUi();                   //метод передачи результатов поиска для отображения
    void ResetUi();                 //метод очистки окна отображения результатов поиска

private slots:

    void on_btnOK_clicked();    // слот нажатия на "OK"

private:
    Ui::SearchWindow *ui;   //указатель на объект соотв типа в классе основной формы
    QString searchName="";  //переменная для хранения имени для поиска
    List list;  //контейнер для хранения пктей файлов, имена которых совпали с введенным
    List :: Iterator iter;  //итератор контейнера для управления его элементами
};

#endif // SEARCHWINDOW_H
