#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<QMessageBox>   //предоставляет модальный диалог для информирования пользователя

#include<iostream>
using namespace std;


class Exception //базовый класс исключений
{
    QString nameOperation="";   //название операции, при которой обработано исключение
    QString problem=""; //суть проблемы
public:
    Exception()=default;
    ~Exception()=default;
    void SetException(QString str1, QString str2)   //создание информации, предоставленной пользователю
    {
       nameOperation=str1;
       problem=str2;
    }
    void GetException(QWidget* parent)
    {
        QMessageBox::warning(parent, nameOperation, problem);   //предоставление пользователю информации об исключении
    }
};

class RootDirectoryException: public Exception  //производный класс, обрабатывающий исключение выполнения операций в корневой папке
{
    QString nameOperation="";
    QString problem="";
public:
    RootDirectoryException()=default;
    RootDirectoryException(QString str1, QString str2) : nameOperation(str1), problem(str2)
    {
         Exception::SetException(nameOperation, problem);   //вызов метода базового класса
    }
    ~RootDirectoryException()=default;
};

class ChoiseException: public Exception //производный класс, обрабатывающий исключение выполнения операции без выбранного объекта
{
    QString nameOperation="";
    QString problem="";
public:
    ChoiseException()=default;
    ChoiseException(QString str1, QString str2):  nameOperation(str1), problem(str2)
    {
        Exception::SetException(nameOperation, problem);    //вызов метода базового класса
    }
    ~ChoiseException()=default;
};

class PerformationException: public Exception   //производный класс, обрабатывающий исключение невыполненной операции
{
    QString nameOperation="";
    QString problem="";
public:
    PerformationException()=default;
    PerformationException(QString str1, QString str2):  nameOperation(str1), problem(str2)
    {
         Exception::SetException(nameOperation, problem);   //вызов метода базового класса
    }
    ~PerformationException()=default;
};

class BadAllocException:public Exception    //производный класс, обрабатывающий исключение выделения памяти
{
    QString nameOperation="";
    QString problem="";
public:
    BadAllocException()=default;
    BadAllocException(QString str1, QString str2):  nameOperation(str1), problem(str2)
    {
         Exception::SetException(nameOperation, problem);   //вызов метода базового класса
    }
    ~BadAllocException()=default;
};

class ExceptionEmpty: public Exception  //производный класс, обрабатывающий исключение пустой строки для ввода
{
    QString nameOperation="";
    QString problem="";
public:
    ExceptionEmpty()=default;
    ExceptionEmpty(QString str1, QString str2):  nameOperation(str1), problem(str2)
    {
         Exception::SetException(nameOperation, problem);   //вызов метода базового класса
    }
    ~ExceptionEmpty()=default;
};

#endif // EXCEPTION_H
