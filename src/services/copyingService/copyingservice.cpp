#include "copyingservice.h"

CopyingService::CopyingService(QObject *parent) : QObject{parent} {}

void CopyingService::startCopying(const QStringList &sourceCopyingObjectPathes,
    const QString &destinationFolderPath)
{
    copiedObjectPathes = QStringList();
    foreach (QString sourceCopyingObjectPath, sourceCopyingObjectPathes)
    {
        if (checkName(sourceCopyingObjectPath, destinationFolderPath))
        {
            setSourceCopyingObjectPath(sourceCopyingObjectPath);
            QFileInfo copyingObjectInfo = QFileInfo(sourceCopyingObjectPath);
            setDestinationCopyingObjectPath(
                destinationFolderPath + QDir::separator() + copyingObjectInfo.fileName());
            copyIn(destinationFolderPath);
        }
    }
    emit copyingFinishedSignal(copiedObjectPathes);
}

bool CopyingService::checkName(const QString &copyingObjectPath,
    const QString &destinationFolderPath)
{
    QFileInfo copyingObjectInfo = QFileInfo(copyingObjectPath);
    QDir destinationFolder = QDir(destinationFolderPath);
    foreach (QFileInfo entry,
        destinationFolder.entryInfoList(
            QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name))
    {
        if (entry.fileName() == copyingObjectInfo.fileName())
        {
            return false;
        }
    }
    return true;
}

void CopyingService::setSourceCopyingObjectPath(const QString &sourceCopyingObjectPath)
{
    this->sourceCopyingObjectPath = sourceCopyingObjectPath;
}

void CopyingService::setDestinationCopyingObjectPath(const QString &destinationCopyingObjectPath)
{
    this->destinationCopyingObjectPath = destinationCopyingObjectPath;
}

void CopyingService::copyIn(const QString &destinationFolderPath)
{
    QFileInfo copyingObject = QFileInfo(sourceCopyingObjectPath);
    if (copyingObject.isDir())
    {
        copyFolder(sourceCopyingObjectPath, destinationFolderPath);
    }
    else if (QFile::copy(sourceCopyingObjectPath, destinationCopyingObjectPath))
    {
        copiedObjectPathes.append(destinationCopyingObjectPath);
    }
}

void CopyingService::copyFolder(const QString &copyingFolderPath,
    const QString &destinationFolderPath)
{
    QDir copyingFolder = QDir(copyingFolderPath);
    QFileInfoList copyingFolderObjects = getCopyingFolderObjectsList(copyingFolder);

    QString destinationCopyingFolderPath =
        destinationFolderPath + QDir::separator() + copyingFolder.dirName();

    QDir destinationFolder = QDir(destinationFolderPath);
    createCopyingFolderInDestinationFolder(destinationCopyingFolderPath, destinationFolder);

    destinationFolder.cd(copyingFolder.dirName());
    copyFolderObjects(copyingFolderObjects, destinationFolder.absolutePath());
    destinationFolder.cdUp();
}

QFileInfoList CopyingService::getCopyingFolderObjectsList(QDir &copyingFolder)
{
    QFileInfoList copyingFolderObjectsList = QFileInfoList();
    foreach (QFileInfo entry,
        copyingFolder.entryInfoList(
            QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
        copyingFolderObjectsList.append(entry);
    }
    return copyingFolderObjectsList;
}

void CopyingService::createCopyingFolderInDestinationFolder(
    const QString &destinationCopyingFolderPath,
    QDir &destinationFolder)
{
    if (destinationFolder.mkdir(destinationCopyingFolderPath) &&
        destinationCopyingFolderPath == destinationCopyingObjectPath)
    {
        copiedObjectPathes.append(destinationCopyingFolderPath);
    }
}

void CopyingService::copyFolderObjects(QFileInfoList &copyingFolderObjects,
    const QString &destinationCopyingFolderPath)
{
    foreach (QFileInfo entry, copyingFolderObjects)
    {
        if (entry.isDir())
        {
            copyFolder(entry.absoluteFilePath(), destinationCopyingFolderPath);
        }
        else if (entry.isFile() || entry.isSymLink())
        {
            QFile::copy(entry.absoluteFilePath(),
                QString(destinationCopyingFolderPath + QDir::separator() + entry.fileName()));
        }
    }
}
