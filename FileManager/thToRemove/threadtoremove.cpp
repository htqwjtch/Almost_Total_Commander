#include "threadtoremove.h"

void ThreadToRemove::runRemove(SysElem* file, SysElem* dir, QString dirPath)
{
    r_move(file, dir, dirPath);
}

ThreadToRemove::ThreadToRemove(QObject* parent) : QObject{parent} {}

bool ThreadToRemove::recursiveDelete(QDir& qDir, SysElem* file, SysElem* dir) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, qDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
            qDir.cd(info.fileName());         // заходим в нее
            recursiveDelete(qDir, file, dir); // рекурсивно удаляем внутренности
            // теперь папка пуста и мы можем ее удалить
            if (!dir->r_move(qDir.absolutePath()))
                return false;
            qDir.cdUp(); // возврат
        }
        else if (info.isFile()) // если текущий объект - файл
            return file->r_move(info.absoluteFilePath());
    }
    return true;
}

void ThreadToRemove::r_move(SysElem* file, SysElem* dir, QString dirPath)
{
    //    QDir qDir = QDir(dirPath); // получение выбранной директории
    //    if (!qDir.isEmpty())       // если директория не пуста
    //    {
    //        if (!recursiveDelete(qDir, file, dir, link)) // если внутренние файлы не удалены
    //            qDebug()<<"The operation <<Delete>> was not perfomed!";
    //    }
    //    if (qDir.isEmpty()) // если директория пуста
    //    {
    //        if (!dir->r_move(dirPath)) // если удаление не выпонено
    //            qDebug()<<"The operation <<Delete>> was not perfomed!";
    //    }
}
