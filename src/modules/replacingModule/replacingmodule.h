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

  private slots:
    void copyingCompleted(const QStringList &);
    void copyingFailed(const QStringList &);
    void removingCompleted();
    void removingFailed();

  private:
    QString sourceFolderPath;
    QStringList replacingObjectPathes;
    QStringList replacedObjectPathes;
    CopyingModule *copyingModule;
    RemovingModule *removingModule;

  signals:
    void replacingCompletedSignal(QStringList, QString);
    void replacingFailedSignal(QStringList, QString);
};

#endif // REPLACINGMODULE_H
