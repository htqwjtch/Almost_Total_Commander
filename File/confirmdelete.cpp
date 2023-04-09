#include "confirmdelete.h"
#include "ui_confirmdelete.h"

ConfirmDelete::ConfirmDelete(QWidget* parent) : QDialog(parent), ui(new Ui::ConfirmDelete)
{
    ui->setupUi(this);        // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("Delete"); // установка имени окна
}

ConfirmDelete::~ConfirmDelete()
{
    delete ui;
}

void ConfirmDelete::setConfirm(bool i) // метод установки подтверждения удаления
{
    confirm = i;
}

bool ConfirmDelete::getConfirm() // метод срабатывания подтверждения удаления
{
    return confirm;
}

void ConfirmDelete::on_btnOK_clicked() // слот нажатия на "OK"
{
    setConfirm(true);
    hide(); // метод закрытия окна
}

void ConfirmDelete::on_btnCancel_clicked() // слот нажатия на "Cancel"
{
    hide();
}
