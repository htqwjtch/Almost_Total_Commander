#include "renamewindow.h"
#include "ui_renamewindow.h"

RenameWindow::RenameWindow(QWidget* parent) : QDialog(parent), ui(new Ui::RenameWindow) //
{
    ui->setupUi(this);        // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("Rename"); // установка имени окна
    ui->name->setToolTip("Please don't forget about the extension, if you want to enter a file name"); // устанока информации для подсказок
}

RenameWindow::~RenameWindow()
{
    delete ui;
}

QString RenameWindow::getName() // метод передачи имени
{
    return name;
}

void RenameWindow::on_btnOK_clicked() // слот нажатия на "OK"
{
    hide(); // закрытие текущего окна
}

void RenameWindow::on_btnCancel_clicked() // слот нажатия на "Cancel"
{
    name = "";
    hide(); // закрытие текущего окна
}

void RenameWindow::on_name_textEdited(const QString& arg1) // слот получения имени объекта
{
    name = arg1;
}
