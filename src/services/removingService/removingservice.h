#ifndef REMOVINGSERVICE_H
#define REMOVINGSERVICE_H

#include <QDir>
#include <QFile>
#include <QObject>

class RemovingService : public QObject
{
    Q_OBJECT

  public:
    explicit RemovingService(QObject *parent = nullptr);

  public slots:
    void startRemoving(const QStringList &);

  private:
    void removeFolder(const QString &);
    void removeFolderObjectsFrom(QDir &);

  private:
    QStringList removedObjectNames;

  signals:
    void removingFinishedSignal(QStringList);
};

#endif // REMOVINGSERVICE_H
