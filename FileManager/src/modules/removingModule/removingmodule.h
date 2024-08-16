#ifndef REMOVINGMODULE_H
#define REMOVINGMODULE_H

#include "../../services/removingService/removingservice.h"

#include <QObject>
#include <QThread>

class RemovingModule : public QObject
{
    Q_OBJECT

public:
    explicit RemovingModule(QObject* parent = nullptr);
    ~RemovingModule();
    void remove(const QString&);

private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void setThreadForRemoving();

private slots:
    void removingIsPerformed();
    void removingIsNotPerformed();

private:
    RemovingService* removingService;
    QThread* threadForRemoving;

signals:
    void startRemovingSignal(QString);
    void removingIsPerformedSignal();
    void removingIsNotPerformedSignal();
};

#endif // REMOVINGMODULE_H
