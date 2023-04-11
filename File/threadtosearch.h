#ifndef THREADTOSEARCH_H
#define THREADTOSEARCH_H

#include "container.h"

#include <QDir>
#include <QFileInfo>
#include <QObject>

class ThreadToSearch : public QObject
{
    Q_OBJECT
    List list;
    List::Iterator iter;

public slots:
    void runSearch(QString lDirPath, QString rDirPath, QString searchName);

public:
    explicit ThreadToSearch(QObject* parent = nullptr);
    void search(QDir&, QString);

signals:
};

#endif // THREADTOSEARCH_H
