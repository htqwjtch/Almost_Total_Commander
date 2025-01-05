#include "copyingservice.h"

CopyingService::CopyingService(QObject* parent) : QObject{parent} {}

void CopyingService::startCopying(const QString& sourceCopyingObjectPath, const QString& destinationFolderPath)
{
    setSourceCopyingObjectPath(sourceCopyingObjectPath);
    QFileInfo copyingObjectInfo = QFileInfo(sourceCopyingObjectPath);
    setDestinationCopyingObjectPath(destinationFolderPath + QDir::separator() + copyingObjectInfo.fileName());
    copyIn(destinationFolderPath);

    emit copyingCompletedSignal();
}

void CopyingService::setSourceCopyingObjectPath(const QString& sourceCopyingObjectPath)
{
    this->sourceCopyingObjectPath = sourceCopyingObjectPath;
}

void CopyingService::setDestinationCopyingObjectPath(const QString& destinationCopyingObjectPath)
{
    this->destinationCopyingObjectPath = destinationCopyingObjectPath;
}

void CopyingService::copyIn(const QString& destinationFolderPath)
{
    QFileInfo copyingObject = QFileInfo(sourceCopyingObjectPath);

    if (copyingObject.isDir())
    {
	copyFolder(sourceCopyingObjectPath, destinationFolderPath);
    }
    else if (!QFile::copy(sourceCopyingObjectPath, destinationCopyingObjectPath))
    {
	emit copyingFailedSignal("Copying failed!");
    }
}

void CopyingService::copyFolder(const QString& copyingFolderPath, const QString& destinationFolderPath)
{
    QDir copyingFolder = QDir(copyingFolderPath);
    QFileInfoList copyingFolderObjects = getCopyingFolderObjectsList(copyingFolder);

    QString destinationCopyingFolderPath = destinationFolderPath + QDir::separator() + copyingFolder.dirName();

    QDir destinationFolder = QDir(destinationFolderPath);
    createCopyingFolderInDestinationFolder(destinationCopyingFolderPath, destinationFolder);

    destinationFolder.cd(copyingFolder.dirName());
    copyFolderObjects(copyingFolderObjects, destinationFolder.absolutePath());
    destinationFolder.cdUp();
}

QFileInfoList CopyingService::getCopyingFolderObjectsList(QDir& copyingFolder)
{
    QFileInfoList copyingFolderObjectsList = QFileInfoList();
    foreach (QFileInfo entry, copyingFolder.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	copyingFolderObjectsList.append(entry);
    }
    return copyingFolderObjectsList;
}

void CopyingService::createCopyingFolderInDestinationFolder(const QString& destinationCopyingFolderPath, QDir& destinationFolder)
{
    if (!destinationFolder.mkdir(destinationCopyingFolderPath))
    {
	emit copyingFailedSignal("Copying failed!");
    }
}

void CopyingService::copyFolderObjects(QFileInfoList& copyingFolderObjects, const QString& destinationCopyingFolderPath)
{
    foreach (QFileInfo entry, copyingFolderObjects)
    {
	if (entry.isDir())
	{
	    copyFolder(entry.absoluteFilePath(), destinationCopyingFolderPath);
	}
	else if (entry.isFile() || entry.isSymLink())
	{
	    if (!QFile::copy(entry.absoluteFilePath(), QString(destinationCopyingFolderPath + QDir::separator() + entry.fileName())))
	    {
		emit copyingFailedSignal("Copying failed!");
		break;
	    }
	}
    }
}
