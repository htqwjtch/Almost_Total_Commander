#include "createchoice.h"
#include "ui_createchoice.h"

CreateChoice::CreateChoice(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateChoice)
{
    ui->setupUi(this);  //настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("Create");  //установка имени окна
}

CreateChoice::~CreateChoice()
{
    delete ui;
}


void CreateChoice::ChooseFile(bool i)    //метод установки создания файла
{
    file=i;
}

void CreateChoice::ChooseDir(bool i)  //метод установки создания директории
{
    dir=i;
}

void CreateChoice::ChooseLink(bool i)
{
    link=i;
}

bool CreateChoice::GetFile()    //метод, сообщающий о выборе создании файла
{
    return file;
}

bool CreateChoice::GetDir()  //метод, сообщающий о выборе создания директории
{
    return dir;
}

bool CreateChoice::GetLink()
{
    return link;
}
void CreateChoice::on_btnFile_clicked()
{
    ChooseFile(true);
    hide();
}


void CreateChoice::on_btnDir_clicked()
{
    ChooseDir(true);
    hide();
}


void CreateChoice::on_btnLink_clicked()
{
    ChooseLink(true);
    hide();
}

