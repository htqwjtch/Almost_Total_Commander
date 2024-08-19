#include "searchingservice.h"

SearchingService::SearchingService(QObject* parent) : QObject{parent} {}

void SearchingService::startSearching(const QString& searchingName, const QString& currentDirectoryPath)
{
    QDir currentDirectory = QDir(currentDirectoryPath);
    QStringList searchingResult = QStringList();
    searchingResult.append(search(searchingName, currentDirectory));
    emit searchingCompletedSignal(searchingResult);
}

QStringList SearchingService::search(const QString& searchingName, QDir& currentDirectory)
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
	    searchingResult.append(search(searchingName, currentDirectory));
	    currentDirectory.cdUp();
	}
    }
    return searchingResult;
}
