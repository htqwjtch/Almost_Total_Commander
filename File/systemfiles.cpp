#include "systemfiles.h"

#include "systemfiles.h"
#include <cstdio>
#include <unistd.h>

#include<QMessageBox>
using namespace std;

bool File::Create() //метод создания текстового файла
{
    ofstream file;  //создание объекта класса ofstream
    file.open(filePath);    //открытие файла с указанным именем
    if(!file.is_open()) //если файл не открыт
        return false;
    file.close();   //если открыт
    return true;
}

bool File::Delete() //метод удаления текстового файла
{
    return !remove(filePath); //если выполнено
}

bool File::Copy(QString newPath)    //метод копирования текстового файла
{
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    ifstream file;  //создание объекта класса ifstream
    file.open(filePath);    //открытие файла с указанным именем
    ofstream newFile;   //создание объекта класса ofstream
    newFile.open(new_path, ios::app);   //открытие файла с указанным именем и режимом записи в конец файла
    if (file.is_open() && newFile.is_open()) //если оба файла открыты
    {
        string line="";
        while (getline(file, line))  //пока можно производить чтение из файла
            newFile << line << endl; //чтение информации из файла построчно
    }
    else    //если закрыт хотя бы один из файлов
    {
        if(file.is_open())
            file.close();
        if(newFile.is_open())
            newFile.close();
        return false;
    }
    //если открыт хотя бы один из файлов
    if(file.is_open())
        file.close();
    if(newFile.is_open())
        newFile.close();
    return true;
}

bool File::Rename(QString newPath)  //метод переименования текстового файла
{
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    return !rename(filePath, new_path);   //если выполнено
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
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    return !rename(dirPath, new_path);
}

bool Dir::Copy(QString newPath)  //метод копирования директории
{
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    return !mkdir(new_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);//если выполнено
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
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    return !rename(linkPath, new_path);   //если выполнено
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
