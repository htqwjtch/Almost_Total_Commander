#ifndef ADDITIONALWINDOW_H
#define ADDITIONALWINDOW_H

#include<QDialog>  //базовый класс диалоговых окон
#include<QFileSystemModel>  //редоставляет модель данных для локальной файловой системы
#include<QDir>  //предоставляет доступ к структурам каталогов и их содержимому
#include<QDesktopServices>  //предоставляет методы для доступа к общим службам рабочего стола
#include<QString>   //предоставляет символьную строку в Юникоде

namespace Ui {
class AdditionalWindow;
}

class AdditionalWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdditionalWindow(QWidget *parent = nullptr);
    //"explicit" предупреждает неявное преобразование типов
    ~AdditionalWindow();
    void SetCancel(bool);   //метод установки отмены
    bool Cancel();  //метод срабатывания отмены
    void SetQDir(QDir &);   //метод получения переменной директории
    QDir GetQDir(); //метод передачи переменной директории

private slots:
    void on_btnOK_clicked();    // слот нажатия на "OK"

    void on_btnCancel_clicked();    // слот нажатия на "Cancel"

    void on_listView_doubleClicked(const QModelIndex &index);   // слот нажатия на панель "listView"

private:
    Ui::AdditionalWindow *ui;   //указатель для связи с соответствующим ui-файлом
    QFileSystemModel *model;    //указатель для связи с моделью данных для файловой системы
    QDir dir;   //переменная для хранения информации об определенной директории
    bool cancel=true;   //флаг срабатывания отмены
};

#endif // ADDITIONALWINDOW_H
