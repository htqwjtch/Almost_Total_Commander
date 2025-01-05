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
    void copyFolder(const QString&, const QString&);
    QFileInfoList getCopyingFolderObjectsList(QDir&);
    void createCopyingFolderInDestinationFolder(const QString&, QDir&);
    void copyFolderObjects(QFileInfoList&, const QString&);

private:
    QString sourceCopyingObjectPath = "";
    QString destinationCopyingObjectPath = "";

signals:
    void copyingCompletedSignal();
    void copyingFailedSignal(QString);
};

#endif // COPYINGSERVICE_H
