#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>   //предоставляет главное окно приложения
#include<QClipboard>    //обеспечивает доступ к системному буферу обмена окна

#include "searchwindow.h"
#include "systemfiles.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow   //класс главного окна приложения
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_lvSource_doubleClicked(const QModelIndex &index);   //слот двойного нажатия на панель"lvSource"

    void on_lvSource_clicked(const QModelIndex &index); //слот нажатия на панель"lvSource"

    void on_btnCreate_clicked();    //слот нажатия на кнопку "Сreate"

    void on_btnDelete_clicked();    //слот нажатия на кнопку "Delete"

    void on_btnCopy_clicked();  //слот нажатия на кнопку "Сopy"

    void on_btnReplace_clicked();   //слот нажатия на кнопку "Replace"

    void on_btnRename_clicked();    //слот нажатия на кнопку "Rename"

    void on_btnSearch_clicked();    //слот нажатия на кнопку "Search"

    void on_lineSearch_textEdited(const QString &arg1); //слот ввода имени для поиска

    void on_listWidget_currentTextChanged(const QString &currentText);  //слот копирования текущего местоположения в буфер обмена

private:
    Ui::MainWindow *ui; //указатель на объект соотв типа в классе основной формы
    QFileSystemModel *model;    //указатель для связи с моделью данных для файловой системы

    File f; //объект класса File для выполнения операций с текстовыми файлами
    Dir d;   //объект класса dir для выполнения операций с директориями
    Link l;

    System *file=&f;    //указатель на объект класса System для получения адреса объекта класса File
    System *dir=&d;  //указатель на объект класса System для получения адреса объекта класса dir
    System *link=&l;

    SearchWindow window;    //объект класса SearchWindow для вывода результатов поиска

    QString filePath="";    //переменная для хранения пути выбранного файла
    QString fileName="";    //переменная для хранения имени выбранного файла

    QString dirPath=""; //переменная для хранения пути выбранной директории
    QString dirName=""; //переменная для хранения имени выбранной директории

    QString linkPath="";
    QString linkName="";
};

bool RecursiveDelete(QDir&, System *f, System *d, System *l);  //функция рекурсивного удаления содержимого выбранной папки
void RecursiveCopyList(QDir &,QFileInfoList &); //функция рекурсивного наполнения содержимым списка для копирования

#endif // MAINWINDOW_H
