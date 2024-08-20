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
	throw ExceptionService("Creating failed!");
    }
}

void CreatingService::createNameAndPathForNotSymbolLink()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.setNameAndPathForNotSymbolLink();
}

void CreatingService::createDirectory()
{
    createNameAndPathForNotSymbolLink();

    QDir directory = QDir();
    if (!directory.mkdir(namingModule.getPath()))
    {
	throw ExceptionService("Creating failed!");
    }
}

void CreatingService::createSymbolLink()
{
    createNameAndPathesForSymbolLink();

    if (symlink(namingModule.getLinkedPath().toLocal8Bit().constData(), namingModule.getPath().toLocal8Bit().constData()))
    {
	throw ExceptionService("Creating failed!");
    }
}

void CreatingService::createNameAndPathesForSymbolLink()
{
    namingModule.setCurrentDirectory(currentDirectory);
    namingModule.setNameAndPathesForSymbolLink();
}
