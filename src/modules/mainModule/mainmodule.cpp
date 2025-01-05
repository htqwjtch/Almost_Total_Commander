#include "mainmodule.h"
#include "ui_mainmodule.h"

#include <QMessageBox>
#include <QTableWidget>

MainModule::MainModule(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainModule)
{
    setUserInterface();
}

MainModule::~MainModule()
{
    delete addTabButton;
    delete tabModule;
    delete ui;
}

void MainModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Not Total Commander");
    setAddTabButton();
    setAddTabButtonTab();
    addTab();
}

void MainModule::setAddTabButton()
{
    addTabButton = new QToolButton();
    addTabButton->setText("+");
    addTabButton->setAutoRaise(true);

    connect(addTabButton, SIGNAL(clicked()), this, SLOT(addTab()));
}

void MainModule::setAddTabButtonTab()
{
    ui->tabWidget->clear();
    ui->tabWidget->addTab(new QWidget(), QString());
    ui->tabWidget->setTabEnabled(0, false);
    ui->tabWidget->tabBar()->setTabButton(0, QTabBar::RightSide, addTabButton);
}

void MainModule::on_actionAdd_Tab_triggered()
{
    addTab();
}

void MainModule::addTab()
{
    tabModule = new TabModule(this);
    QString tabName = "Tab " + QString::number(ui->tabWidget->count());
    ui->tabWidget->insertTab(ui->tabWidget->count() - 1, tabModule, tabName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 2);
}

void MainModule::on_actionClose_Tab_triggered()
{
    on_tabWidget_tabCloseRequested(ui->tabWidget->currentIndex());
}

void MainModule::on_tabWidget_tabCloseRequested(int index)
{
    if (ui->tabWidget->count() > 2)
    {
	on_actionLeft_tab_triggered();
	ui->tabWidget->removeTab(index);
    }
}

void MainModule::on_actionLeft_tab_triggered()
{
    ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() - 1);
}

void MainModule::on_actionRight_Tab_triggered()
{
    if (ui->tabWidget->currentIndex() < ui->tabWidget->count() - 2)
    {
	ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
    }
}

void MainModule::on_actionExit_triggered()
{
    this->close();
}

void MainModule::on_actionSearch_triggered()
{
    tabModule->execute("Search");
}

void MainModule::on_actionCreate_triggered()
{
    tabModule->execute("Create");
}

void MainModule::on_actionRemove_triggered()
{
    tabModule->execute("Remove");
}

void MainModule::on_actionCopy_triggered()
{
    tabModule->execute("Copy");
}

void MainModule::on_actionReplace_triggered()
{
    tabModule->execute("Replace");
}

void MainModule::on_actionRename_triggered()
{
    tabModule->execute("Rename");
}

void MainModule::on_actionShow_Hidden_triggered()
{
    tabModule->execute("Show Hidden");
}
