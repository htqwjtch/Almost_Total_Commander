#include "createchoise.h"
#include "ui_createchoise.h"

CreateChoise::CreateChoise(QWidget *parent) : QDialog(parent), ui(new Ui::CreateChoise)
{
    ui->setupUi(this);  //настраивает пользовательский интерфейс для указанного виджета
     setWindowTitle("Create");  //установка имени окна
}

CreateChoise::~CreateChoise()
{
    delete ui;
}

void CreateChoise::on_btnFile_clicked() // слот выбора о создании файла
{
    ChooseFile(true);
    hide();
}

void CreateChoise::on_btnFolder_clicked()   // слот выбора о создании директории
{
    ChooseFolder(true);
    hide();
}

void CreateChoise::ChooseFile(bool i)    //метод установки создания файла
{
    file=i;
}

void CreateChoise::ChooseFolder(bool i)  //метод установки создания директории
{
    folder=i;
}

bool CreateChoise::GetFile()    //метод, сообщающий о выборе создании файла
{
    return file;
}

bool CreateChoise::GetFolder()  //метод, сообщающий о выборе создания директории
{
    return folder;
}

void CreateChoise::on_btnCancel_clicked()   // слот нажатия на "Cancel"
{
    hide();
}
