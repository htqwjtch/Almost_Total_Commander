#include "searchingservice.h"

SearchingService::SearchingService(QObject* parent) : QObject{parent} {}

void SearchingService::startSearching(const QString& searchingName, const QString& currentFolderPath)
{
    QDir currentFolder = QDir(currentFolderPath);
    QStringList searchingResult = QStringList();
    searchingResult.append(search(searchingName, currentFolder));
    emit searchingCompletedSignal(searchingResult);
}

QStringList SearchingService::search(const QString& searchingName, QDir& currentFolder)
{
    QStringList searchingResult = QStringList();
    foreach (QFileInfo entry, currentFolder.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	if (!entry.fileName().compare(searchingName))
	{
	    searchingResult.append(entry.absoluteFilePath());
	}
	if (entry.isDir())
	{
	    currentFolder.cd(entry.fileName());
	    searchingResult.append(search(searchingName, currentFolder));
	    currentFolder.cdUp();
	}
    }
    return searchingResult;
}
