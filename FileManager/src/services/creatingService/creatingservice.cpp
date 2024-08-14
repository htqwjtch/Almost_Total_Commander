#include "creatingservice.h"

#include <unistd.h>

CreatingService::CreatingService(QDir& currentDirectory)
{
    this->currentDirectory = currentDirectory;
}

void CreatingService::createFile()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.enterNameForNotSymbolLink();
    isNewElementNameUnique();

    File file;
    if (!file.create(namingModule.getPath()))
    {
	throw ExceptionService("Creating", "The operation was not perfomed!");
    }
}

void CreatingService::isNewElementNameUnique()
{
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (!entry.fileName().compare(namingModule.getName()))
	{
	    throw ExceptionService("Creating", "This name already exists in the current directory!");
	}
    }
}

void CreatingService::createDirectory()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.enterNameForNotSymbolLink();
    isNewElementNameUnique();

    Dir directory;
    if (!directory.create(namingModule.getPath()))
    {
	throw ExceptionService("Creating", "The operation was not perfomed!");
    }
}

void CreatingService::createSymbolLink()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.enterNameAndLinkedPathForSymbolLink();
    isNewElementNameUnique();

    if (symlink(namingModule.getLinkedPath().toLocal8Bit().constData(), namingModule.getPath().toLocal8Bit().constData()))
    {
	throw ExceptionService("Creating", "The operation was not perfomed!");
    }
}
