#include "mainwindow.h"
#include "confirmdelete.h"
#include "createchoice.h"
#include "exception.h"
#include "linkedpathwindow.h"
#include "renamewindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    try
    {
        ui->setupUi(this);                         // настраивает пользовательский интерфейс для указанного виджета
        setWindowTitle("FileManager");             // установка имени главного окна
        if (!(model = new QFileSystemModel(this))) // выделение памяти под указатель на объект этого класса
            throw BadAllocException("Memory allocation", "Model of QFileSystemModel was not created!");
        model->setFilter(QDir::QDir::AllEntries); //отображать некоторые элементы файловой системы(в нашем случае все)
        model->setRootPath("/");                  // определить место в системе для отслеживания изменений(указана корневая папка)
        ui->lvLeft->setModel(model);              // назначение *model объектом представления панели Source
        ui->lvRight->setModel(model);
        connect(ui->lvRight, SIGNAL(clicked(QModelIndex)), this, SLOT(on_lvLeft_clicked(QModelIndex)));
        connect(ui->lvRight, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_lvLeft_doubleClicked(QModelIndex)));
        if (!(view = new QListView(this)))
            throw BadAllocException("Memory allocation", "Object of QListView was not created!");
        // устанока информации для подсказок
        ui->btnCreate->setToolTip("Create");
        ui->btnDelete->setToolTip("Delete");
        ui->btnCopy->setToolTip("Copy");
        ui->btnReplace->setToolTip("Replace");
        ui->btnRename->setToolTip("Rename");
        ui->lineSearch->setToolTip("Please don't forget about the extension, if "
                                   "you want to enter a file name");
        if (!(window = new SearchWindow(this)))
            throw BadAllocException("Memory allocation", "Object of SearchWindow was not created!");
    }
    catch (BadAllocException error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Memory allocation", "Unknown error! Please try again!");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lvLeft_clicked(const QModelIndex& index)
{
    view = (QListView*)sender();                                // получение указателя на обЪект который принял сигнал
    QFileInfo info = model->fileInfo(index);                    // получение пути элемента, который соответствует этому индексу
    QString format = "dddd, d MMMM yy hh:mm:ss";                // формат вывода даты последнего изменения
    ui->lblDate->setText(info.lastModified().toString(format)); // вывод даты последнего изменения
    if (info.isFile())                                          // выбранный объект - файл
    {
        QString sizeFile = "";                                                     // переменная размера файла
        if (info.size() < 1024)                                                    // если размер файла меньше 1 килобайта
            sizeFile = sizeFile.append(QString::number(info.size())).append(" B"); // приведение размера к виду "B"
        else if (info.size() >= 1024 && info.size() < 1048576)                     // если размер файла больше 1 килобайта и меньше 1 мегабайта
        {
            double d = info.size() / 1024.;
            sizeFile = sizeFile.append(QString::number(d)).append(" KB"); // приведение размера к виду "KB"
        }
        else if (info.size() >= 1048576 && info.size() < 1073741824) // если размер файла больше 1 мегабайта и меньше 1 гигабайта
        {
            double d = info.size() / 1048576.;
            sizeFile = sizeFile.append(QString::number(d)).append(" MB"); // приведение размера к виду "MB"
        }
        else if (info.size() >= 1073741824) // если размер файла больше 1 гигабайта
        {
            double d = info.size() / 1073741824.;
            sizeFile = sizeFile.append(QString::number(d)).append(" GB"); // приведение размера к виду "GB"
        }
        QString size = "Size : ";
        QString allSize = size.append(sizeFile); // строка для отображения размера файла
        ui->lblSize->setText(allSize);           // отображениe размера файла
        QString type = "Type : ";
        QString typeInfo = type.append("file").append(" ").append(info.suffix()); // строка для отображения типа файла
        ui->lblType->setText(typeInfo);                                           // отображениe типа файла
        fileName = model->fileName(index);                                        // установка имени выбранного файла
        filePath = model->filePath(index);                                        // установка пути выбранного файла
        if (dirPath != "")                                                        // если до этого была выбрана директория
            dirPath = dirName = "";                                               //очистка пути директории
        if (linkPath != "")
            linkPath = linkName = "";
    }
    else if (info.isDir()) // если выбранный объект - директория
    {
        ui->lblSize->setText("");
        ui->lblType->setText("Type: System directory"); // отображение типа объекта
        dirName = info.fileName();                      // переменная для хранения имени выбранной директории
        dirPath = info.absoluteFilePath();              // переменная для хранения пути выбранной директории
        if (filePath != "")                             // если до этого был выбран файл
            filePath = fileName = "";                   // очистка пути файл
        if (linkPath != "")
            linkPath = linkName = "";
    }
    else if (info.isSymLink())
    {
        QString sizelink = "";                                                     // переменная размера файла
        if (info.size() < 1024)                                                    // если размер файла меньше 1 килобайта
            sizelink = sizelink.append(QString::number(info.size())).append(" B"); // приведение размера к виду "B"
        else if (info.size() >= 1024 && info.size() < 1048576)                     // если размер файла больше 1 килобайта и меньше 1 мегабайта
        {
            double d = info.size() / 1024.;
            sizelink = sizelink.append(QString::number(d)).append(" KB"); // приведение размера к виду "KB"
        }
        else if (info.size() >= 1048576 && info.size() < 1073741824) // если размер файла больше 1 мегабайта и меньше 1 гигабайта
        {
            double d = info.size() / 1048576.;
            sizelink = sizelink.append(QString::number(d)).append(" MB"); // приведение размера к виду "MB"
        }
        else if (info.size() >= 1073741824) // если размер файла больше 1 гигабайта
        {
            double d = info.size() / 1073741824.;
            sizelink = sizelink.append(QString::number(d)).append(" GB"); // приведение размера к виду "GB"
        }
        QString size = "Size : ";
        QString allSize = size.append(sizelink); // строка для отображения размера файла
        ui->lblSize->setText(allSize);           // отображениe размера файла
        QString type = "Type : ";
        QString typeInfo = type.append("link").append(" ").append(info.suffix()); // строка для отображения типа файла
        ui->lblType->setText(typeInfo);                                           // отображениe типа файла
        linkName = model->fileName(index);                                        // переменная для хранения имени выбранного файла
        linkPath = model->filePath(index);                                        // установка пути выбранного файла
        if (filePath != "")
            filePath = fileName = "";
        if (dirPath != "")          // если до этого была выбрана директория
            dirPath = dirName = ""; // очистка пути директории
    }
}

void MainWindow::on_lvLeft_doubleClicked(const QModelIndex& index)
{
    view = (QListView*)sender(); // Возвращает указатель на объект, отправивший сигнал, если он вызван в слоте, активированном сигналом.
    QLabel* var;
    if (view == ui->lvLeft)
        var = ui->leftPath;
    if (view == ui->lvRight)
        var = ui->rightPath;
    QFileInfo fileInfo = model->fileInfo(index); // получение информации элемента, который соответствует этому индексу
    if (fileInfo.fileName() == "..")             // если выбран выход из текущей папки
    {
        QDir qDir = fileInfo.dir();                            // получение объекта класса QDir
        if (filePath != "")                                    // если до этого был выбран файл
            filePath = fileName = "";                          // очистка пути файла
        if (linkPath != "")                                    // если до этого был выбран файл
            linkPath = linkName = "";                          // очистка пути файла
        qDir.cd("..");                                         // dir.cdUp();  навигация. в данном случае переход в родительскую папку
        view->setRootIndex(model->index(qDir.absolutePath())); // получение индекса по пути
        // чтобы показать эелемент, полученный через индекс(listView->setRootIndex) так работает списочное представление
        // (в конкретный момент времени показано содержимое одной папки)
        var->clear();                              // очистка панели "listWidget"
        var->setText(fileInfo.absoluteFilePath()); // отображение нового пути в панели "listWidget"
        if (dirPath != "")                         // если до этого выбрана директория
            dirPath = dirName = "";                // очистка пути директории
    }
    else if (fileInfo.fileName() == ".") // если выбран выход в корневую папку
    {
        if (filePath != "")                        // если до этого был выбран файл
            filePath = fileName = "";              // очистка пути файла
        if (linkPath != "")                        // если до этого был выбран файл
            linkPath = linkName = "";              // очистка пути файла
        view->setRootIndex(model->index(""));      // переход в корневую папre (показать корневую папку)
        var->clear();                              // очистка панели "listWidget"
        var->setText(fileInfo.absoluteFilePath()); // отображение нового пути в панели "listWidget"
        if (dirPath != "")                         // если до этого выбрана директория
            dirPath = dirName = "";
    }
    else if (fileInfo.isDir()) // если выбранный элемент - директория
    {
        if (filePath != "")                        // если до этого был выбран файл
            filePath = fileName = "";              // очистка пути файла
        if (linkPath != "")                        // если до этого был выбран файл
            linkPath = linkName = "";              // очистка пути файла
        view->setRootIndex(index);                 // элемент с этим индексом становится корневым
        var->clear();                              // очистка панели "listWidget"
        var->setText(fileInfo.absoluteFilePath()); // отображение нового пути в панел "listWidget" очистка пути директории
        dirPath = dirName = "";
    }
    else if (fileInfo.isFile()) // если выбранный элемент - файл
    {
        if (dirPath != "")                                        // если до этого выбрана директория
            dirPath = dirName = "";                               // очистка пути директории
        if (linkPath != "")                                       // если до этого был выбран файл
            linkPath = linkName = "";                             // очистка пути файла
        QDesktopServices::openUrl(QUrl::fromUserInput(filePath)); // открывает файл в файловой системе Windows
        filePath = fileName = "";                                 // очистка пути файла
    }
    else if (fileInfo.isSymLink()) // если выбранный элемент - файл
    {
        if (dirPath != "")                                        // если до этого выбрана директория
            dirPath = dirName = "";                               // очистка пути директории
        if (filePath != "")                                       // если до этого был выбран файл
            filePath = fileName = "";                             // очистка пути файла
        QDesktopServices::openUrl(QUrl::fromUserInput(filePath)); // открывает файл в файловой системе Windows
        linkPath = linkName = "";                                 // очистка пути файла
    }
}

void MainWindow::on_btnCreate_clicked() // слот нажатия на кнопку "Сreate"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); //получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    try
    {
        if (qDir.absolutePath() == "/home/h4thqewjtch/qt/build-File-Desktop-Debug")
            // если это корневая директория
            QMessageBox::warning(this, "Create", "You are in a root directory! Please choose an another directory");
        else
        {
            CreateChoice window;
            window.exec();        // метод выполняет появление окна для выбора типа создаваемого объекта
            if (window.getFile()) // если был выбран файл
            {
                RenameWindow isFile;
                isFile.exec();                                                                 // выполняет появление окна для создания имени
                QString createPath = qDir.absolutePath().append("/").append(isFile.getName()); // получение пути соозданного файла
                bool fileExists = false;                                                       // флаг существования файлов с таким именем
                // цикл прохода по текущей директории для поиска файлов с таким именем
                foreach (QFileInfo files, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                {
                    if (files.fileName() == isFile.getName()) // если файл с таким именем найден
                    {
                        fileExists = true; // флаг существования файла принимает истинное значение
                        break;
                    }
                }
                if (!fileExists) // если файлов с таким именем нет
                {
                    if (!file->create(createPath)) // если файл не создан
                        throw PerformationException("Create File", "The operation <<Create>> was not perfomed!");
                }
                else
                    throw PerformationException("Create File", "A file with this name exists!");
            }
            if (window.getDir()) // если выбранный объект - директория0
            {
                RenameWindow isDir;
                isDir.exec();                                                                 // выполняет появление окна для создания имени
                QString createPath = qDir.absolutePath().append("/").append(isDir.getName()); // получение пути сооздаваемой директории
                bool dirExists = false;                                                       // флаг существования файлов с таким именем
                // цикл прохода по текущей директории для поиска директории с таким именем
                foreach (QFileInfo dirs, qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
                {
                    if (dirs.fileName() == isDir.getName()) // если директория с таким именем найдена
                    {
                        dirExists = true; // флаг существования директории принимает истинное значение
                        break;
                    }
                }
                if (!dirExists) // если директорий с таким именем нет
                {
                    if (!dir->create(createPath)) // если директория не создана
                        throw PerformationException("Create Directory", "The operation <<Create>> was not perfomed!");
                }
                else
                    throw PerformationException("Create Directory", "A directory with this name exist!");
            }
            if (window.getLink())
            {
                RenameWindow isLink;
                isLink.exec();                                                                 // выполняет появление окна для создания имени
                QString createPath = qDir.absolutePath().append("/").append(isLink.getName()); // получение пути соозданного файла
                LinkedPathWindow window;
                window.exec();                         // выполняет появление окна для создания имени
                QString linkedPath = window.getPath(); // получение пути соозданного файла
                bool linkExists = false;               // флаг существования файлов с таким именем
                // цикл прохода по текущей директории для поиска файлов с таким именем
                foreach (QFileInfo links, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                {
                    if (links.fileName() == isLink.getName()) // если файл с таким именем найден
                    {
                        linkExists = true; // флаг существования файла принимает истинное значение
                        break;
                    }
                }
                if (!linkExists) // если файлов с таким именем нет
                {
                    QString path = "";
                    if (!link->create(path.append(linkedPath).append(" ").append(createPath))) // если файл не создан
                        throw PerformationException("Create Symbol Link", "The operation <<Create>> was not perfomed!");
                }
                else
                    throw PerformationException("Create Symbol Link", "A symbol link with this name exists!");
            }
        }
    }
    catch (PerformationException error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Create", "Unknown error! Please try again!");
    }
}

bool recursiveDelete(QDir& qDir, System* file, System* dir, System* link) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, qDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
            qDir.cd(info.fileName());               // заходим в нее
            recursiveDelete(qDir, file, dir, link); // рекурсивно удаляем внутренности
            // теперь папка пуста и мы можем ее удалить
            if (!dir->r_move(qDir.absolutePath()))
                return false;
            qDir.cdUp(); // возврат
        }
        else if (info.isFile()) // если текущий объект - файл
        {
            if (!file->r_move(info.absoluteFilePath())) // если файл не удален
                return false;
        }
        else if (info.isSymLink()) // если текущий объект - файл
        {
            if (!link->r_move(info.absoluteFilePath())) // если файл не удален
                return false;
        }
    }
    return true;
}

void MainWindow::on_btnDelete_clicked() // слот нажатия на кнопку "Delete"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    try
    {
        if (qDir.absolutePath() == "/home/h4thqewjtch/qt/build-File-Desktop-Debug") // если это корневая директория
            QMessageBox::warning(this, "Delete", "You are in a root directory! Please choose an another directory");
        else
        {
            if (filePath == "" && dirPath == "" && linkPath == "") // если не выбран ни один объект
                throw ChoiseException("Delete", "You was not choose a file or a directory! Please try again");
            else if (filePath != "" && dirPath == "" && linkPath == "") // если выбран файл
            {
                QMessageBox::StandardButton btn = QMessageBox::question(this, "Delete", "Do you want to perform <<Delete>> operation?", QMessageBox::Ok | QMessageBox::Cancel);
                if (btn == QMessageBox::Cancel)
                    throw PerformationException("Delete FIle", "The operation was canceled!");
                else
                {
                    if (!file->r_move(filePath)) // удаление файла
                        throw PerformationException("Delete File", "The operation <<Delete>> was not perfomed!");
                    filePath = fileName = ""; // очистка пути файла
                }
            }
            else if (filePath == "" && dirPath != "" && linkPath == "") // если выбрана директория
            {
                ConfirmDelete window;
                window.exec();            // метод выполняет появление окна для подтверждения удаления
                if (!window.getConfirm()) // если операция отменена
                    throw PerformationException("Delete Directory", "The operation was canceled!");
                else
                {
                    QDir qDir = QDir(dirPath); // получение выбранной директории
                    if (!qDir.isEmpty())       // если директория не пуста
                    {
                        if (!recursiveDelete(qDir, file, dir, link)) // если внутренние файлы не удалены
                            throw PerformationException("Delete Directory", "The operation <<Delete>> was not perfomed!");
                    }
                    if (qDir.isEmpty()) // если директория пуста
                    {
                        if (!dir->r_move(dirPath)) // если удаление не выпонено
                            throw PerformationException("Delete Directory", "The operation <<Delete>> was not perfomed!");
                        dirPath = dirName = ""; // очистка пути директории
                    }
                }
            }
            else if (filePath == "" && dirPath == "" && linkPath != "") // если выбран файл
            {
                ConfirmDelete window;
                window.exec();            // метод выполняет появление окна для подтверждения удаления
                if (!window.getConfirm()) // если операция отменена
                    throw PerformationException("Delete Symbol Link", "The operation was canceled!");
                else
                {
                    if (!link->r_move(linkPath)) // если удаление не выпонено
                        throw PerformationException("Delete Symbol Link", "The operation <<Delete>> was not perfomed!");
                    linkPath = linkName = ""; // очистка пути файла
                }
            }
        }
    }
    catch (ChoiseException error)
    {
        error.getException(this);
    }
    catch (PerformationException error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Delete", "Unknown error! Please try again!");
    }
}

void recursiveCopyList(QDir& dir, QFileInfoList& copyList) // функция рекурсивного наполнения содержимым списка для копирования
{
    // цикл прохода по текущей директории для создания контейнера с файлами и директориями внутри
    foreach (QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        copyList.append(info); // добавление элемента в контейнеp
        if (info.isDir())      // элемент - директория
        {
            dir.cd(info.fileName());          // заходим в нее
            recursiveCopyList(dir, copyList); // рекурсивно копируем содержимое
            dir.cdUp();                       // возврат
        }
    }
}

void MainWindow::on_btnCopy_clicked() // слот нажатия на кнопку "Сopy"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    try
    {
        if (fileName == "" && dirName == "" && linkName == "") // если не выбран ни один объект
            throw ChoiseException("Copy", "You was not choose a file or a directory! Please try again");
        else if (fileName != "" && dirName == "" && linkName == "") // если выбран файл
        {
            QString copyPath = rDir.absolutePath().append("/").append(fileName); // создание пути для копирования
            bool fileExists = false;                                             // флаг существования файла с таким именем
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo files, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (files.fileName() == fileName) // если файл с таким именем есть
                {
                    fileExists = true; // установка флаг на истинное значение
                    break;
                }
            }
            if (!fileExists) // если файлов с таким именем нет
            {
                if (!file->copy(filePath, copyPath)) // если копирование не произошло
                    throw PerformationException("Copy File", "The operation <<Copy>> was not perfomed!");
                filePath = fileName = ""; // очистка пути файла
            }
            else
                throw PerformationException("Copy File", "A file with this name exists!");
        }
        else if (fileName == "" && dirName != "" && linkName == "") // если выбрана директория
        {
            QFileInfoList copyList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
            recursiveCopyList(lDir, copyList);        // рекурсивное наполнение контейнера внутренними файлами директор
            bool dirExists = false;                   // флаг существования директорий с таким именем
            // проход по выбранной директории для поиска директории с именем копируемой
            foreach (QFileInfo dirs, rDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (dirs.fileName() == dirName) // если диреткория существует
                {
                    dirExists = true; // установка флага на истинное значение
                    break;
                }
            }
            if (!dirExists) // если директорий с таким именем нет
            {
                rDir.mkdir(dirName); // создание копии директории по выбранному пути
                rDir.cd(dirName);
                // цикл копирования элементов контейнера в созданную директорию
                foreach (QFileInfo info, copyList)
                {
                    QString copyPath = info.filePath().replace(lDir.absolutePath(), rDir.absolutePath()); // создание пути для копирования
                    if (info.isFile())                                                                    // текущий элемент контейнера - файл
                    {
                        if (!file->copy(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
                            throw PerformationException("Copy File", "The operation <<Copy>> was not perfomed!");
                    }
                    if (info.isDir()) // если текущий элемент - директория
                    {
                        if (!dir->copy(info.dir().dirName(), copyPath)) // если копирование не выполнено
                            throw PerformationException("Copy Directory", "The operation <<Copy>> was not perfomed!");
                    }
                    if (info.isSymLink())
                    {
                        if (!link->copy(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
                            throw PerformationException("Copy Symbol Link", "The operation <<Copy>> was not perfomed!");
                    }
                }
                filePath = fileName = "";
                dirPath = dirName = "";
                linkPath = linkName = "";
            }
            else
                throw PerformationException("Copy Directory", "A directory with this name exists!");
        }
        else if (fileName == "" && dirName == "" && linkName != "") // если выбран файл
        {
            QString copyPath = rDir.absolutePath().append("/").append(linkName); // создание пути для копирования
            bool linkExists = false;                                             // флаг существования файла с таким именем
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo links, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (links.fileName() == linkName) // если файл с таким именем есть
                {
                    linkExists = true; // установка флаг на истинное значение
                    break;
                }
            }
            if (!linkExists) // если файлов с таким именем нет
            {
                if (!link->copy(linkPath, copyPath)) // если копирование не произошло
                    throw PerformationException("Copy Symbol Link", "The operation <<Copy>> was not perfomed!");
                linkPath = linkName = ""; // очистка пути файла
            }
            else
                throw PerformationException("Copy Symbol Link", "A symbol link with this name exists!");
        }
    }
    catch (ChoiseException error)
    {
        error.getException(this);
    }
    catch (PerformationException error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Copy", "Unknown error! Please try again!");
    }
}

void MainWindow::on_btnReplace_clicked() // слот нажатия на кнопку "Replace"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    try
    {
        if (fileName == "" && dirName == "" && linkName == "") // если не выбран ни один объект
            throw ChoiseException("Replace", "You was not choose a file or a directory! Please try again");
        else if (fileName != "" && dirName == "" && linkName == "") // если выбран файл
        {
            QString newPath = rDir.absolutePath().append("/").append(fileName); // создание пути для перемещения
            bool fileExists = false;                                            // флаг существования файла с таким именем
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo files, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (files.fileName() == fileName) // если файл с таким именем есть
                {
                    fileExists = true; // установка флаг на истинное значение
                    break;
                }
            }
            if (!fileExists) // если файлов с таким именем нет
            {
                if (!file->copy(filePath, newPath)) // если копирование не произошло
                    throw PerformationException("Replace File", "The operation <<Copy>> was not perfomed!");
                if (!file->r_move(filePath)) // если удаление не произошло
                    throw PerformationException("Replace File", "The operation <<Delete>> was not perfomed!");
                filePath = fileName = ""; // очистка пути файла
            }
            else
                throw PerformationException("Replace File", "A file with this name exists!");
        }
        else if (fileName == "" && dirName != "" && linkName == "") // если выбрана директория
        {
            QFileInfoList replaceList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
            recursiveCopyList(lDir, replaceList);        // рекурсивное наполнение контейнера внутренними файлами директории
            bool dirExists = false;                      // флаг существования директорий с таким именем
            // проход по выбранной директории для поиска директории с именем копируемой
            foreach (QFileInfo dirs, rDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (dirs.fileName() == dirName) // если диреткория существует
                {
                    dirExists = true; // установка флага на истинное значение
                    break;
                }
            }
            if (!dirExists) // если директорий с таким именем нет
            {
                rDir.mkdir(dirName); // создание копии директории по выбранному пути
                rDir.cd(dirName);
                // цикл копирования элементов контейнера в созданную директорию
                foreach (QFileInfo info, replaceList)
                {
                    QString replacePath = info.filePath().replace(lDir.absolutePath(), rDir.absolutePath()); // создание пути для копирования
                    if (info.isFile())                                                                       // текущий элемент контейнера - файл
                    {
                        if (!file->copy(info.absoluteFilePath(), replacePath)) // если копирование не выполнено
                            throw PerformationException("Replace File", "The operation <<Copy>> was not perfomed!");
                    }
                    if (info.isDir()) // если текущий элемент - директория
                    {
                        if (!dir->copy(info.dir().dirName(), replacePath)) // если копирование не выполнено
                            throw PerformationException("Replace Directory", "The operation <<Copy>> was not perfomed!");
                    }
                    if (info.isSymLink()) //если
                    {
                        if (!link->copy(info.absoluteFilePath(), replacePath)) // если копирование не выполнено
                            throw PerformationException("Replace Symbol Link", "The operation <<Copy>> was not perfomed!");
                    }
                }
                if (!lDir.isEmpty()) // если директория не пуста
                {
                    if (!recursiveDelete(lDir, file, dir, link)) // если внутренние файлы не удалены
                        throw PerformationException("Replace Directory", "The operation <<Delete>> was not perfomed!");
                }
                if (lDir.isEmpty()) // если директория пуста
                {
                    if (!dir->r_move(dirPath)) // если удаление не выпонено
                        throw PerformationException("Replace Directory", "The operation <<Delete>> was not perfomed!");
                    dirPath = dirName = ""; // очистка пути директории
                }
                filePath = fileName = "";
                dirPath = dirName = "";
                linkPath = linkName = "";
            }
            else
                throw PerformationException("Replace Directory", "A directory with this name exists!");
        }
        else if (fileName == "" && dirName == "" && linkName != "") // если выбран файл
        {
            QString newPath = rDir.absolutePath().append("/").append(linkName); // создание пути для перемещения
            bool linkExists = false;                                            // флаг существования файла с таким именем
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo links, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            {
                if (links.fileName() == linkName) // если файл с таким именем есть
                {
                    linkExists = true; // установка флаг на истинное значение
                    break;
                }
            }
            if (!linkExists) // если файлов с таким именем нет
            {
                if (!link->copy(linkPath, newPath)) // если копирование не произошло
                    throw PerformationException("Replace Symbol Link", "The operation <<Copy>> was not perfomed!");
                if (!link->r_move(linkPath)) // если удаление не произошло
                    throw PerformationException("Replace Symbol Link", "The operation <<Delete>> was not perfomed!");
                linkPath = linkName = ""; // очистка пути файла
            }
            else
                throw PerformationException("Replace Symbol Link", "A symbol link with this name exists!");
        }
    }
    catch (ChoiseException error)
    {
        error.getException(this);
    }
    catch (PerformationException error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Replace", "Unknown error! Please try again!");
    }
}

void MainWindow::on_btnRename_clicked() // слот нажатия на кнопку "Rename"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    try
    {
        if (qDir.absolutePath() == "/home/h4thqewjtch/qt/build-File-Desktop-Debug") // если это корневая директория
            QMessageBox::warning(this, "Rename", "You are in a root directory! Please choose an another directory");
        else
        {
            if (filePath == "" && dirPath == "" && linkPath == "") // если не выбран ни один объект
                throw ChoiseException("Rename", "You was not choose a file or a directory! Please try again");
            else if (filePath != "" && dirPath == "" && linkPath == "") // если выбран файл
            {
                RenameWindow name;
                name.exec();              // метод выполняет появление окна для переименования файла
                if (name.getName() == "") // если имя не введено
                    throw ExceptionEmpty("Rename File", "A new file name is empty! Please try again");
                else
                {
                    QString newPath = qDir.absolutePath().append("/").append(name.getName()); // создание нового пути с учетом переименования
                    bool fileExists = false;                                                  // флаг существования файла с таким именем
                    // цикл прохода по текущей директории для поиска файлов с таким именем
                    foreach (QFileInfo files, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                    {
                        if (files.fileName() == name.getName()) // если файл с таким именем есть
                        {
                            fileExists = true; // установка флаг на истинное значение
                            break;
                        }
                    }
                    if (!fileExists) // если файлов с таким именем нет
                    {
                        if (!file->r_name(filePath, newPath)) // если переименование не произошло
                            throw PerformationException("Rename File", "The operation <<Rename>> was not perfomed!");
                        filePath = fileName = ""; // очистка пути файла
                    }
                    else
                        throw PerformationException("Rename File", "A file with this name exists!");
                }
            }
            else if (filePath == "" && dirPath != "" && linkPath == "") // если выбрана директория
            {
                RenameWindow name;
                name.exec();              // метод выполняет появление окна для переименования директории
                if (name.getName() == "") // если имя не введено
                    throw ExceptionEmpty("Rename Directory", "A new directory name is empty! Please try again");
                else
                {
                    QString newPath = qDir.absolutePath().append("/").append(name.getName()); // создание нового пути с учетом переименования
                    bool dirExists = false;                                                   // флаг существования директории с таким именем
                    // цикл прохода по выбранной директории для поиска директории с таким именем
                    foreach (QFileInfo dirs, qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
                    {
                        if (dirs.fileName() == name.getName()) // если директория с таким именем есть
                        {
                            dirExists = true; // установка флаг на истинное значение
                            break;
                        }
                    }
                    if (!dirExists) // если директорий с таким именем нет
                    {
                        if (!dir->r_name(dirPath, newPath)) // если переименование не произошло
                            throw PerformationException("Rename Directory", "The operation <<Rename>> was not perfomed!");
                        dirPath = dirName = ""; // очистка пути директории
                    }
                    else
                        throw PerformationException("Rename Directory", "A directory with this name exists!");
                }
            }
            else if (filePath == "" && dirPath == "" && linkPath != "") // если выбран файл
            {
                RenameWindow name;
                name.exec();              // метод выполняет появление окна для переименования файла
                if (name.getName() == "") // если имя не введено
                    throw ExceptionEmpty("Rename Symbol Link", "A new symbol link name is empty! Please try again");
                else
                {
                    QString newPath = qDir.absolutePath().append("/").append(name.getName()); // создание нового пути с учетом переименования
                    bool linkExists = false;                                                  // флаг существования файла с таким именем
                    // цикл прохода по текущей директории для поиска файлов с таким именем
                    foreach (QFileInfo links, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                    {
                        if (links.fileName() == name.getName()) // если файл с таким именем есть
                        {
                            linkExists = true; // установка флаг на истинное значение
                            break;
                        }
                    }
                    if (!linkExists) // если файлов с таким именем нет
                    {
                        if (!link->r_name(linkPath, newPath)) // если переименование не произошло
                            throw PerformationException("Rename Symbol Link", "The operation <<Rename>> was not perfomed!");
                        linkPath = linkName = ""; // очистка пути файла
                    }
                    else
                        throw PerformationException("Rename Symbol Link", "A symbol link with this name exists!");
                }
            }
        }
    }
    catch (ChoiseException error)
    {
        error.getException(this);
    }
    catch (PerformationException error)
    {
        error.getException(this);
    }
    catch (ExceptionEmpty error)
    {
        error.getException(this);
    }
    catch (...)
    {
        QMessageBox::warning(this, "Rename", "Unknown error! Please try again!");
    }
}

void MainWindow::on_lineSearch_textEdited(const QString& arg1) // слот ввода имени для поиска
{
    window->setName(arg1);
}

void MainWindow::on_btnSearch_clicked() // слот нажатия на кнопку "Search"
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    window->search(lDir);
    // window->setUi();
    window->search(rDir);
    window->setUi();
    window->exec();
    window->resetUi();
}
