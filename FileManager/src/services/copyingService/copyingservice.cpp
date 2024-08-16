#include "copyingservice.h"

CopyingService::CopyingService(QObject* parent) : QObject{parent} {}

void CopyingService::startCopying(const QString& sourceCopyingObjectPath, const QString& destinationDirectoryPath)
{
    setSourceCopyingObjectPath(sourceCopyingObjectPath);
    QFileInfo copyingObjectInfo = QFileInfo(sourceCopyingObjectPath);
    setDestinationCopyingObjectPath(destinationDirectoryPath + QDir::separator() + copyingObjectInfo.fileName());
    copyIn(destinationDirectoryPath);

    emit copyingIsPerformedSignal();
}

void CopyingService::setSourceCopyingObjectPath(const QString& sourceCopyingObjectPath)
{
    this->sourceCopyingObjectPath = sourceCopyingObjectPath;
}

void CopyingService::setDestinationCopyingObjectPath(const QString& destinationCopyingObjectPath)
{
    this->destinationCopyingObjectPath = destinationCopyingObjectPath;
}

void CopyingService::copyIn(const QString& destinationDirectoryPath)
{
    QFileInfo copyingObject = QFileInfo(sourceCopyingObjectPath);

    if (copyingObject.isDir())
    {
	copyDirectory(sourceCopyingObjectPath, destinationDirectoryPath);
    }
    else if (!QFile::copy(sourceCopyingObjectPath, destinationCopyingObjectPath))
    {
	emit copyingIsNotPerformedSignal();
    }
}

void CopyingService::copyDirectory(const QString& copyingDirectoryPath, const QString& destinationDirectoryPath)
{
    QDir copyingDirectory = QDir(copyingDirectoryPath);
    QFileInfoList copyingDirectoryObjects = getCopyingDirectoryObjectsList(copyingDirectory);

    QString destinationCopyingDirectoryPath = destinationDirectoryPath + QDir::separator() + copyingDirectory.dirName();

    QDir destinationDirectory = QDir(destinationDirectoryPath);
    createCopyingDirectoryInDestinationDirectory(destinationCopyingDirectoryPath, destinationDirectory);

    destinationDirectory.cd(copyingDirectory.dirName());
    copyDirectoryObjects(copyingDirectoryObjects, destinationDirectory.absolutePath());
    destinationDirectory.cdUp();
}

QFileInfoList CopyingService::getCopyingDirectoryObjectsList(QDir& copyingDirectory)
{
    QFileInfoList copyingDirectoryObjectsList = QFileInfoList();
    foreach (QFileInfo entry, copyingDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	copyingDirectoryObjectsList.append(entry);
    }
    return copyingDirectoryObjectsList;
}

void CopyingService::createCopyingDirectoryInDestinationDirectory(const QString& destinationCopyingDirectoryPath, QDir& destinationDirectory)
{
    if (!destinationDirectory.mkdir(destinationCopyingDirectoryPath))
    {
	emit copyingIsNotPerformedSignal();
	return;
    }
}

void CopyingService::copyDirectoryObjects(QFileInfoList& copyingDirectoryObjects, const QString& destinationCopyingDirectoryPath)
{
    foreach (QFileInfo entry, copyingDirectoryObjects)
    {
	if (entry.isFile() || entry.isSymLink())
	{
	    if (!QFile::copy(entry.absoluteFilePath(), QString(destinationCopyingDirectoryPath + QDir::separator() + entry.fileName())))
	    {
		emit copyingIsNotPerformedSignal();
		break;
	    }
	}
	else if (entry.isDir())
	{
	    copyDirectory(entry.absoluteFilePath(), destinationCopyingDirectoryPath);
	}
    }
}
