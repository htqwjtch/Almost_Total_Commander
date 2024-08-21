#ifndef REMOVINGSERVICE_H
#define REMOVINGSERVICE_H

#include <QDir>
#include <QFile>
#include <QObject>

class RemovingService : public QObject
{
    Q_OBJECT

public:
    explicit RemovingService(QObject* parent = nullptr);

public slots:
    void startRemoving(const QString&);

private:
    void removeFolder(const QString&);
    void removeFolderObjectsFrom(QDir&);

signals:
    void removingCompletedSignal();
    void removingFailedSignal(QString);
};

#endif // REMOVINGSERVICE_H
