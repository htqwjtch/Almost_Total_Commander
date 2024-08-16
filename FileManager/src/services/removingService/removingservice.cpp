#include "removingservice.h"

RemovingService::RemovingService(QObject* parent) : QObject{parent} {}

void RemovingService::startRemoving(const QString& removingObjectPath)
{
    QFileInfo removingObject = QFileInfo(removingObjectPath);

    if (removingObject.isDir())
    {
	removeDirectory(removingObjectPath);
    }
    else if (!QFile::remove(removingObjectPath))
    {
	emit removingIsNotPerformedSignal();
    }

    emit removingIsPerformedSignal();
}

void RemovingService::removeDirectory(const QString& removingDirectoryPath)
{
    QDir removingDirectory = QDir(removingDirectoryPath);
    if (!removingDirectory.isEmpty())
    {
	removeDirectoryObjectsFrom(removingDirectory);
    }
    if (!removingDirectory.rmdir(removingDirectoryPath))
    {
	emit removingIsNotPerformedSignal();
    }
}

void RemovingService::removeDirectoryObjectsFrom(QDir& removingDirectory)
{
    foreach (QFileInfo entry, removingDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	if (entry.isDir())
	{
	    removingDirectory.cd(entry.fileName());
	    removeDirectoryObjectsFrom(removingDirectory);
	    removingDirectory.cdUp();
	    if (!removingDirectory.rmdir(entry.absoluteFilePath()))
	    {
		emit removingIsNotPerformedSignal();
		break;
	    }
	}
	else if (entry.isFile())
	{
	    if (!QFile::remove(entry.absoluteFilePath()))
	    {
		emit removingIsNotPerformedSignal();
		break;
	    }
	}
    }
}
