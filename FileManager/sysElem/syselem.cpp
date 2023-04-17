#include "syselem.h"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

using namespace std;

bool File::create(QString filePath) // метод создания файла
{
    ofstream file;                                 //создание объекта класса ofstream
    file.open(filePath.toLocal8Bit().constData()); //открытие файла с указанным именем
    return file.is_open();
}

bool File::r_move(QString filePath) // метод удаления текстового файла
{
    return !remove(filePath.toLocal8Bit().constData()); // если выполнено
}

bool File::c_py(QString filePath, QString newPath) // метод копирования текстового файла
{
    QString cmd = "cp ";
    cmd = cmd.append(filePath).append(" ").append(newPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool File::r_name(QString filePath, QString newPath) // метод переименования текстового файла
{
    return !rename(filePath.toLocal8Bit().constData(), newPath.toLocal8Bit().constData()); // если выполнено
}

bool Dir::create(QString dirPath) // метод создания директории
{
    return !mkdir(dirPath.toLocal8Bit().constData(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

bool Dir::r_move(QString dirPath) // метод удаления директории
{
    return !remove(dirPath.toLocal8Bit().constData());
}

bool Dir::r_name(QString dirPath, QString newPath) // метод переименования директории
{
    return !rename(dirPath.toLocal8Bit().constData(), newPath.toLocal8Bit().constData());
}

bool Dir::c_py(QString dirName, QString newPath) // метод копирования директории
{
    newPath = newPath.append("/").append(dirName);
    return !mkdir(newPath.toLocal8Bit().constData(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH); // если выполнено
}
