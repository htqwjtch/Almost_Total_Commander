#include "threadtoreplace.h"

ThreadToReplace::ThreadToReplace(QObject* parent) : QObject{parent} {}

void ThreadToReplace::run_replace(QDir rDir, const QString& filePath, const QString& dirPath)
{
    if (!filePath.isEmpty())
    {
	if (!QFile::copy(filePath, rDir.absolutePath())) // если копирование не произошло
	{
	    emit not_performed();
            return;
	}
	if (!QFile::remove(filePath))
	{
	    emit not_performed();
            return;
	}
    }
    else
    {
	c_py(rDir, dirPath);
	r_move(dirPath);
    }
    emit replace_finished();
}

void ThreadToReplace::c_py(QDir rDir, const QString& dirPath)
{
    QFileInfoList copyList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
    QDir lDir = QDir(dirPath);
    foreach (QFileInfo info, lDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
        copyList.append(info);                           // добавление элемента в контейнеp
    if (!rDir.mkdir(rDir.absolutePath().append(lDir.dirName()))) // если копирование не выполнено
    {
        emit not_performed();
        return;
    }
    rDir.cd(lDir.dirName());
    QString copyPath = rDir.absolutePath();
    //цикл копирования элементов контейнера в созданную директорию
    foreach (QFileInfo info, copyList)
    {
        if (info.isFile()) // текущий элемент контейнера - файл
        {
	    if (!QFile::copy(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
		emit not_performed();
	}
        else if (info.isDir()) // если текущий элемент - директория
	    c_py(rDir, info.absoluteFilePath());
    }
    rDir.cdUp();
}

bool ThreadToReplace::rec_remove(QDir& qDir) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, qDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
            qDir.cd(info.fileName());                  // заходим в нее
	    rec_remove(qDir);                          // рекурсивно удаляем внутренности
	    qDir.cdUp();                               // возврат
	    if (!qDir.rmdir(info.absoluteFilePath()))  // теперь папка пуста и мы можем ее удалить
		return false;
	}
        else if (info.isFile()) // если текущий объект - файл
	    if (!QFile::remove(info.absoluteFilePath()))
		return false;
    }
    return true;
}

void ThreadToReplace::r_move(const QString& dirPath)
{
    QDir qDir = QDir(dirPath); // получение выбранной директории
    if (!qDir.isEmpty())       // если директория не пуста
    {
	if (!rec_remove(qDir)) // если внутренние файлы не удалены
	{
            emit not_performed();
            return;
        }
    }
    if (qDir.isEmpty()) // если директория пуста
    {
	if (!qDir.rmdir(dirPath)) // если удаление не выпонено
	    emit not_performed();
    }
}
