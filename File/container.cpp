#include "container.h"
#include "exception.h"

void List::Push(QString bolt)   //метод добавления элемента
{
    try {
        if(!(node=new Node))   //если память не выделилась
            throw BadAllocException("", "");
    }
    catch(BadAllocException error)
    {
        qDebug()<<"Node of List was not create!\n";
    }

    catch (...)
    {
        qDebug()<<"Unknown Error!\n";
    }
    node->info=bolt;    //наполнение информацией атрибут структуры
    if (!head||!tail)   //если контейнер пуст
    {
        //создание первого элемента
        tail = node;
        head = node;
    }
    else
    {
        //добавление нового элемента
        tail->next=node;
        tail=node;
    }
}

Node* List::PeekHead(bool flag) //метод передачи первого либо текущего элемента
{
    return flag?head:node;
}

void List::Pop()    //метод очистки контейнера
{
    while(head) //пока первый элемент есть
    {
        node = head->next;  //установка текущего на следующий элемент за первым
        delete head;    //удаление первого элемента
        head = node;    //следующий за первым становится первым
    }
    tail = node;    //установка последнего элемента на пустой указатель
}

bool List::IsEmpty()    //метод проверки, пуст ли контейнер
{
    return tail==nullptr;
}


void List::Iterator::SetIter(Node* node)     //метод установки итератора на элемент, связанный с указателем *node
{
    current=node;
}

bool List::Iterator::operator ++()  //перегруженный оператор для перехода к следующему элементу
{
    if(this->current->next) //если указатель следующего элемента не пустой
    {
        this->current=this->current->next; //переход к следующему элемненту
        return true;
    }
    return false;
}

Node* List::Iterator::operator *()  //перегруженный оператор для получения информации текущего элемента
{
    return this->current;
}
