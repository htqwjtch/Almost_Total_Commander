#include "creatingservice.h"

CreatingService::CreatingService(QDir &currentFolder, QObject *parent) : QObject{parent}
{
    this->currentFolder = currentFolder;
    namingModule = new NamingModule(currentFolder);
}

CreatingService::~CreatingService() { delete namingModule; }

void CreatingService::createFile()
{
    createNameAndPathForNotSymbolLink();

    QFile file = QFile(namingModule->getPath());
    if (!file.open(QIODevice::ReadWrite))
    {
        throw ExceptionService("Creating failed!");
    }
    emit creatingFinishedSignal(namingModule->getPath());
}

void CreatingService::createNameAndPathForNotSymbolLink()
{
    namingModule->setNameAndPathForNotSymbolLink();
}

void CreatingService::createFolder()
{
    createNameAndPathForNotSymbolLink();

    QDir folder = QDir();
    if (!folder.mkdir(namingModule->getPath()))
    {
        throw ExceptionService("Creating failed!");
    }
    emit creatingFinishedSignal(namingModule->getPath());
}

void CreatingService::createSymbolLink()
{
    createNameAndPathesForSymbolLink();

    if (symlink(namingModule->getLinkedPath().toLocal8Bit().constData(),
            namingModule->getPath().toLocal8Bit().constData()))
    {
        throw ExceptionService("Creating failed!");
    }
    emit creatingFinishedSignal(namingModule->getPath());
}

void CreatingService::createNameAndPathesForSymbolLink()
{
    namingModule->setNameAndPathesForSymbolLink();
}
