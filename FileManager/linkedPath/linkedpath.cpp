#include "linkedpath.h"
#include "ui_linkedpath.h"

LinkedPath::LinkedPath(QWidget* parent) : QDialog(parent), ui(new Ui::LinkedPath)
{
    ui->setupUi(this);
    setWindowTitle("Link"); // установка имени окна
}

LinkedPath::~LinkedPath()
{
    delete ui;
}

QString LinkedPath::get_path() // метод передачи имени
{
    return path;
}

void LinkedPath::on_btnCancel_clicked()
{
    path.clear();
    hide(); // закрытие текущего окна
}

void LinkedPath::on_btnOK_clicked()
{
    hide(); // закрытие текущего окна
}

void LinkedPath::on_path_textEdited(const QString& arg1)
{
    path = arg1;
}
