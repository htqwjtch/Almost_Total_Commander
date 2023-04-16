#include "createchoice.h"
#include "ui_createchoice.h"

CreateChoice::CreateChoice(QWidget* parent) : QDialog(parent), ui(new Ui::CreateChoice)
{
    ui->setupUi(this);        // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("Create"); // установка имени окна
}

CreateChoice::~CreateChoice()
{
    delete ui;
}

void CreateChoice::chooseFile(bool i) // метод установки создания файла
{
    file = i;
}

void CreateChoice::chooseDir(bool i) // метод установки создания директории
{
    dir = i;
}

void CreateChoice::chooseLink(bool i)
{
    link = i;
}

bool CreateChoice::getFile() // метод, сообщающий о выборе создании файла
{
    return file;
}

bool CreateChoice::getDir() // метод, сообщающий о выборе создания директории
{
    return dir;
}

bool CreateChoice::getLink()
{
    return link;
}

void CreateChoice::on_btnFile_clicked()
{
    chooseFile(true);
    hide();
}

void CreateChoice::on_btnDir_clicked()
{
    chooseDir(true);
    hide();
}

void CreateChoice::on_btnLink_clicked()
{
    chooseLink(true);
    hide();
}

void CreateChoice::on_btnCancel_clicked()
{
    hide();
}
