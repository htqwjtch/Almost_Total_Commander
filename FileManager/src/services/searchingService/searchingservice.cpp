#include "searchingservice.h"

SearchingService::SearchingService(QObject* parent) : QObject{parent} {}

void SearchingService::startSearching(const QString& currentDirectoryPath, const QString& searchingName)
{
    QDir currentDirectory = QDir(currentDirectoryPath);
    QStringList searchingResult = QStringList();
    searchingResult.append(search(currentDirectory, searchingName));
    emit searchingIsPerformedSignal(searchingResult);
}

QStringList SearchingService::search(QDir& currentDirectory, const QString& searchingName)
{
    QStringList searchingResult = QStringList();
    foreach (QFileInfo entry, currentDirectory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name | QDir::DirsFirst))
    {
	if (!entry.fileName().compare(searchingName))
	{
	    searchingResult.append(entry.absoluteFilePath());
	}
	if (entry.isDir())
	{
	    currentDirectory.cd(entry.fileName());
	    searchingResult.append(search(currentDirectory, searchingName));
	    currentDirectory.cdUp();
	}
    }
    return searchingResult;
}
