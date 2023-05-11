#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H

#include <QClipboard>
#include <QDialog>
#include <QDir>
#include <QListWidget> //предоставляет виджет списка на основе элементов

namespace Ui
{
    class SearchResult;
}

class SearchResult : public QDialog
{
    Q_OBJECT

    Ui::SearchResult* ui; // указатель на объект соотв типа в классе основной формы

public:
    explicit SearchResult(QWidget* parent = nullptr);
    ~SearchResult();
    void set_ui(QFileInfoList); // метод передачи результатов поиска для отображения
    void reset_ui();            // метод очистки окна отображения результатов поиска

private slots:
    void on_btnOK_clicked();

    void on_leftList_itemClicked(QListWidgetItem* item);
};

#endif // SEARCHRESULT_H
