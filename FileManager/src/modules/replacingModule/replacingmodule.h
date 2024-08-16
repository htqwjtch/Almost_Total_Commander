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
    explicit ReplacingModule(QObject* parent = nullptr);
    ~ReplacingModule();
    void setReplacingObjectPath(const QString&);
    void replaceIn(const QString&);

private:
    void allocateMemory();
    void connectSignalsWithSlots();
    void connectSignalsWithSlotsForCopying();
    void connectSignalsWithSlotsForRemoving();

private slots:
    void copyingIsPerformed();
    void copyingIsNotPerformed();
    void removingIsPerformed();
    void removingIsNotPerformed();

private:
    QString replacingObjectPath = "";
    CopyingModule* copyingModule;
    RemovingModule* removingModule;

signals:
    void replacingIsPerformedSignal();
    void replacingIsNotPerformedSignal();
};

#endif // REPLACINGMODULE_H
