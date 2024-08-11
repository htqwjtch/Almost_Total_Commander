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
    setWindowTitle("Creation");
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
	createNewElementName();
	createFile();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreatingModule::createNewElementName()
{
    newElementName.exec();
    isNewElementNameUnique();
}

void CreatingModule::isNewElementNameUnique()
{
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (!entry.fileName().compare(newElementName.get_name()))
	{
	    throw LocalException("Creation", "This name already exists in the current directory!");
	}
    }
}

void CreatingModule::createFile()
{
    File file;
    if (!file.create(getNewElementPath()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

QString CreatingModule::getNewElementPath()
{
    return currentDirectory.absolutePath().append("/").append(newElementName.get_name());
}

void CreatingModule::on_directoryCreationButton_clicked()
{
    try
    {
	createNewElementName();
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
    if (!directory.create(getNewElementPath()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

void CreatingModule::on_symbolLinkCreationButton_clicked()
{
    try
    {
	createNewElementName();
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
    LinkedPath linkedElementPath;
    linkedElementPath.exec();
    if (symlink(linkedElementPath.get_path().toLocal8Bit().constData(), getNewElementPath().toLocal8Bit().constData()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

void CreatingModule::on_cancelButton_clicked()
{
    accept();
}

