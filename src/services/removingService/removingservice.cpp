#include "removingservice.h"

RemovingService::RemovingService(QObject* parent) : QObject{parent} {}

void RemovingService::startRemoving(const QString& removingObjectPath)
{
    QFileInfo removingObject = QFileInfo(removingObjectPath);

    if (removingObject.isDir())
    {
	removeFolder(removingObjectPath);
    }
    else if (!QFile::remove(removingObjectPath))
    {
	emit removingFailedSignal("Removing failed!");
    }

    emit removingCompletedSignal();
}

void RemovingService::removeFolder(const QString& removingFolderPath)
{
    QDir removingFolder = QDir(removingFolderPath);
    if (!removingFolder.isEmpty())
    {
	removeFolderObjectsFrom(removingFolder);
    }
    if (!removingFolder.rmdir(removingFolderPath))
    {
	emit removingFailedSignal("Removing failed!");
    }
}

void RemovingService::removeFolderObjectsFrom(QDir& removingFolder)
{
    foreach (QFileInfo entry, removingFolder.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	if (entry.isDir())
	{
	    removingFolder.cd(entry.fileName());
	    removeFolderObjectsFrom(removingFolder);
	    removingFolder.cdUp();
	    if (!removingFolder.rmdir(entry.absoluteFilePath()))
	    {
		emit removingFailedSignal("Removing failed!");
		break;
	    }
	}
	else if (entry.isFile())
	{
	    if (!QFile::remove(entry.absoluteFilePath()))
	    {
		emit removingFailedSignal("Removing failed!");
		break;
	    }
	}
    }
}
