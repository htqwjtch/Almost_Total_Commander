#include "threadtocpy.h"

void ThreadToCopy::runCopy(QDir lDir, QDir rDir, SysElem* file, SysElem* dir, QString dirName)
{
    c_py(lDir, rDir, file, dir, dirName);
}

ThreadToCopy::ThreadToCopy(QObject* parent) : QObject{parent} {}

void ThreadToCopy::recursiveCopyList(QDir& dir, QFileInfoList& copyList) // функция рекурсивного наполнения содержимым списка для копирования
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

void ThreadToCopy::c_py(QDir lDir, QDir rDir, SysElem* file, SysElem* dir, QString dirName)
{
    QFileInfoList copyList = QFileInfoList(); // создание контейнера для хранения внутренних файлов выбранной директории
    recursiveCopyList(lDir, copyList); // рекурсивное наполнение контейнера внутренними файлами директор
    // проход по выбранной директории для поиска директории с именем копируемой
    rDir.mkdir(dirName); // создание копии директории по выбранному пути
    rDir.cd(dirName);
    // цикл копирования элементов контейнера в созданную директорию
    //        foreach (QFileInfo info, copyList)
    //        {
    //            QString copyPath = info.filePath().replace(lDir.absolutePath(), rDir.absolutePath()); // создание пути для копирования
    //            if (info.isFile()) // текущий элемент контейнера - файл
    //            {
    //                if (!file->c_py(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
    //                    qDebug()<<"The operation <<Copy>> was not perfomed!";
    //            }
    //            if (info.isDir()) // если текущий элемент - директория
    //            {
    //                if (!dir->c_py(info.dir().dirName(), copyPath)) // если копирование не выполнено
    //                    qDebug()<<"The operation <<Copy>> was not perfomed!";
    //            }
    //            if (info.isSymLink())
    //            {
    //                if (!link->c_py(info.absoluteFilePath(), copyPath)) // если копирование не выполнено
    //                    qDebug()<<"The operation <<Copy>> was not perfomed!";
    //            }
    //        }
}
