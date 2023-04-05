#include "systemfiles.h"

#include "systemfiles.h"
#include <cstdio>
#include <unistd.h>
#include <string.h>

#include<QMessageBox>
using namespace std;

bool File::Create() //метод создания текстового файла
{
    QString cmd="touch ";
    cmd=cmd.append(filePath);
    return !system(cmd.toLocal8Bit().constData());
}

bool File::Delete() //метод удаления текстового файла
{
    return !remove(filePath); //если выполнено
}

bool File::Copy(QString newPath)    //метод копирования текстового файла
{
    QString cmd="cp ";
    cmd=cmd.append(filePath).append(" ").append(newPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool File::Rename(QString newPath)  //метод переименования текстового файла
{
    return !rename(filePath, newPath.toLocal8Bit().constData());   //если выполнено
}

void File::SetPath(QString path)    //метод установки пути текстового файла
{
    filePath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
}

const char* File::GetPath() //метод передачи пути текстового файла
{
    return filePath;
}


bool Dir::Create()   //метод создания директории
{
    return !mkdir(dirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}

bool Dir::Delete()   //метод удаления директории
{
    return !remove(dirPath);//если выполнено
}

bool Dir::Rename(QString newPath)     //метод переименования директории
{
    const char* new_path=newPath.toLocal8Bit().constData();
    return !rename(dirPath, new_path);
}

bool Dir::Copy(QString newPath)  //метод копирования директории
{
    return !mkdir(newPath.toLocal8Bit().constData(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);//если выполнено
}

void Dir::SetPath(QString path)  //метод установки пути директории
{
    dirPath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
}

const char* Dir::GetPath()   //метод передачи пути директории
{
    return dirPath;
}


bool Link::Create() //метод создания текстового файла
{
    QString cmd="ln -s ";
    cmd=cmd.append(linkedPath).append(" ").append(linkPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool Link::Delete() //метод удаления текстового файла
{
    return !remove(linkPath);
}

bool Link::Copy(QString newPath)    //метод копирования текстового файла
{
    QString cmd="cp ";
    cmd=cmd.append(linkPath).append(" ").append(newPath);
    return !system(cmd.toLocal8Bit().constData());
}

bool Link::Rename(QString newPath)  //метод переименования текстового файла
{
    return !rename(linkPath, newPath.toLocal8Bit().constData());   //если выполнено
}

void Link::SetPath(QString path)    //метод установки пути текстового файла
{
    if(strstr(linkPath, "/home")==NULL)
        linkPath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
    else linkedPath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
}

const char* Link::GetPath() //метод передачи пути текстового файла
{
    return linkPath;
}
