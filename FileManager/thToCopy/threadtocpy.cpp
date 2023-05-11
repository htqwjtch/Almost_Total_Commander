#include "threadtocpy.h"

ThreadToCopy::ThreadToCopy(QObject* parent) : QObject{parent} {}

void ThreadToCopy::run_copy(QDir rDir, SysElem* file, SysElem* dir, QString filePath, QString dirPath)
{
    if (!filePath.isEmpty())
    {
        if (!file->c_py(filePath, rDir.absolutePath())) // если копирование не произошло
        {
            emit not_performed();
            return;
        }
    }
    else
        c_py(rDir, file, dir, dirPath);
    emit copy_finished();
}

void ThreadToCopy::c_py(QDir rDir, SysElem* file, SysElem* dir, QString dirPath)
{
    QFileInfoList copyList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
    QDir lDir = QDir(dirPath);
    foreach (QFileInfo info, lDir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
        copyList.append(info);                           // добавление элемента в контейнеp
    if (!dir->c_py(lDir.dirName(), rDir.absolutePath())) // если копирование не выполнено
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
            if (!file->c_py(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
                emit not_performed();
        }
        else if (info.isDir()) // если текущий элемент - директория
            c_py(rDir, file, dir, info.absoluteFilePath());
    }
    rDir.cdUp();
}
