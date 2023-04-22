#include "threadtosearch.h"

#include <cstdio>
#include <fstream>
#include <iostream>

#include <QDesktopServices>

using namespace std;

ThreadToSearch::ThreadToSearch(QObject* parent) : QObject{parent} {}

void ThreadToSearch::search(QDir& dir, QString searchName, QFileInfoList& list)
{
    // проход по текущему диску для поиска объектов с введенным именем
    foreach (QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.fileName() == searchName) // сравнение элементов по имени
            list.append(info);
        if (info.isFile() || info.isSymLink()) // если элемент - файл, переходим к след файлу
            continue;
        if (info.isDir()) // если дошли до этого момента, значит элемент - директория
        {
            dir.cd(info.fileName());       // заходим в нее
            search(dir, searchName, list); // рекурсивно ищем различия
            dir.cdUp();                    // возврат
        }
    }
}

void ThreadToSearch::runSearch(QString lDirPath, QString rDirPath, QString searchName)
{
    QDir lDir = QDir(lDirPath);
    QDir rDir = QDir(rDirPath);
    QFileInfoList list = QFileInfoList();
    if (!list.isEmpty())
        list.clear();
    if (lDirPath.contains("/home"))
        search(lDir, searchName, list);
    if (rDirPath.contains("/home"))
        search(rDir, searchName, list);
    emit searchFinished(list);
}
