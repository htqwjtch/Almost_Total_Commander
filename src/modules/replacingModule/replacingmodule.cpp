#include "replacingmodule.h"

ReplacingModule::ReplacingModule(QObject *parent) : QObject{parent}
{
    allocateMemory();
    connectSignalsWithSlots();
}

void ReplacingModule::allocateMemory()
{
    copyingModule = new CopyingModule(this);
    removingModule = new RemovingModule(this);
}

void ReplacingModule::connectSignalsWithSlots()
{
    replacingObjectPathes = QStringList();
    connectSignalsWithSlotsForCopying();
    connectSignalsWithSlotsForRemoving();
}

void ReplacingModule::connectSignalsWithSlotsForCopying()
{
    QObject::connect(
        copyingModule, SIGNAL(copyingCompletedSignal()), this, SLOT(copyingCompleted()));
    QObject::connect(copyingModule,
        SIGNAL(copyingFailedSignal(QString)),
        this,
        SLOT(copyingFailed(const QString &)));
}

void ReplacingModule::connectSignalsWithSlotsForRemoving()
{
    QObject::connect(
        removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule,
        SIGNAL(removingFailedSignal(QString)),
        this,
        SLOT(removingFailed(const QString &)));
}

ReplacingModule::~ReplacingModule()
{
    delete removingModule;
    delete copyingModule;
}

void ReplacingModule::replace(const QStringList &replacingObjectPathes,
    const QString &destinationFolderPath)
{

    setReplacingObjectPathes(replacingObjectPathes);
    copyingModule->copy(replacingObjectPathes, destinationFolderPath);
}

void ReplacingModule::setReplacingObjectPathes(const QStringList &replacingObjectPathes)
{
    this->replacingObjectPathes = replacingObjectPathes;
}

void ReplacingModule::copyingCompleted() { removingModule->remove(replacingObjectPathes); }

void ReplacingModule::copyingFailed(const QString &exceptionInfo)
{
    emit replacingFailedSignal(exceptionInfo);
}

void ReplacingModule::removingCompleted() { emit replacingCompletedSignal(); }

void ReplacingModule::removingFailed(const QString &exceptionInfo)
{
    emit replacingFailedSignal(exceptionInfo);
}
