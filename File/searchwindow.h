#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include "container.h"

#include <QDialog>
#include <QDir>
#include <QListWidget> //предоставляет виджет списка на основе элементов

namespace Ui
{
    class SearchWindow;
}

class SearchWindow : public QDialog
{
    Q_OBJECT

    Ui::SearchWindow* ui; // указатель на объект соотв типа в классе основной формы
    List list; // контейнер для хранения пктей файлов, имена которых совпали с введенным
    List ::Iterator iter; // итератор контейнера для управления его элементами

private slots:
    void on_btnOK_clicked(); // слот нажатия на "OK"

public:
    explicit SearchWindow(QWidget* parent = nullptr);
    ~SearchWindow();
    void setUi();   // метод передачи результатов поиска для отображения
    void resetUi(); // метод очистки окна отображения результатов поиска
};

#endif // SEARCHWINDOW_H
