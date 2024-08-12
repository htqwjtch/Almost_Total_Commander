#include "creatingmodule.h"
#include "linkedPath/linkedpath.h"
#include "ui_creationmodule.h"

#include <QDebug>
#include <unistd.h>

CreatingModule::CreatingModule(QDir& currentDirectory, QWidget* parent) : QDialog(parent), ui(new Ui::CreatingModule)
{
    setUserInterface();
    this->currentDirectory = currentDirectory;
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
}

void CreatingModule::on_fileCreationButton_clicked()
{
    try
    {
	namingModule.setCurrentDirectory(currentDirectory);
	namingModule.enterNameForNotSymbolLink();
	isNewElementNameUnique();
	createFile();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreatingModule::isNewElementNameUnique()
{
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (!entry.fileName().compare(namingModule.getName()))
	{
	    throw LocalException("Creating", "This name already exists in the current directory!");
	}
    }
}

void CreatingModule::createFile()
{
    File file;
    if (!file.create(namingModule.getPath()))
    {
	throw LocalException("Creating", "The operation was not perfomed!");
    }
}

void CreatingModule::on_directoryCreationButton_clicked()
{
    try
    {
	namingModule.setCurrentDirectory(currentDirectory);
	namingModule.enterNameForNotSymbolLink();
	isNewElementNameUnique();
	createDirectory();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreatingModule::createDirectory()
{
    Dir directory;
    if (!directory.create(namingModule.getPath()))
    {
	throw LocalException("Creating", "The operation was not perfomed!");
    }
}

void CreatingModule::on_symbolLinkCreationButton_clicked()
{
    try
    {
	namingModule.setCurrentDirectory(currentDirectory);
	namingModule.enterNameAndLinkedPathForSymbolLink();
	isNewElementNameUnique();
	createSymbolLink();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreatingModule::createSymbolLink()
{
    if (symlink(namingModule.getLinkedPath().toLocal8Bit().constData(), namingModule.getPath().toLocal8Bit().constData()))
    {
	throw LocalException("Creating", "The operation was not perfomed!");
    }
}

void CreatingModule::on_cancelButton_clicked()
{
    accept();
}

