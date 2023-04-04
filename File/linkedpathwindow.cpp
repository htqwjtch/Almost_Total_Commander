#include "linkedpathwindow.h"
#include "ui_linkedpathwindow.h"

LinkedPathWindow::LinkedPathWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LinkedPathWindow)
{
    ui->setupUi(this);
    setWindowTitle("Link");   //установка имени окна
    ui->path->setToolTip("Please don't forget about the extension, if you want to enter a file name");  //устанока информации для подсказок
}

LinkedPathWindow::~LinkedPathWindow()
{
    delete ui;
}

QString LinkedPathWindow::GetPath() //метод передачи имени
{
    return path;
}

void LinkedPathWindow::on_btnCancel_clicked()
{
    path="";
    hide();//закрытие текущего окна
}

void LinkedPathWindow::on_btnOK_clicked()
{
    hide(); //закрытие текущего окна
}


void LinkedPathWindow::on_path_textEdited(const QString &arg1)
{
    path=arg1;
}

