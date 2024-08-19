#include "creatingservice.h"
#include "../exceptionService/exceptionservice.h"

#include <QDir>
#include <QFile>
#include <unistd.h>

CreatingService::CreatingService(QDir& currentDirectory)
{
    this->currentDirectory = currentDirectory;
}

void CreatingService::createFile()
{
    createNameAndPathForNotSymbolLink();

    QFile file = QFile(namingModule.getPath());
    if (!file.open(QIODevice::ReadWrite))
    {
	throw ExceptionService("Creating was not perfomed!");
    }
}

void CreatingService::createNameAndPathForNotSymbolLink()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.setNameAndPathForNotSymbolLink();
    isNewElementNameUnique();
}

void CreatingService::isNewElementNameUnique()
{
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (!entry.fileName().compare(namingModule.getName()))
	{
	    throw ExceptionService("This name already exists in the current directory!");
	}
    }
}

void CreatingService::createDirectory()
{
    createNameAndPathForNotSymbolLink();

    QDir directory = QDir();
    if (!directory.mkdir(namingModule.getPath()))
    {
	throw ExceptionService("Creating was not perfomed!");
    }
}

void CreatingService::createSymbolLink()
{
    createNameAndPathesForSymbolLink();

    if (symlink(namingModule.getLinkedPath().toLocal8Bit().constData(), namingModule.getPath().toLocal8Bit().constData()))
    {
	throw ExceptionService("Creating was not perfomed!");
    }
}

void CreatingService::createNameAndPathesForSymbolLink()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.setNameAndPathesForSymbolLink();
    isNewElementNameUnique();
}
