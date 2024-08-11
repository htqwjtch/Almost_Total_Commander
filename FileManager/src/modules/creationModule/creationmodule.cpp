#include "creationmodule.h"
#include "linkedPath/linkedpath.h"
#include "ui_creationmodule.h"

#include <QDebug>
#include <unistd.h>

CreationModule::CreationModule(QDir& currentDirectory, QWidget* parent) : QDialog(parent), ui(new Ui::CreationModule)
{
    ui->setupUi(this);
    setWindowTitle("Creation");
    this->currentDirectory = currentDirectory;
    ui->fileCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
    ui->directoryCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
    ui->symbolLinkCreationButton->setStyleSheet("background-color: rgba(255, 255, 255, 0); border: none;");
}

CreationModule::~CreationModule()
{
    delete ui;
}

void CreationModule::on_fileCreationButton_clicked()
{
    try
    {
	create_new_element_name();
	create_file();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreationModule::create_new_element_name()
{
    newElementName.exec();
    is_new_element_name_unique();
}

void CreationModule::is_new_element_name_unique()
{
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (!entry.fileName().compare(newElementName.get_name()))
	{
	    throw LocalException("Creation", "This name already exists in the current directory!");
	}
    }
}

void CreationModule::create_file()
{
    File file;
    if (!file.create(get_new_element_path()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

QString CreationModule::get_new_element_path()
{
    return currentDirectory.absolutePath().append("/").append(newElementName.get_name());
}

void CreationModule::on_directoryCreationButton_clicked()
{
    try
    {
	create_new_element_name();
	create_directory();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreationModule::create_directory()
{
    Dir directory;
    if (!directory.create(get_new_element_path()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

void CreationModule::on_symbolLinkCreationButton_clicked()
{
    try
    {
	create_new_element_name();
	create_symbol_link();
    }
    catch (LocalException localException)
    {
	QMessageBox::warning(this, localException.get_title(), localException.get_info());
    }
    accept();
}

void CreationModule::create_symbol_link()
{
    LinkedPath linkedElementPath;
    linkedElementPath.exec();
    if (symlink(linkedElementPath.get_path().toLocal8Bit().constData(), get_new_element_path().toLocal8Bit().constData()))
    {
	throw LocalException("Creation", "The operation was not perfomed!");
    }
}

void CreationModule::on_cancelButton_clicked()
{
    accept();
}

