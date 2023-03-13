#include "systemfiles.h"
#include<cstdio>

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
    if(!remove(filePath)) //если удаление не выполнено
        return true;
    return false; //если выполнено
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
    if(!rename(filePath, new_path))  //если переименование не выполнено
        return true;
    return false;   //если выполнено
 }

void File::SetPath(QString path)    //метод установки пути текстового файла
{
     filePath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
}

const char* File::GetPath() //метод передачи пути текстового файла
{
    return filePath;
}


bool Folder::Create()   //метод создания директории
{
    if (mkdir(dirPath, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)==-1)   //если создание не выполнено
      return true;
    return false;//если выполнено
}

bool Folder::Delete()   //метод удаления директории
{
    if(!remove(dirPath)==-1) //если удаление не выполнено
        return true;
    return false;//если выполнено
}

bool Folder::Rename(QString newPath)     //метод переименования директории
 {
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    if(!rename(dirPath, new_path))  //если переименование не выполнено
        return true;
    return false;//если выполнено
 }

bool Folder::Copy(QString newPath)  //метод копирования директории
 {
    const char* new_path=newPath.toLocal8Bit().constData(); //преобразование строки типа QString в строку типа string
    if (mkdir(new_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)==-1)  //если создание копии директории не выполнено
      return true;
    return false;//если выполнено
 }

void Folder::SetPath(QString path)  //метод установки пути директории
{
     dirPath=path.toLocal8Bit().constData();// преобразует тип данных QString в тип string
}

const char* Folder::GetPath()   //метод передачи пути директории
{
    return dirPath;
}
