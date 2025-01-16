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
    explicit CopyingModule(QObject *parent = nullptr);
    ~CopyingModule();
    void copy(const QStringList &, const QString &);

  private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void setThreadForCopying();

  private slots:
    void copyingFinished(const QStringList &);

  private:
    CopyingService *copyingService;
    QThread *threadForCopying;

    QStringList copyingObjectPathes;

  signals:
    void startCopyingSignal(QStringList, QString);
    void copyingCompletedSignal(QStringList);
    void copyingFailedSignal(QStringList);
};

#endif // COPYINGMODULE_H
