#ifndef SYSELEM_H
#define SYSELEM_H

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include <QDir>
#include <QFileSystemModel>
#include <QString>

using namespace std;

class SysElem
{
public:
    SysElem() = default;
        virtual ~SysElem() = default;
        // ниже представлены чисто виртуальные методы для работы с системными
        // объектами описаны они будут в производных классах
        virtual bool create(QString) = 0;
        virtual bool r_move(QString) = 0;
        virtual bool r_name(QString, QString) = 0;
        virtual bool c_py(QString, QString) = 0;
};

class File : public SysElem // производный класс File для работы с текстовыми файлами
{
public:
    File() = default;
    ~File() = default;
    bool create(QString);          // метод создания текстового файла
    bool r_move(QString);          // метод удаления текстового файла
    bool r_name(QString, QString); // метод переименования текстового файла
    bool c_py(QString, QString);   // метод копирования текстового файла
};

class Dir : public SysElem // производный класс Dir для работы с директориями
{
public:
    Dir() = default;
    ~Dir() = default;
    bool create(QString);          // метод создания директории
    bool r_move(QString);          // метод удаления директории
    bool r_name(QString, QString); // метод переименования директории
    bool c_py(QString, QString);   // метод копирования директории
};

class Link : public SysElem
{
public:
    Link() = default;
    ~Link() = default;
    bool create(QString);          // метод создания директории
    bool r_move(QString);          // метод удаления директории
    bool r_name(QString, QString); // метод переименования директории
    bool c_py(QString, QString);   // метод копирования директории
};


#endif // SYSELEM_H



