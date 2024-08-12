#include "namingmodule.h"

void NamingModule::setCurrentDirectory(QDir& currentDirectory)
{
    this->currentDirectory = currentDirectory;
}

void NamingModule::enterNameForNotSymbolLink()
{
    namingNotSymbolLinkModule.exec();
    name = namingNotSymbolLinkModule.getName();
    path = currentDirectory.absolutePath().append("/").append(namingNotSymbolLinkModule.getName());
}

void NamingModule::enterNameAndLinkedPathForSymbolLink()
{
    namingSymbolLinkModule.exec();
    name = namingSymbolLinkModule.getName();
    path = currentDirectory.absolutePath().append("/").append(namingSymbolLinkModule.getName());
    linkedPath = namingSymbolLinkModule.getLinkedPath();
}

QString NamingModule::getName()
{
    return name;
}

QString NamingModule::getPath()
{
    return path;
}

QString NamingModule::getLinkedPath()
{
    return linkedPath;
}
