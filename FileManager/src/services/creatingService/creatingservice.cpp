#include "creatingservice.h"
#include "../exceptionService/exceptionservice.h"

#include <QDir>
#include <QFile>
#include <unistd.h>

CreatingService::CreatingService(QDir& currentFolder)
{
    this->currentFolder = currentFolder;
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
    namingModule.setCurrentFolder(currentFolder);
    namingModule.setNameAndPathForNotSymbolLink();
}

void CreatingService::createFolder()
{
    createNameAndPathForNotSymbolLink();

    QDir folder = QDir();
    if (!folder.mkdir(namingModule.getPath()))
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
    namingModule.setCurrentFolder(currentFolder);
    namingModule.setNameAndPathesForSymbolLink();
}
