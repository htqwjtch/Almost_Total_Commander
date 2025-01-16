#include "removingservice.h"

RemovingService::RemovingService(QObject *parent) : QObject{parent} {}

void RemovingService::startRemoving(const QStringList &removingObjectPathes)
{
    removedObjectNames = QStringList();
    foreach (QString removingObjectPath, removingObjectPathes)
    {
        QFileInfo removingObject = QFileInfo(removingObjectPath);
        QString removingObjectName = removingObject.fileName();
        if (removingObject.isDir())
        {
            removeFolder(removingObjectPath);
        }
        else if (QFile::remove(removingObjectPath))
        {
            removedObjectNames.append(removingObjectName);
        }
    }

    emit removingFinishedSignal(removedObjectNames);
}

void RemovingService::removeFolder(const QString &removingFolderPath)
{
    QDir removingFolder = QDir(removingFolderPath);
    QString removingFolderName = removingFolder.dirName();
    if (!removingFolder.isEmpty())
    {
        removeFolderObjectsFrom(removingFolder);
    }
    if (removingFolder.rmdir(removingFolderPath))
    {
        removedObjectNames.append(removingFolderName);
    }
}

void RemovingService::removeFolderObjectsFrom(QDir &removingFolder)
{
    foreach (QFileInfo entry,
        removingFolder.entryInfoList(
            QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        if (entry.isDir())
        {
            removingFolder.cd(entry.fileName());
            removeFolderObjectsFrom(removingFolder);
            removingFolder.cdUp();
            if (!removingFolder.rmdir(entry.absoluteFilePath()))
            {
                break;
            }
        }
        else if (entry.isFile())
        {
            if (!QFile::remove(entry.absoluteFilePath()))
            {
                break;
            }
        }
    }
}
