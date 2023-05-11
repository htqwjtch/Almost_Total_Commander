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

bool CreateChoice::get_file() // метод, сообщающий о выборе создании файла
{
    return file;
}

bool CreateChoice::get_dir() // метод, сообщающий о выборе создания директории
{
    return dir;
}

bool CreateChoice::get_link()
{
    return link;
}

void CreateChoice::on_btnFile_clicked()
{
    file = true;
    hide();
}

void CreateChoice::on_btnDir_clicked()
{
    dir = true;
    hide();
}

void CreateChoice::on_btnLink_clicked()
{
    link = true;
    hide();
}

void CreateChoice::on_btnCancel_clicked()
{
    hide();
}
