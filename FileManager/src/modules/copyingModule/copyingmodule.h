#ifndef COPYINGMODULE_H
#define COPYINGMODULE_H

#include "../../services/copyingService/copyingservice.h"
#include "../../services/exceptionService/exceptionservice.h"

#include <QMessageBox>
#include <QObject>
#include <QThread>

class CopyingModule : public QObject
{
    Q_OBJECT

public:
    explicit CopyingModule(QObject* parent = nullptr);
    ~CopyingModule();
    void copy(const QString&, const QString&);

private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void setThreadForCopying();
    void checkName(const QString&, const QString&);

private slots:
    void copyingCompleted();
    void copyingFailed(const QString&);

private:
    CopyingService* copyingService;
    QThread* threadForCopying;

signals:
    void startCopyingSignal(QString, QString);
    void copyingCompletedSignal();
    void copyingFailedSignal(QString);
};

#endif // COPYINGMODULE_H
