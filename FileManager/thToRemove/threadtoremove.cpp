#include "threadtoremove.h"

ThreadToRemove::ThreadToRemove(QObject* parent) : QObject{parent} {}

void ThreadToRemove::run_remove(const QString& filePath, const QString& directoryPath)
{
    if (!filePath.isEmpty()) // если выбран файл
    {
	if (!QFile::remove(filePath)) // удаление файла
	{
            emit not_performed();
            return;
        }
    }
    else
	remove(directoryPath);
    emit remove_finished();
}

bool ThreadToRemove::rec_remove(QDir& directory) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
	    directory.cd(info.fileName()); // заходим в нее
	    rec_remove(directory);         // рекурсивно удаляем внутренности
	    directory.cdUp();
	    if (!directory.rmdir(info.absoluteFilePath())) // теперь папка пуста и мы можем ее удалить
		return false;
        }
        else if (info.isFile()) // если текущий объект - файл
	    if (!QFile::remove(info.absoluteFilePath()))
		return false;
    }
    return true;
}

void ThreadToRemove::remove(const QString& directoryPath)
{
    QDir directory = QDir(directoryPath); // получение выбранной директории
    if (!directory.isEmpty())             // если директория не пуста
    {
	if (!rec_remove(directory)) // если внутренние файлы не удалены
	{
            emit not_performed();
            return;
        }
    }
    if (directory.isEmpty()) // если директория пуста
    {
	if (!directory.rmdir(directoryPath))
	    emit not_performed();
    }
}
