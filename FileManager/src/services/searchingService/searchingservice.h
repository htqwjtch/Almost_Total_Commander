#ifndef SEARCHINGSERVICE_H
#define SEARCHINGSERVICE_H

#include <QDir>
#include <QObject>
#include <QThread>

class SearchingService : public QObject
{
    Q_OBJECT
public:
    explicit SearchingService(QObject* parent = nullptr);

public slots:
    void startSearching(const QString&, const QString&);

private:
    QStringList search(QDir&, const QString&);

signals:
    void searchingFinished(QStringList);
};

#endif // SEARCHINGSERVICE_H
