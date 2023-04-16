#include "threadtosearch.h"
#include "../sysElem/syselem.h"

#include <cstdio>
#include <fstream>
#include <iostream>

#include <QDesktopServices>
#include <QMessageBox>
#include <QUrl>

using namespace std;

ThreadToSearch::ThreadToSearch(QObject* parent) : QObject{parent} {}

void ThreadToSearch::search(QDir& dir, QString searchName)
{
    // проход по текущему диску для поиска объектов с введенным именем
    foreach (QFileInfo info, dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (info.fileName() == searchName)               // сравнение элементов по имени
            list.push(dir.absoluteFilePath(searchName)); // добавление элемента в контейнер
        if (info.isFile() || info.isSymLink())           // если элемент - файл, переходим к след файлу
            continue;
        if (info.isDir()) // если дошли до этого момента, значит элемент - директория
        {
            dir.cd(info.fileName()); // заходим в нее
            search(dir, searchName); // рекурсивно ищем различия
            dir.cdUp();              // возврат
        }
    }
}

void ThreadToSearch::runSearch(QString lDirPath, QString rDirPath, QString searchName)
{
    QDir lDir = QDir(lDirPath);
    QDir rDir = QDir(rDirPath);
    list.push("----------------------------------------_Left_Panel_Results_----------------------------------------\n\n");
    if (lDirPath.contains("/home"))
        search(lDir, searchName);
    list.push("\n\n---------------------------------------_Right_Panel_Results_----------------------------------------\n\n");
    if (rDirPath.contains("/home"))
        search(rDir, searchName);
    File f;
    SysElem* file = &f;
    if (!file->create("/home/h4thqewjtch/Desktop/Search.txt"))
        qDebug() << "The operation <<Create>> was not perfomed!";
    ofstream File;                                     //создание объекта класса ofstream
    File.open("/home/h4thqewjtch/Desktop/Search.txt"); //открытие файла с указанным имене
    if (File.is_open() && !list.isEmpty())             //если оба файла открыты
    {
        iter.setIter(list.peekHead());                                 // установка итератора на начало контейнера
        do                                                             //пока можно производить чтение из файла
            File << ((*iter)->info).toLocal8Bit().constData() << endl; //чтение информации из файла построчно
        while (++iter);
    }
    else
    {
        if (File.is_open())
            File.close();
        if (!list.isEmpty())
            list.clear();
        return;
    }
    if (File.is_open())
        File.close();
    if (!list.isEmpty())
        list.clear();
    QDesktopServices::openUrl(QUrl::fromUserInput("/home/h4thqewjtch/Desktop/Search.txt"));

    return;
}
