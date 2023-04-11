#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("FileManager"); // установка имени главного окна
    ui->tabWidget->clear();
    on_toolButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    form = new Form(this);
    QString name = "Tab " + QString::number(ui->tabWidget->count() + 1);
    ui->tabWidget->addTab(form, name);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (ui->tabWidget->count() > 1)
        ui->tabWidget->removeTab(index);
}

void MainWindow::on_CtrlC_triggered()
{
    form->onBtnCopyClicked();
}

void MainWindow::on_CtrlX_triggered()
{
    form->onBtnReplaceClicked();
}

void MainWindow::on_CtrlEsc_triggered()
{
    this->close();
}

void MainWindow::on_CtrlN_triggered()
{
    form->onBtnCreateClicked();
}

void MainWindow::on_CtrlLeft_triggered()
{
    if (ui->tabWidget->currentIndex() > 0)
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() - 1);
}

void MainWindow::on_CtrlRight_triggered()
{
    if (ui->tabWidget->currentIndex() < ui->tabWidget->count() - 1)
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
}

void MainWindow::on_CtrlDel_triggered()
{
    on_tabWidget_tabCloseRequested(ui->tabWidget->currentIndex());
}

void MainWindow::on_CtrlT_triggered()
{
    on_toolButton_clicked();
}

void MainWindow::on_CtrlR_triggered()
{
    form->onBtnRenameClicked();
}

void MainWindow::on_CtrlD_triggered()
{
    form->onBtnDeleteClicked();
}

void MainWindow::on_CtrlF_triggered()
{
    form->onBtnSearchClicked();
}
