#ifndef COPYINGSERVICE_H
#define COPYINGSERVICE_H

#include <QDir>
#include <QFile>
#include <QObject>

class CopyingService : public QObject
{
    Q_OBJECT

public:
    explicit CopyingService(QObject* parent = nullptr);

public slots:
    void startCopying(const QString&, const QString&);

private:
    void setSourceCopyingObjectPath(const QString&);
    void setDestinationCopyingObjectPath(const QString&);
    void copyIn(const QString&);
    void copyDirectory(const QString&, const QString&);
    QFileInfoList getCopyingDirectoryObjectsList(QDir&);
    void createCopyingDirectoryInDestinationDirectory(const QString&, QDir&);
    void copyDirectoryObjects(QFileInfoList&, const QString&);

private:
    QString sourceCopyingObjectPath = "";
    QString destinationCopyingObjectPath = "";

signals:
    void copyingCompletedSignal();
    void copyingFailedSignal(QString);
};

#endif // COPYINGSERVICE_H
