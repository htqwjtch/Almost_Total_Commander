#include "additionalwindow.h"
#include "exception.h"
#include "ui_additionalwindow.h"

#include<QMessageBox>

AdditionalWindow::AdditionalWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AdditionalWindow)
{
    ui->setupUi(this);  //настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("FileManager");  //установка имени окна
    model = new QFileSystemModel(this);     // выделение памяти под указатель
    model->setFilter(QDir::QDir::AllEntries); // метод позволяет отображать некоторые элементы файловой системы(в нашем случае все)
    model->setRootPath("");                   // метод позволяет определить место в системе для отслеживания изменений(указана корневая папка)
    //система представлена в виде структурЫ типа List
    ui->listView->setModel(model);  //установка новой модели выбора
}

AdditionalWindow::~AdditionalWindow()
{
    delete ui;
    delete model;
}

void AdditionalWindow::SetQDir(QDir &Dir)   //метод получения переменной директории
{
    dir=Dir;
}

QDir AdditionalWindow::GetQDir()    //метод передачи переменной директории
{
    return dir;
}

void AdditionalWindow::SetCancel(bool i)    //метод установки отмены
{
    cancel=i;
}

bool AdditionalWindow::Cancel() //метод срабатывания отмены
{
    return cancel;
}

void AdditionalWindow::on_btnOK_clicked()   // слот нажатия на "OK"
{
    QDir dir=QDir(model->filePath(ui->listView->rootIndex()));  //получение текущей директории
    try {
        if(dir.absolutePath()=="D:/Qt/Projects/build-QWERTY-Desktop_Qt_6_4_0_MinGW_64_bit-Debug")   //если это корневая директория
            throw RootDirectoryException("", "You are in a root directory! Please choose an another directory");
        else
        {
            SetCancel(false);   //установка подтверждения
            SetQDir(dir);    //метод получения переменной директории
            hide(); //метод закрытия окна
        }
    }
    catch(RootDirectoryException error)
    {
        error.GetException(this);
    }

    catch (...)
    {
        QMessageBox::warning(this, "", "Unknown error! Please try again!");
    }

}

void AdditionalWindow::on_btnCancel_clicked()   // слот нажатия на "Cancel"
{
    hide(); //метод закрытия окна
}

void AdditionalWindow::on_listView_doubleClicked(const QModelIndex &index)  // слот нажатия на панель "listView"
{
    QListView* listView = (QListView*) sender();//получение указателя на обЪект который принял сигнал
    //приведение объекта источника методом sender() к типу listview
    QFileInfo info = model->fileInfo(index); //получение пути элемента, который соответствует этому индексу
    // в зависимости от того, что это за элемент, алгоритм дальнейших дествий ветвится
    if(info.fileName()=="..")
    {
        QDir dir = info.dir();//получение объекта класса QDir
        dir.cd("..");//dir.cdUp();  навигация. в данном случае переход в родительскую папку
        listView->setRootIndex(model->index(dir.absolutePath()));// получение индекса по пути
        //чтобы показать эелемент, полученный через индекс(listView->setRootIndex)
        //так работает списочное представление (в конкретный момент времени показано содержимое одной папки)
    }
    else if(info.fileName()==".")
    {
        listView->setRootIndex(model->index(""));//переход в корневую папку
        //показать корневую папку
    }
    else if (info.isDir())// если выбранный элемент - директория
    {
        listView->setRootIndex(index);//элемент с этим индексом становится корневым
    }
}
