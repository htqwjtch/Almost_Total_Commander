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
    virtual bool Create(QString)=0;
    virtual bool Delete(QString)=0;
    virtual bool Rename(QString, QString)=0;
    virtual bool Copy(QString, QString)=0;
};


class File: public System   //производный класс File для работы с текстовыми файлами
{
public:
    File()=default;
    ~File()=default;
    bool Create(QString);  //метод создания текстового файла
    bool Delete(QString);  //метод удаления текстового файла
    bool Rename(QString, QString);   //метод переименования текстового файла
    bool Copy(QString, QString);     //метод копирования текстового файла
};

class Dir: public System //производный класс Dir для работы с директориями
{
public:
    Dir()=default;
    ~Dir()=default;
    bool Create(QString);  //метод создания директории
    bool Delete(QString);  //метод удаления директории
    bool Rename(QString, QString);   //метод переименования директории
    bool Copy(QString, QString);     //метод копирования директории
};

class Link: public System
{
public:
    Link()=default;
    ~Link()=default;
    bool Create(QString);  //метод создания директории
    bool Delete(QString);  //метод удаления директории
    bool Rename(QString, QString);   //метод переименования директории
    bool Copy(QString, QString);     //метод копирования директории
};


#endif // SYSTEM_H
