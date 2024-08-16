#ifndef SEARCHINGSERVICE_H
#define SEARCHINGSERVICE_H

#include <QDir>
#include <QObject>

class SearchingService : public QObject
{
    Q_OBJECT
public:
    explicit SearchingService(QObject* parent = nullptr);

public slots:
    void startSearching(const QString&, const QString&);

private:
    QStringList search(const QString&, QDir&);

signals:
    void searchingIsPerformedSignal(QStringList);
};

#endif // SEARCHINGSERVICE_H
