#include "creatingmodule.h"
#include "../../services/exceptionService/exceptionservice.h"
#include "ui_creatingmodule.h"

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
    setButtonsStyleSheets();
}

void CreatingModule::setButtonsStyleSheets()
{
    ui->fileCreationButton->setStyleSheet("QPushButton {"
					  "    border: none;"
					  "}"
					  "QPushButton:hover {"
					  "    border: 1px ridge grey;"
					  "}");
    ui->directoryCreationButton->setStyleSheet("QPushButton {"
					       "    border: none;"
					       "}"
					       "QPushButton:hover {"
					       "    border: 1px ridge grey;"
					       "}");
    ui->symbolLinkCreationButton->setStyleSheet("QPushButton {"
						"    border: none;"
						"}"
						"QPushButton:hover {"
						"    border: 1px ridge grey;"
						"}");
}

CreatingModule::~CreatingModule()
{
    delete creatingService;
    delete ui;
}

void CreatingModule::on_fileCreationButton_clicked()
{
    try
    {
	creatingService->createFile();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
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
	QMessageBox::warning(this, "", exceptionService.getInfo());
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
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    accept();
}

void CreatingModule::on_cancelButton_clicked()
{
    accept();
}

