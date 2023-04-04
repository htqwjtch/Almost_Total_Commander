#include "linkelementwindow.h"
#include "ui_linkelementwindow.h"

LinkElementWindow::LinkElementWindow(QWidget *parent) : QDialog(parent), ui(new Ui::LinkElementWindow)
{
    ui->setupUi(this);
    setWindowTitle("Link");   //установка имени окна
    ui->path->setToolTip("Please don't forget about the extension, if you want to enter a file name");  //устанока информации для подсказок
}

LinkElementWindow::~LinkElementWindow()
{
    delete ui;
}

QString LinkElementWindow::GetPath() //метод передачи имени
{
    return path;
}

void LinkElementWindow::on_btnOK_clicked()
{
    hide();
}


void LinkElementWindow::on_btnCancel_clicked()
{
    path="";
    hide();//закрытие текущего окна
}


void LinkElementWindow::on_path_textEdited(const QString &arg1)
{
    path=arg1;
}

