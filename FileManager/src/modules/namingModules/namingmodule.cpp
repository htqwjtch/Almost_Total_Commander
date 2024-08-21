#include "namingmodule.h"

#include <QDebug>

void NamingModule::setCurrentFolder(QDir& currentFolder)
{
    this->currentFolder = currentFolder;
}

void NamingModule::setNameAndPathForNotSymbolLink()
{
    try
    {
	namingNotSymbolLinkModule.exec();
	checkName(namingNotSymbolLinkModule.getName());
	name = namingNotSymbolLinkModule.getName();
	path = currentFolder.absolutePath() + QDir::separator() + namingNotSymbolLinkModule.getName();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning((QWidget*)this, "", exceptionService.getInfo());
    }
}

void NamingModule::checkName(const QString& name)
{
    foreach (QFileInfo entry, currentFolder.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
	if (entry.fileName() == name)
	{
	    throw ExceptionService("This name already exists in the current folder!");
	}
    }
}

void NamingModule::setNameAndPathesForSymbolLink()
{
    try
    {
	namingSymbolLinkModule.exec();
	checkName(namingSymbolLinkModule.getName());
	name = namingSymbolLinkModule.getName();
	path = currentFolder.absolutePath() + QDir::separator() + namingSymbolLinkModule.getName();
	linkedPath = namingSymbolLinkModule.getLinkedPath();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning((QWidget*)this, "", exceptionService.getInfo());
    }
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

void NamingModule::rename(const QString& renamingObjectPath)
{
    try
    {
	setNameAndPathForNotSymbolLink();
	QFileInfo renamingFileInfo = QFileInfo(renamingObjectPath);
	if (!name.isEmpty())
	{
	    if (renamingFileInfo.isDir())
	    {
		if (!currentFolder.rename(renamingObjectPath, path))
		{
		    throw ExceptionService("Renaming failed!");
		}
	    }
	    else if (!QFile::rename(renamingObjectPath, path))
	    {
		throw ExceptionService("Renaming failed!");
	    }
	}
	else
	{
	    throw ExceptionService("Name is empty!");
	}
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning((QWidget*)this, "", exceptionService.getInfo());
    }
}
