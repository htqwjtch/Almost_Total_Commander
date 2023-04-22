#include "threadtoreplace.h"

ThreadToReplace::ThreadToReplace(QObject* parent) : QObject{parent} {}

void ThreadToReplace::runReplace(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath)
{
    if (!filePath.isEmpty())
    {
        if (!file->c_py(filePath, rDir.absolutePath())) // если копирование не произошло
        {
            emit notPerformed();
            return;
        }
        if (!file->r_move(filePath))
        {
            emit notPerformed();
            return;
        }
    }
    else
    {
        c_py(rDir, file, dir, dirPath);
        r_move(file, dir, dirPath);
    }
    emit replaceFinished();
}

void ThreadToReplace::c_py(QDir rDir, SysElem* file, SysElem* dir, QString dirPath)
{
    QFileInfoList copyList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
    QDir lDir = QDir(dirPath);
    foreach (QFileInfo info, lDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
        copyList.append(info);                           // добавление элемента в контейнеp
    if (!dir->c_py(lDir.dirName(), rDir.absolutePath())) // если копирование не выполнено
    {
        emit notPerformed();
        return;
    }
    rDir.cd(lDir.dirName());
    QString copyPath = rDir.absolutePath();
    //цикл копирования элементов контейнера в созданную директорию
    foreach (QFileInfo info, copyList)
    {
        if (info.isFile()) // текущий элемент контейнера - файл
        {
            if (!file->c_py(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
                emit notPerformed();
        }
        else if (info.isDir()) // если текущий элемент - директория
            c_py(rDir, file, dir, info.absoluteFilePath());
    }
    rDir.cdUp();
}

bool ThreadToReplace::recRemove(QDir& qDir, SysElem* file, SysElem* dir) // функция рекурсивного удаления содержимого выбранной папки
{
    // цикл прохода по текущей директории для удаления файлов и директорий внутри
    foreach (QFileInfo info, qDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.isDir()) // если директория
        {
            qDir.cd(info.fileName());                  // заходим в нее
            recRemove(qDir, file, dir);                // рекурсивно удаляем внутренности
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

void ThreadToReplace::r_move(SysElem* file, SysElem* dir, QString dirPath)
{
    QDir qDir = QDir(dirPath); // получение выбранной директории
    if (!qDir.isEmpty())       // если директория не пуста
    {
        if (!recRemove(qDir, file, dir)) // если внутренние файлы не удалены
        {
            emit notPerformed();
            return;
        }
    }
    if (qDir.isEmpty()) // если директория пуста
    {
        if (!dir->r_move(dirPath)) // если удаление не выпонено
            emit notPerformed();
    }
}
