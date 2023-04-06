#include "systemfiles.h"

#include "systemfiles.h"
#include <cstdio>
#include <unistd.h>
#include <string.h>

#include<QMessageBox>
using namespace std;

bool File::Create(QString filePath) //метод создания текстового файла
{
    QString cmd="touch ";
    cmd=cmd.append(filePath);
    return !system(cmd.toLocal8Bit().constData());
}

bool File::Delete(QString filePath) //метод удаления текстового файла
{
    return !remove(filePath.toLocal8Bit().constData()); //если выполнено
}

bool File::Copy(QString filePath, QString newPath)    //метод копирования текстового файла
{
    QString cmd="cp ";
    cmd=cmd.append(filePath).append(" ").append(newPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool File::Rename(QString filePath, QString newPath)  //метод переименования текстового файла
{
    return !rename(filePath.toLocal8Bit().constData(), newPath.toLocal8Bit().constData());   //если выполнено
}


bool Dir::Create(QString dirPath)   //метод создания директории
{
    return !mkdir(dirPath.toLocal8Bit().constData(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

bool Dir::Delete(QString dirPath)   //метод удаления директории
{
    return !remove(dirPath.toLocal8Bit().constData());
}

bool Dir::Rename(QString dirPath, QString newPath)     //метод переименования директории
{
    return !rename(dirPath.toLocal8Bit().constData(), newPath.toLocal8Bit().constData());
}

bool Dir::Copy(QString dirName, QString newPath)  //метод копирования директории
{
    newPath=newPath.append(dirName);
    return !mkdir(newPath.toLocal8Bit().constData(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);//если выполнено
}


bool Link::Create(QString linkedPath_linkPath) //метод создания текстового файла
{
    QString cmd="ln -s ";
    cmd=cmd.append(linkedPath_linkPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool Link::Delete(QString linkPath) //метод удаления текстового файла
{
    return !remove(linkPath.toLocal8Bit().constData());
}

bool Link::Copy(QString linkPath, QString newPath)    //метод копирования текстового файла
{
    QString cmd="cp ";
    cmd=cmd.append(linkPath).append(" ").append(newPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool Link::Rename(QString linkPath, QString newPath)  //метод переименования текстового файла
{
    return !rename(linkPath.toLocal8Bit().constData(), newPath.toLocal8Bit().constData());   //если выполнено
}
