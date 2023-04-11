#include "threadtoremove.h"
#include "exception.h"

void ThreadToRemove::runRemove(System* file, System* dir, System* link, QString dirPath)
{
    r_move(file, dir, link, dirPath);
}

ThreadToRemove::ThreadToRemove(QObject* parent) : QObject{parent} {}

bool ThreadToRemove::recursiveDelete(QDir& qDir, System* file, System* dir, System* link) // функция рекурсивного удаления содержимого выбранной папки
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

void ThreadToRemove::r_move(System* file, System* dir, System* link, QString dirPath)
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
    }
}
