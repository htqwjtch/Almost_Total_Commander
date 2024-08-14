#include "creatingmodule.h"
#include "ui_creationmodule.h"

#include <QDebug>
#include <unistd.h>

CreatingModule::CreatingModule(QDir& currentDirectory, QWidget* parent) : QDialog(parent), ui(new Ui::CreatingModule)
{
    setUserInterface();
    creatingService = new CreatingService(currentDirectory);
}

void CreatingModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Creating");
    setButtonsInvisible();
}

void CreatingModule::setButtonsInvisible()
{
    ui->fileCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
    ui->directoryCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
    ui->symbolLinkCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
}

CreatingModule::~CreatingModule()
{
    delete ui;
    delete creatingService;
}

void CreatingModule::on_fileCreationButton_clicked()
{
    try
    {
	creatingService->createFile();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, exceptionService.getTitle(), exceptionService.getInfo());
    }
    accept();
}

void CreatingModule::on_directoryCreationButton_clicked()
{
    try
    {
	creatingService->createDirectory();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, exceptionService.getTitle(), exceptionService.getInfo());
    }
    accept();
}

void CreatingModule::on_symbolLinkCreationButton_clicked()
{
    try
    {
	creatingService->createSymbolLink();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, exceptionService.getTitle(), exceptionService.getInfo());
    }
    accept();
}

void CreatingModule::on_cancelButton_clicked()
{
    accept();
}

