#include "../form/form.h"
#include "../createChoice/createchoice.h"
#include "../linkedPath/linkedpath.h"
#include "../newName/newname.h"
#include "ui_form.h"

#include <unistd.h>

#include <QDesktopServices>
#include <QMessageBox>

Form::Form(QWidget* parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this); // настраивает пользовательский интерфейс для указанного виджета

    if (!(model = new QFileSystemModel(this))) // выделение памяти под указатель на объект этого класса
        QMessageBox::warning(this, "Memory allocation", "Model of QFileSystemModel was not created!");

    model->setFilter(QDir::QDir::AllEntries); //отображать некоторые элементы файловой системы(в нашем случае все)
    model->setRootPath("/"); // определить место в системе для отслеживания изменений(указана корневая папка)

    ui->lvLeft->setModel(model); // назначение *model объектом представления панели Source
    ui->lvRight->setModel(model);

    connect(ui->lvRight, SIGNAL(clicked(QModelIndex)), this, SLOT(on_lvLeft_clicked(QModelIndex)));
    connect(ui->lvRight, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_lvLeft_doubleClicked(QModelIndex)));

    connect(ui->rightPath, SIGNAL(textEdited(QString)), this, SLOT(on_leftPath_textEdited(QString)));

    if (!(threadCopy = new QThread(this)))
        QMessageBox::warning(this, "Memory allocation", "Object of QThread was not created!");
    connect(this, SIGNAL(destroyed()), threadCopy, SLOT(quit()));

    if (!(threadRemove = new QThread(this)))
        QMessageBox::warning(this, "Memory allocation", "Object of QThread was not created!");
    connect(this, SIGNAL(destroyed()), threadRemove, SLOT(quit()));

    if (!(threadSearch = new QThread(this)))
        QMessageBox::warning(this, "Memory allocation", "Object of QThread was not created!");
    connect(this, SIGNAL(destroyed()), threadSearch, SLOT(quit()));

    //	if (!(window = new SearchWindow(this)))
    //	    throw BadAllocException("Memory allocation", "Object of SearchWindow was not created!");

    if (!(thCopy = new ThreadToCopy()))
        QMessageBox::warning(this, "Memory allocation", "Object of ThreadToCopy was not created!");
    connect(this, SIGNAL(startCopy(QDir, QDir, SysElem*, SysElem*, QString)), thCopy, SLOT(runCopy(QDir, QDir, SysElem*, SysElem*, QString)));
    thCopy->moveToThread(threadCopy);
    threadCopy->start();

    if (!(thRemove = new ThreadToRemove()))
        QMessageBox::warning(this, "Memory allocation", "Object of ThreadToRemove was not created!");
    connect(this, SIGNAL(startRemove(SysElem*, SysElem*, QString)), thRemove, SLOT(runRemove(SysElem*, SysElem*, QString)));
    thRemove->moveToThread(threadRemove);
    threadRemove->start();

    if (!(thSearch = new ThreadToSearch()))
        QMessageBox::warning(this, "Memory allocation", "Object of ThreadToSearch was not created!");
    connect(this, SIGNAL(startSearch(QString, QString, QString)), thSearch, SLOT(runSearch(QString, QString, QString)));
    thSearch->moveToThread(threadSearch);
    threadSearch->start();

    // устанока информации для подсказок
    ui->btnCreate->setToolTip("Create");
    ui->btnRemove->setToolTip("Remove");
    ui->btnCopy->setToolTip("Copy");
    ui->btnReplace->setToolTip("Replace");
    ui->btnRename->setToolTip("Rename");
    ui->lineSearch->setToolTip("Please don't forget about the extension, if you want to enter a file name");

    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); //получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));

    lDir.cd(lDir.homePath());
    ui->lvLeft->setRootIndex(model->index(lDir.homePath()));
    rDir.cd(rDir.homePath());
    ui->lvRight->setRootIndex(model->index(rDir.homePath()));

    ui->leftPath->setText(lDir.homePath());  // отображение нового пути
    ui->rightPath->setText(rDir.homePath()); // отображение нового пути

    on_lvLeft_clicked(model->index(lDir.homePath()));
    view = ui->lvLeft;
}

Form::~Form()
{
    delete ui;
}

void Form::onBtnCreateClicked()
{
    on_btnCreate_clicked();
}

void Form::onBtnRemoveClicked()
{
    on_btnRemove_clicked();
}

void Form::onBtnCopyClicked()
{
    on_btnCopy_clicked();
}

void Form::onBtnReplaceClicked()
{
    on_btnReplace_clicked();
}

void Form::onBtnRenameClicked()
{
    on_btnRename_clicked();
}

void Form::onBtnSearchClicked()
{
    on_btnSearch_clicked();
}

void Form::on_lvLeft_clicked(const QModelIndex& index)
{
    view = (QListView*)sender();
    QFileInfo info = model->fileInfo(index); // получение пути элемента, который соответствует этому индексу
    if (info.isSymLink() || info.isFile()) // выбранный объект - файл
    {
        if (dirPath != "")          // если до этого была выбрана директория
            dirPath = dirName = ""; //очистка пути директории
        QString sizeFile = "";      // переменная размера файла
        if (info.size() < 1024)     // если размер файла меньше 1 килобайта
            sizeFile = sizeFile.append(QString::number(info.size())).append(" B"); // приведение размера к виду "B"
        else if (info.size() >= 1024 && info.size() < 1048576) // если размер файла больше 1 килобайта и меньше 1 мегабайта
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
        QString typeInfo = "Type : ";
        if (info.isSymLink())
            typeInfo = typeInfo.append("link ");
        else
            typeInfo = typeInfo.append("file ").append(info.suffix());
        ui->lblType->setText(typeInfo);    // отображениe типа файла
        fileName = model->fileName(index); // установка имени выбранного файла
        filePath = model->filePath(index); // установка пути выбранного файла
    }
    else if (info.fileName() == "." || info.fileName() == "..")
    {
        filePath = fileName = "";
        dirPath = dirName = "";
        ui->lblSize->clear();
        ui->lblType->clear();
        ui->lblDate->clear();
    }
    else if (info.isDir()) // если выбранный объект - директория
    {
        QDir dir = QDir(model->filePath(index));
        if (filePath != "")           // если до этого был выбран файл
            filePath = fileName = ""; // очистка пути файл
        QString count = "";
        count = count.append(QString::number(dir.count() - 2)).append(" item");
        if (dir.count() > 3)
            count = count.append("s");
        ui->lblSize->setText(count);
        ui->lblType->setText("Type: directory");                    // отображение типа объекта
        QString format = "dddd, d MMMM yy hh:mm:ss";                // формат вывода даты последнего изменения
        ui->lblDate->setText(info.lastModified().toString(format)); // вывод даты последнего изменения
        dirName = info.fileName();         // переменная для хранения имени выбранной директории
        dirPath = info.absoluteFilePath(); // переменная для хранения пути выбранной директории
    }
}

void Form::on_lvLeft_doubleClicked(const QModelIndex& index)
{
    view = (QListView*)sender(); // Возвращает указатель на объект, отправивший сигнал, если он вызван в слоте, активированном сигналом.
    QLineEdit* var;
    if (view == ui->lvLeft)
        var = ui->leftPath;
    if (view == ui->lvRight)
        var = ui->rightPath;
    QFileInfo info = model->fileInfo(index); // получение информации элемента, который соответствует этому индексу
    if (info.isFile()) // если выбранный элемент - файл
    {
        if (dirPath != "")                                        // если до этого выбрана директория
            dirPath = dirName = "";                               // очистка пути директории
        QDesktopServices::openUrl(QUrl::fromUserInput(filePath)); // открывает файл
        filePath = fileName = "";                                 // очистка пути файла
    }
    else if (info.isDir()) // если выбранный элемент - директория
    {
        if (filePath != "")           // если до этого был выбран файл
            filePath = fileName = ""; // очистка пути файла
        if (info.fileName() == ".")
        {
            view->setRootIndex(model->index("")); // переход в корневую папre (показать корневую папку)
            info = model->fileInfo(model->index(""));
        }
        else if (info.fileName() == "..")
        {
            QDir qDir = info.dir(); // получение объекта класса QDir
            qDir.cd(".."); // dir.cdUp();  навигация. в данном случае переход в родительскую папку
            view->setRootIndex(model->index(qDir.absolutePath())); // получение индекса по пути
        }
        else
            view->setRootIndex(index);         // элемент с этим индексом становится корневым
        var->setText(info.absoluteFilePath()); // отображение нового пути
        dirPath = dirName = "";                //очистка пути директории
    }
}

void Form::on_btnCreate_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); //получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    if (qDir.absolutePath().contains(qDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !qDir.absolutePath().contains(qDir.homePath())) // если это корневая директория
        QMessageBox::warning(this, "Create", "You in a root diretory! Please go to another directory and try again");
    else
    {
        CreateChoice window;
        window.exec(); // метод выполняет появление окна для выбора типа создаваемого объекта
        if (window.getFile()) // если был выбран файл
        {
            NewName isFile;
            isFile.exec(); // выполняет появление окна для создания имени
            QString createPath = qDir.absolutePath().append("/").append(isFile.getName()); // получение пути соозданного файла
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo files, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                if (files.fileName() == isFile.getName()) // если файл с таким именем найден
                {
                    QMessageBox::warning(this, "Create File", "A file with this name exists!");
                    return;
                }
            if (!file->create(createPath)) // если файл не создан
                QMessageBox::warning(this, "Create File", "The operation <b>\"Create\"</b> was not perfomed!");
        }
        if (window.getDir()) // если выбранный объект - директория
        {
            NewName isDir;
            isDir.exec(); // выполняет появление окна для создания имени
            QString createPath = qDir.absolutePath().append("/").append(isDir.getName()); // получение пути сооздаваемой директории
            // цикл прохода по текущей директории для поиска директории с таким именем
            foreach (QFileInfo dirs, qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
                if (dirs.fileName() == isDir.getName()) // если директория с таким именем найдена
                {
                    QMessageBox::warning(this, "Create Directory", "A directory with this name exist!");
                    return;
                }
            if (!dir->create(createPath)) // если директория не создана
                QMessageBox::warning(this, "Create Directory", "The operation <b>\"Create\"</b> was not perfomed!");
        }
        if (window.getLink())
        {
            NewName isLink;
            isLink.exec(); // выполняет появление окна для создания имени
            QString createPath = qDir.absolutePath().append("/").append(isLink.getName()); // получение пути соозданной ссылки
            LinkedPath window;
            window.exec();                         // выполняет появление окна для создания имени
            QString linkedPath = window.getPath(); // получение пути соозданной ссылкb
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo links, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                if (links.fileName() == isLink.getName()) // если файл с таким именем найден
                {
                    QMessageBox::warning(this, "Create Symbol Link", "A symbol link with this name exists!");
                    return;
                }
            QString cmd = "ln -s ";
            cmd = cmd.append(linkedPath).append(" ").append(createPath);
            if (system(cmd.toLocal8Bit().constData()) != 0)
                QMessageBox::warning(this, "Create Symbol Link", "The operation <b>\"Create\"</b> was not perfomed!");
        }
    }
}

void Form::on_btnRemove_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    if (qDir.absolutePath().contains(qDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !qDir.absolutePath().contains(qDir.homePath())) // если это корневая директория
        QMessageBox::warning(this, "Remove", "You in a root diretory! Please go to another directory and try again");
    else
    {
        if (filePath == "" && dirPath == "") // если не выбран ни один объект
        {
            QMessageBox::warning(this, "Remove", "You was not choose a file or a directory! Please try again");
            return;
        }
        QMessageBox::StandardButton btn
            = QMessageBox::question(this, "Remove", "Do you want to perform <b>\"Remove\"</b> operation?", QMessageBox::Cancel | QMessageBox::Ok);
        if (btn == QMessageBox::Cancel)
        {
            filePath = fileName = ""; // очистка пути файла
            dirPath = dirName = "";   // очистка пути директории
            return;
        }
        else if (filePath != "") // если выбран файл
        {
            if (!file->r_move(filePath)) // удаление файла
                QMessageBox::warning(this, "Remove File", "The operation <b>\"Remove\"</b> was not perfomed!");
            filePath = fileName = ""; // очистка пути файла
        }
        else if (dirPath != "") // если выбрана директория
        {
            emit startRemove(file, dir, dirPath);
            dirPath = dirName = ""; // очистка пути директории
        }
    }
}

void Form::on_btnCopy_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    if (lDir.absolutePath().contains(lDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || rDir.absolutePath().contains(rDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !lDir.absolutePath().contains(lDir.homePath()) || !rDir.absolutePath().contains(rDir.homePath()))
    {
        QMessageBox::warning(this, "Copy", "You in a root diretory! Please go to another directory and try again");
        filePath = fileName = ""; // очистка пути файла
        dirPath = dirName = "";
        return;
    }
    if (fileName == "" && dirName == "") // если не выбран ни один объект
        QMessageBox::warning(this, "Copy", "You was not choose a file or a directory! Please try again");
    else if (fileName != "") // если выбран файл
    {
        QString copyPath = rDir.absolutePath().append("/").append(fileName); // создание пути для копирования
        // цикл прохода по текущей директории для поиска файлов с таким именем
        foreach (QFileInfo files, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            if (files.fileName() == fileName) // если файл с таким именем есть
            {
                QMessageBox::warning(this, "Copy File", "A file with this name exists!");
                filePath = fileName = ""; // очистка пути файла
                return;
            }
        if (!file->c_py(filePath, copyPath)) // если копирование не произошло
            QMessageBox::warning(this, "Copy File", "The operation <b>\"Copy\"</b> was not perfomed!");
        filePath = fileName = ""; // очистка пути файла
    }
    else if (dirName != "") // если выбрана директория
    {
        QDir curDir = QDir(dirPath);
        // проход по выбранной директории для поиска директории с именем копируемой
        foreach (QFileInfo dirs, rDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
            if (dirs.fileName() == dirName) // если диреткория существует
            {
                QMessageBox::warning(this, "Copy Directory", "A directory with this name exists!");
                dirName = "";
                return;
            }
        emit startCopy(curDir, rDir, file, dir, dirName);
        dirPath = dirName = "";
    }
}

void Form::on_btnReplace_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    if (lDir.absolutePath().contains(lDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || rDir.absolutePath().contains(rDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !lDir.absolutePath().contains(lDir.homePath()) || !rDir.absolutePath().contains(rDir.homePath())) // если это корневая директория
    {
        QMessageBox::warning(this, "Replace", "You in a root diretory! Please go to another directory and try again");
        filePath = fileName = "";
        dirPath = dirName = "";
        return;
    }
    if (fileName == "" && dirName == "") // если не выбран ни один объект
    {
        QMessageBox::warning(this, "Replace", "You was not choose a file or a directory! Please try again");
        filePath = fileName = "";
        dirPath = dirName = "";
        return;
    }
    else if (fileName != "") // если выбран файл
    {
        QString copyPath = rDir.absolutePath().append("/").append(fileName); // создание пути для копирования
        // цикл прохода по текущей директории для поиска файлов с таким именем
        foreach (QFileInfo files, rDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
            if (files.fileName() == fileName) // если файл с таким именем есть
            {
                QMessageBox::warning(this, "Replace File", "A file with this name exists!");
                filePath = fileName = "";
                return;
            }
        if (!file->c_py(filePath, copyPath)) // если копирование не произошло
        {
            QMessageBox::warning(this, "Replace File", "The operation <b>\"Copy\"</b> was not perfomed!");
            filePath = fileName = "";
            return;
        }
    }
    else if (dirName != "") // если выбрана директория
    {
        QDir d = QDir(dirPath);
        emit startCopy(d, rDir, file, dir, dirName);
    }

    else if (filePath != "") // если выбран файл
    {
        if (!file->r_move(filePath)) // удаление файла
            QMessageBox::warning(this, "Replace File", "The operation <b>\"Remove\"</b> was not perfomed!");
        filePath = fileName = ""; // очистка пути файла
    }
    else if (dirPath != "") // если выбрана директория
    {
        emit startRemove(file, dir, dirPath);
        dirPath = dirName = "";
    }
}

void Form::on_btnRename_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir qDir;
    if (view == ui->lvLeft)
        qDir = lDir;
    if (view == ui->lvRight)
        qDir = rDir;
    if (qDir.absolutePath().contains(qDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !qDir.absolutePath().contains(qDir.homePath())) // если это корневая директория
        QMessageBox::warning(this, "Rename", "You in a root diretory! Please go to another directory and try again");
    else
    {
        if (filePath == "" && dirPath == "") // если не выбран ни один объект
            QMessageBox::warning(this, "Rename", "You was not choose a file or a directory! Please try again");
        else if (filePath != "") // если выбран файл
        {
            NewName name;
            name.exec();              // метод выполняет появление окна для переименования файла
            if (name.getName() == "") // если имя не введено
            {
                QMessageBox::warning(this, "Rename File", "A new file name is empty! Please try again");
                filePath = fileName = "";
                return;
            }
            QString newPath = qDir.absolutePath().append("/").append(name.getName()); // создание нового пути с учетом переименования
            // цикл прохода по текущей директории для поиска файлов с таким именем
            foreach (QFileInfo files, qDir.entryInfoList(QDir::Files | QDir::NoDotAndDotDot, QDir::Name))
                if (files.fileName() == name.getName()) // если файл с таким именем есть
                {
                    QMessageBox::warning(this, "Rename File", "A file with this name exists!");
                    filePath = fileName = "";
                    return;
                }
            if (!file->r_name(filePath, newPath)) // если переименование не произошло
                QMessageBox::warning(this, "Rename File", "The operation <b>\"Rename\"</b> was not perfomed!");
            filePath = fileName = ""; // очистка пути файла
        }
        else if (dirPath != "") // если выбрана директория
        {
            NewName name;
            name.exec(); // метод выполняет появление окна для переименования директории
            if (name.getName() == "") // если имя не введено
            {
                QMessageBox::warning(this, "Rename Directory", "A new directory name is empty! Please try again");
                dirPath = dirName = "";
                return;
            }
            QString newPath = qDir.absolutePath().append("/").append(name.getName()); // создание нового пути с учетом переименования
            // цикл прохода по выбранной директории для поиска директории с таким именем
            foreach (QFileInfo dirs, qDir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
                if (dirs.fileName() == name.getName()) // если директория с таким именем есть
                {
                    QMessageBox::warning(this, "Rename Directory", "A directory with this name exists!");
                    dirPath = dirName = "";
                    return;
                }
            if (!dir->r_name(dirPath, newPath)) // если переименование не произошло
                QMessageBox::warning(this, "Rename Directory", "The operation <b>\"Rename\"</b> was not perfomed!");
            dirPath = dirName = ""; // очистка пути директории
        }
    }
}

void Form::on_lineSearch_textEdited(const QString& arg1)
{
    searchName = arg1;
}

void Form::on_btnSearch_clicked()
{
    QString lDirPath = model->filePath(ui->lvLeft->rootIndex());
    QString rDirPath = model->filePath(ui->lvRight->rootIndex());
    QDir lDir = QDir(lDirPath); // получение текущей директории
    QDir rDir = QDir(rDirPath);
    if (lDirPath.contains(lDir.homePath()) && rDirPath.contains(rDir.homePath())
        && !lDirPath.contains(lDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        && !rDirPath.contains(rDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug")))
        emit startSearch(lDirPath, rDirPath, searchName);
    else
        QMessageBox::warning(this, "Search", "There is no access to perform a search in this directory!");
}

void Form::on_leftPath_textEdited(const QString& arg1)
{
    QLineEdit* line = (QLineEdit*)sender();
    if (line == ui->leftPath)
        view = ui->lvLeft;
    else if (line == ui->rightPath)
        view = ui->lvRight;
    QFileInfo fileInfo = model->fileInfo(model->index(arg1)); // получение информации элемента, который соответствует этому индексу
    if (fileInfo.isFile() || fileInfo.isSymLink()) // если выбранный элемент - файл или ссылка
        view->setRootIndex(model->index(fileInfo.absolutePath()));
    else if (fileInfo.isDir())
        view->setRootIndex(model->index(arg1)); // элемент с этим индексом становится корневым
}
