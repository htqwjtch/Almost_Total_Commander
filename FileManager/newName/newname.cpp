#include "newname.h"
#include "ui_newname.h"

NewName::NewName(QWidget* parent) : QDialog(parent), ui(new Ui::NewName)
{
    ui->setupUi(this);
    setWindowTitle("Rename");                                                                          // установка имени окна
    ui->name->setToolTip("Please don't forget about the extension, if you want to enter a file name"); // устанока информации для подсказок
}

NewName::~NewName()
{
    delete ui;
}

QString NewName::getName() // метод передачи имени
{
    return name;
}

void NewName::on_name_textEdited(const QString& arg1)
{
    name = arg1;
}

void NewName::on_btnCancel_clicked()
{
    name.clear();
    hide(); // закрытие текущего окна
}

void NewName::on_btnOK_clicked()
{
    hide(); // закрытие текущего окна
}
