#ifndef SYSTEM_H
#define SYSTEM_H


#include<QFileSystemModel>
#include<QDir>
#include<QString>

#include<iostream>
#include<fstream>
#include<sys/stat.h>
#include<cstdio>

using namespace std;

class System    //базовый класс Sytem для работы с системными объектами
{
public:
    System()=default;
    virtual ~System()=default;
    //ниже представлены чисто виртуальные методы для работы с системными объектами
    //описаны они будут в производных классах
    virtual bool Create()=0;
    virtual bool Delete()=0;
    virtual bool Rename(QString)=0;
    virtual bool Copy(QString)=0;
    virtual void SetPath(QString)=0;
    virtual const char* GetPath()=0;
};


class File: public System   //производный класс File для работы с текстовыми файлами
{
    const char* filePath="";
public:
    File()=default;
    ~File()=default;
    bool Create();  //метод создания текстового файла
    bool Delete();  //метод удаления текстового файла
    bool Rename(QString);   //метод переименования текстового файла
    bool Copy(QString);     //метод копирования текстового файла
    void SetPath(QString);  //метод установки пути текстового файла
    const char* GetPath();  //метод передачи пути текстового файла
};

class Dir: public System //производный класс Dir для работы с директориями
{
    const char* dirPath="";
public:
    Dir()=default;
    ~Dir()=default;
    bool Create();  //метод создания директории
    bool Delete();  //метод удаления директории
    bool Rename(QString);   //метод переименования директории
    bool Copy(QString);     //метод копирования директории
    void SetPath(QString);  //метод установки пути директории
    const char* GetPath();  //метод передачи пути директории
};

class Link: public System
{
    const char* linkPath="";
    const char* linkedPath="";
public:
    Link()=default;
    ~Link()=default;
    bool Create();  //метод создания директории
    bool Delete();  //метод удаления директории
    bool Rename(QString);   //метод переименования директории
    bool Copy(QString);     //метод копирования директории
    void SetPath(QString);  //метод установки пути директории
    const char* GetPath();  //метод передачи пути директории
};


#endif // SYSTEM_H
