#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QMessageBox>
#include <QTableWidget>
#include <QToolButton>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this); // настраивает пользовательский интерфейс для указанного виджета
    setWindowTitle("FileManager"); // установка имени главного окна

    ui->tabWidget->clear();

    QToolButton* tb = new QToolButton();
    tb->setText("+");
    tb->setAutoRaise(true);
    connect(tb, SIGNAL(clicked()), this, SLOT(add_tab()));

    QLabel* lbl = nullptr;
    if (!(lbl = new QLabel("You can add tabs by pressing <b>\"+\"</b>")))
        QMessageBox::warning(this, "Memory allocation", "Object of QLabel was not created!");
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->tabWidget->addTab(lbl, QString());
    ui->tabWidget->setTabEnabled(0, false);
    ui->tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, tb);

    add_tab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::add_tab()
{
    form = new Form(this);
    QString tabName = "Tab " + QString::number(ui->tabWidget->count());
    ui->tabWidget->insertTab(ui->tabWidget->count() - 1, form, tabName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 2);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    if (ui->tabWidget->count() > 2 && ui->tabWidget->currentIndex() != ui->tabWidget->count() - 1)
        ui->tabWidget->removeTab(index);
}

void MainWindow::on_CtrlC_triggered()
{
    form->btn_copy();
}

void MainWindow::on_CtrlX_triggered()
{
    form->btn_replace();
}

void MainWindow::on_CtrlEsc_triggered()
{
    this->close();
}

void MainWindow::on_CtrlN_triggered()
{
    form->btn_create();
}

void MainWindow::on_CtrlLeft_triggered()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() - 1);
}

void MainWindow::on_CtrlRight_triggered()
{
    if (ui->tabWidget->currentIndex() < ui->tabWidget->count() - 2)
        ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
}

void MainWindow::on_CtrlDel_triggered()
{
    on_tabWidget_tabCloseRequested(ui->tabWidget->currentIndex());
}

void MainWindow::on_CtrlT_triggered()
{
    add_tab();
}

void MainWindow::on_CtrlR_triggered()
{
    form->btn_rename();
}

void MainWindow::on_CtrlD_triggered()
{
    form->btn_remove();
}

void MainWindow::on_CtrlF_triggered()
{
    form->btn_search();
}
