#ifndef THREADTOSEARCH_H
#define THREADTOSEARCH_H

#include <QDir>
#include <QFileInfo>
#include <QObject>
#include <QThread>

class ThreadToSearch : public QObject
{
    Q_OBJECT

public slots:
    void run_search(QString lDirPath, QString rDirPath, QString searchName);

public:
    explicit ThreadToSearch(QObject* parent = nullptr);
    void search(QDir&, QString, QFileInfoList&);

signals:
    void search_finished(QFileInfoList);
};

#endif // THREADTOSEARCH_H
