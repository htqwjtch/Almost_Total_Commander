#include "form.h"
#include "../src/modules/creatingModule/creatingmodule.h"
#include "other_functions.h"
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

    copyingModule = new CopyingModule(this);
    removingModule = new RemovingModule(this);
    replacingModule = new ReplacingModule(this);
    searchingModule = new SearchingModule(this);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QObject::connect(copyingModule, SIGNAL(copyingIsPerformedSignal()), this, SLOT(copyingIsPerformed()));
    QObject::connect(copyingModule, SIGNAL(copyingIsNotPerformedSignal()), this, SLOT(copyingIsNotPerformed()));

    QObject::connect(removingModule, SIGNAL(removingIsPerformedSignal()), this, SLOT(removingIsPerformed()));
    QObject::connect(removingModule, SIGNAL(removingIsNotPerformedSignal()), this, SLOT(removingIsNotPerformed()));

    QObject::connect(replacingModule, SIGNAL(replacingIsPerformedSignal()), this, SLOT(replacingIsPerformed()));
    QObject::connect(replacingModule, SIGNAL(replacingIsNotPerformedSignal()), this, SLOT(replacingIsNotPerformed()));

    QObject::connect(searchingModule, SIGNAL(searchingIsPerformedSignal()), this, SLOT(searchingIsPerformed()));

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // устанока информации для подсказок
    ui->btnCreate->setToolTip("Create");
    ui->btnRemove->setToolTip("Remove");
    ui->btnCopy->setToolTip("Copy");
    ui->btnReplace->setToolTip("Replace");
    ui->btnRename->setToolTip("Rename");

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
    delete searchingModule;
    delete replacingModule;
    delete removingModule;
    delete copyingModule;

    delete model;
    delete ui;
}

void Form::btn_create()
{
    on_btnCreate_clicked();
}

void Form::btn_remove()
{
    on_btnRemove_clicked();
}

void Form::btn_copy()
{
    on_btnCopy_clicked();
}

void Form::btn_replace()
{
    on_btnReplace_clicked();
}

void Form::btn_rename()
{
    on_btnRename_clicked();
}

void Form::btn_search()
{
    on_btnSearch_clicked();
}

void Form::on_lvLeft_clicked(const QModelIndex& index)
{
    view = (QListView*)sender();
    QFileInfo info = model->fileInfo(index); // получение пути элемента, который соответствует этому индексу
    if (info.isSymLink() || info.isFile()) // выбранный объект - файл
    {
        if (!dirPath.isEmpty()) // если до этого была выбрана директория
            dirPath.clear();
        init_infoBar(info, ui->lblSize, ui->lblType, ui->lblDate);
        filePath = model->filePath(index); // установка пути выбранного файла
    }
    else if (!info.fileName().compare(".") || !info.fileName().compare(".."))
    {
        filePath.clear();
        dirPath.clear();
        ui->lblSize->clear();
        ui->lblType->clear();
        ui->lblDate->clear();
    }
    else if (info.isDir()) // если выбранный объект - директория
    {
        QDir dir = QDir(model->filePath(index));
        if (!filePath.isEmpty()) // если до этого был выбран файл
            filePath.clear();    // очистка пути файл
        QString count = "";
        count = count.append(QString::number(dir.count() - 2)).append(" item");
        if (dir.count() > 3)
            count = count.append("s");
        ui->lblSize->setText(count);
        ui->lblType->setText("Type: directory");                    // отображение типа объекта
        QString format = "dddd, d MMMM yy hh:mm:ss";                // формат вывода даты последнего изменения
        ui->lblDate->setText(info.lastModified().toString(format)); // вывод даты последнего изменения
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
        if (!dirPath.isEmpty())                                   // если до этого выбрана директория
            dirPath.clear();                                      // очистка пути директории
        QDesktopServices::openUrl(QUrl::fromUserInput(filePath)); // открывает файл
        filePath.clear();                                         // очистка пути файла
    }
    else if (info.isDir()) // если выбранный элемент - директория
    {
        if (!filePath.isEmpty()) // если до этого был выбран файл
            filePath.clear();    // очистка пути файла
        if (!info.fileName().compare("."))
        {
            view->setRootIndex(model->index("")); // переход в корневую папre (показать корневую папку)
            info = model->fileInfo(model->index(""));
        }
        else if (!info.fileName().compare(".."))
        {
            QDir qDir = info.dir(); // получение объекта класса QDir
            qDir.cd(".."); // dir.cdUp();  навигация. в данном случае переход в родительскую папку
            view->setRootIndex(model->index(qDir.absolutePath())); // получение индекса по пути
        }
        else
	{
	    view->setRootIndex(index);
	} // элемент с этим индексом становится корневым
	var->setText(info.absoluteFilePath()); // отображение нового пути
	dirPath.clear();                       //очистка пути директории
    }
}

void Form::on_btnCreate_clicked()
{
    QDir leftPanelDirectory = QDir(model->filePath(ui->lvLeft->rootIndex())); //получение текущей директории
    QDir rightPanelDirectory = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir currentDirectory;
    if (view == ui->lvLeft)
    {
        currentDirectory = leftPanelDirectory;
    }
    if (view == ui->lvRight)
    {
        currentDirectory = rightPanelDirectory;
    }
    if (currentDirectory.absolutePath().contains(currentDirectory.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !currentDirectory.absolutePath().contains(currentDirectory.homePath())) // если это корневая директория
    {
        QMessageBox::warning(this, "Creation", "There is no access to perform any operation in the current directory!");
        return;
    }
    CreatingModule creatingModule = CreatingModule(currentDirectory);
    creatingModule.exec();
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
    {
        QMessageBox::warning(this, "Remove", "There is no access to perform any operation in this directory!");
        return;
    }
    if (filePath.isEmpty() && dirPath.isEmpty()) // если не выбран ни один объект
    {
        QMessageBox::warning(this, "Remove", "You was not choose a file or a directory! Please try again");
        return;
    }
    QMessageBox::StandardButton btn
        = QMessageBox::question(this, "Remove", "Do you want to perform operation?", QMessageBox::Cancel | QMessageBox::Ok);
    if (btn == QMessageBox::Cancel)
    {
        filePath.clear(); // очистка пути файла
        dirPath.clear();  // очистка пути директории
        return;
    }
    QFileInfo data;
    if (!filePath.isEmpty()) // если выбран файл
    {
	data = QFileInfo(filePath);
    }
    else if (!dirPath.isEmpty()) // если выбрана директория
    {
	data = QFileInfo(dirPath);
    }
    ui->btnRemove->setEnabled(false);
    removingModule->remove(data.absoluteFilePath());
    filePath.clear(); // очистка пути файла
    dirPath.clear();  // очистка пути директории
}

void Form::on_btnCopy_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    if (lDir.absolutePath().contains(lDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || rDir.absolutePath().contains(rDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !lDir.absolutePath().contains(lDir.homePath()) || !rDir.absolutePath().contains(rDir.homePath()))
    {
        QMessageBox::warning(this, "Copy", "There is no access to perform any operation in this directory!");
        filePath.clear(); // очистка пути файла
        dirPath.clear();
        return;
    }
    if (filePath.isEmpty() && dirPath.isEmpty()) // если не выбран ни один объект
    {
        QMessageBox::warning(this, "Copy", "You was not choose a file or a directory! Please try again");
        return;
    }
    QFileInfo data;
    if (!filePath.isEmpty()) // если выбран файл
    {
        data = QFileInfo(filePath);
    }
    else if (!dirPath.isEmpty()) // если выбрана директория
    {
        data = QFileInfo(dirPath);
    }
    foreach (QFileInfo info, rDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
        if (info.fileName() == data.fileName()) // если файл с таким именем есть
        {
            QMessageBox::warning(this, "Copy", "A file or a directory with this name exists!");
            filePath.clear(); // очистка пути файла
            return;
        }
    }
    ui->btnCopy->setEnabled(false);
    copyingModule->copy(data.absoluteFilePath(), rDir.absolutePath());

    filePath.clear(); // очистка пути файла
    dirPath.clear();
}

void Form::on_btnReplace_clicked()
{
    QDir lDir = QDir(model->filePath(ui->lvLeft->rootIndex())); // получение текущей директории
    QDir rDir = QDir(model->filePath(ui->lvRight->rootIndex()));
    if (lDir.absolutePath().contains(lDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || rDir.absolutePath().contains(rDir.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
        || !lDir.absolutePath().contains(lDir.homePath()) || !rDir.absolutePath().contains(rDir.homePath()))
    {
        QMessageBox::warning(this, "Replace", "There is no access to perform any operation in this directory!");
        filePath.clear(); // очистка пути файла
        dirPath.clear();
        return;
    }
    if (filePath.isEmpty() && dirPath.isEmpty()) // если не выбран ни один объект
    {
        QMessageBox::warning(this, "Replace", "You was not choose a file or a directory! Please try again");
        return;
    }
    QFileInfo data;
    if (!filePath.isEmpty()) // если выбран файл
    {
        data = QFileInfo(filePath);
    }
    else if (!dirPath.isEmpty()) // если выбрана директория
    {
        data = QFileInfo(dirPath);
    }
    foreach (QFileInfo info, rDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
        if (info.fileName() == data.fileName()) // если файл с таким именем есть
        {
            QMessageBox::warning(this, "Replace", "A file or a directory with this name exists!");
            filePath.clear(); // очистка пути файла
            return;
        }
    }
    ui->btnReplace->setEnabled(false);
    replacingModule->setReplacingObjectPath(data.absoluteFilePath());
    replacingModule->replaceIn(rDir.absolutePath());

    filePath.clear(); // очистка пути файла
    dirPath.clear();
}

void Form::on_btnRename_clicked()
{
    QDir leftPanelDirectory = QDir(model->filePath(ui->lvLeft->rootIndex()));
    QDir rightPanelDirectory = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir currentDirectory;
    if (view == ui->lvLeft)
	currentDirectory = leftPanelDirectory;
    if (view == ui->lvRight)
	currentDirectory = rightPanelDirectory;
    if (currentDirectory.absolutePath().contains(currentDirectory.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
	|| !currentDirectory.absolutePath().contains(currentDirectory.homePath()))
    {
        QMessageBox::warning(this, "Rename", "There is no access to perform any operation in this directory!");
        return;
    }
    if (filePath.isEmpty() && dirPath.isEmpty())
    {
        QMessageBox::warning(this, "Rename", "You was not choose a file or a directory! Please try again");
        return;
    }
    NamingModule namingModule;
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.setNameAndPathForNotSymbolLink();
    if (namingModule.getName().isEmpty()) // если имя не введено
    {
        filePath.clear();
        dirPath.clear();
        return;
    }
    foreach (QFileInfo info, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (info.fileName() == namingModule.getName()) // если файл с таким именем есть
	{
	    QMessageBox::warning(this, "Rename", "A file or a directory with this name exists!");
            filePath.clear();
            dirPath.clear();
            return;
	}
    }
    if (!filePath.isEmpty())                                                   // если выбран файл
    {
	if (!QFile::rename(filePath, namingModule.getPath())) // если переименование не произошло
	    QMessageBox::warning(this, "Rename", "The operation was not perfomed!");
	filePath.clear(); // очистка пути файла
    }
    else if (!dirPath.isEmpty()) // если выбрана директория
    {
	if (!currentDirectory.rename(dirPath, namingModule.getPath())) // если переименование не произошло
	    QMessageBox::warning(this, "Rename", "The operation was not perfomed!");
	dirPath.clear(); // очистка пути директории
    }
}

void Form::on_lineSearch_textEdited(const QString& arg1)
{
    searchName = arg1;
}

void Form::on_btnSearch_clicked()
{
    QDir leftPanelDirectory = QDir(model->filePath(ui->lvLeft->rootIndex()));
    QDir rightPanelDirectory = QDir(model->filePath(ui->lvRight->rootIndex()));
    QDir currentDirectory;
    if (view == ui->lvLeft)
	currentDirectory = leftPanelDirectory;
    if (view == ui->lvRight)
	currentDirectory = rightPanelDirectory;
    if (currentDirectory.absolutePath().contains(currentDirectory.homePath().append("/kypck/build-FileManager-Desktop_Qt_6_5_0_GCC_64bit-Debug"))
	|| !currentDirectory.absolutePath().contains(currentDirectory.homePath()))
    {
	QMessageBox::warning(this, "Rename", "There is no access to perform any operation in this directory!");
	return;
    }

    ui->btnSearch->setEnabled(false);
    searchingModule->search(searchName, currentDirectory.absolutePath());
    //QMessageBox::warning(this, "", "There is no access to perform a search in this directory!");
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

void Form::removingIsNotPerformed()
{
    ui->btnRemove->setEnabled(true);
    QMessageBox::warning(this, "Removing", "The operation is not performed!");
}

void Form::copyingIsNotPerformed()
{
    ui->btnCopy->setEnabled(true);
    QMessageBox::warning(this, "Copying", "The operation is not performed!");
}

void Form::replacingIsNotPerformed()
{
    ui->btnReplace->setEnabled(true);
    QMessageBox::warning(this, "Replacing", "The operation is not performed!");
}

void Form::removingIsPerformed()
{
    ui->btnRemove->setEnabled(true);
}

void Form::copyingIsPerformed()
{
    ui->btnCopy->setEnabled(true);
}

void Form::replacingIsPerformed()
{
    ui->btnReplace->setEnabled(true);
}

void Form::searchingIsPerformed()
{
    ui->btnSearch->setEnabled(true);
    searchingModule->exec();
}
