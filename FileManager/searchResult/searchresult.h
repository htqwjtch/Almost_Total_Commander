#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include "../container/container.h"

#include <QDialog>
#include <QDir>
#include <QListWidget> //предоставляет виджет списка на основе элементов

namespace Ui {
class SearchResult;
}

class SearchResult : public QDialog
{
    Q_OBJECT

    Ui::SearchResult* ui; // указатель на объект соотв типа в классе основной формы
    List list; // контейнер для хранения пктей файлов, имена которых совпали с введенным
    List ::Iterator iter; // итератор контейнера для управления его элементами

public:
    explicit SearchResult(QWidget *parent = nullptr);
    ~SearchResult();
    void setUi();   // метод передачи результатов поиска для отображения
    void resetUi(); // метод очистки окна отображения результатов поиска

private slots:
    void on_btnOK_clicked();

};

#endif // SEARCHRESULT_H
