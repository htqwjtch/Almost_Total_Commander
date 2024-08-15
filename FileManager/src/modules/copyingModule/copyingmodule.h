#ifndef COPYINGMODULE_H
#define COPYINGMODULE_H

#include "../../services/copyingService/copyingservice.h"

#include <QObject>
#include <QThread>

class CopyingModule : public QObject
{
    Q_OBJECT

public:
    explicit CopyingModule(QObject* parent = nullptr);
    ~CopyingModule();
    void copy(const QString&, const QString&, const QString&);

private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void setThreadForCopying();

private slots:
    void copyingIsPerformed();
    void copyingIsNotPerformed();

private:
    CopyingService* copyingService;
    QThread* threadForCopying;

signals:
    void startCopyingSignal(QString, QString, QString);
    void copyingIsPerformedSignal();
    void copyingIsNotPerformedSignal();
};

#endif // COPYINGMODULE_H
