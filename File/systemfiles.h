#ifndef SYSTEM_H
#define SYSTEM_H

#include <QDir>
#include <QFileSystemModel>
#include <QString>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sys/stat.h>

using namespace std;

class System // базовый класс Sytem для работы с системными объектами
{
public:
    System() = default;
    virtual ~System() = default;
    // ниже представлены чисто виртуальные методы для работы с системными
    // объектами описаны они будут в производных классах
    virtual bool create(QString) = 0;
    virtual bool r_move(QString) = 0;
    virtual bool r_name(QString, QString) = 0;
    virtual bool copy(QString, QString) = 0;
};

class File : public System // производный класс File для работы с текстовыми файлами
{
public:
    File() = default;
    ~File() = default;
    bool create(QString);          // метод создания текстового файла
    bool r_move(QString);          // метод удаления текстового файла
    bool r_name(QString, QString); // метод переименования текстового файла
    bool copy(QString, QString);   // метод копирования текстового файла
};

class Dir : public System // производный класс Dir для работы с директориями
{
public:
    Dir() = default;
    ~Dir() = default;
    bool create(QString);          // метод создания директории
    bool r_move(QString);          // метод удаления директории
    bool r_name(QString, QString); // метод переименования директории
    bool copy(QString, QString);   // метод копирования директории
};

class Link : public System
{
public:
    Link() = default;
    ~Link() = default;
    bool create(QString);          // метод создания директории
    bool r_move(QString);          // метод удаления директории
    bool r_name(QString, QString); // метод переименования директории
    bool copy(QString, QString);   // метод копирования директории
};

#endif // SYSTEM_H
