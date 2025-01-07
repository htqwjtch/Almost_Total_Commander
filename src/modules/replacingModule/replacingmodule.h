#ifndef REPLACINGMODULE_H
#define REPLACINGMODULE_H

#include "../../modules/copyingModule/copyingmodule.h"
#include "../../modules/removingModule/removingmodule.h"

#include <QObject>
#include <QThread>

class ReplacingModule : public QObject
{
    Q_OBJECT
  public:
    explicit ReplacingModule(QObject *parent = nullptr);
    ~ReplacingModule();
    void replace(const QStringList &, const QString &);

  private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void connectSignalsWithSlotsForCopying();
    void connectSignalsWithSlotsForRemoving();
    void setReplacingObjectPathes(const QStringList &);

  private slots:
    void copyingCompleted();
    void copyingFailed(const QString &);
    void removingCompleted();
    void removingFailed(const QString &);

  private:
    QStringList replacingObjectPathes;
    CopyingModule *copyingModule;
    RemovingModule *removingModule;

  signals:
    void replacingCompletedSignal();
    void replacingFailedSignal(QString);
};

#endif // REPLACINGMODULE_H
