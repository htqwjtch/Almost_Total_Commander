#include "threadtoremove.h"

ThreadToRemove::ThreadToRemove(QObject* parent) : QObject{parent} {}

void ThreadToRemove::run_remove(SysElem* file, SysElem* dir, QString filePath, QString dirPath)
{
    if (!filePath.isEmpty()) // если выбран файл
    {
        if (!file->r_move(filePath)) // удаление файла
        {
            emit not_performed();
            return;
        }
    }
    else
        r_move(file, dir, dirPath);
    emit remove_finished();
}

bool ThreadToRemove::rec_remove(QDir& qDir, SysElem* file, SysElem* dir) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, qDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
            qDir.cd(info.fileName());                  // заходим в нее
            rec_remove(qDir, file, dir);               // рекурсивно удаляем внутренности
            qDir.cdUp();                               // возврат
            if (!dir->r_move(info.absoluteFilePath())) // теперь папка пуста и мы можем ее удалить
                return false;
        }
        else if (info.isFile()) // если текущий объект - файл
            if (!file->r_move(info.absoluteFilePath()))
                return false;
    }
    return true;
}

void ThreadToRemove::r_move(SysElem* file, SysElem* dir, QString dirPath)
{
    QDir qDir = QDir(dirPath); // получение выбранной директории
    if (!qDir.isEmpty())       // если директория не пуста
    {
        if (!rec_remove(qDir, file, dir)) // если внутренние файлы не удалены
        {
            emit not_performed();
            return;
        }
    }
    if (qDir.isEmpty()) // если директория пуста
    {
        if (!dir->r_move(dirPath)) // если удаление не выпонено
            emit not_performed();
    }
}
