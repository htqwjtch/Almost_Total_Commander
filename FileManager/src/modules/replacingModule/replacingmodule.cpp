#include "replacingmodule.h"

ReplacingModule::ReplacingModule(QObject* parent) : QObject{parent}
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
    connectSignalsWithSlotsForCopying();
    connectSignalsWithSlotsForRemoving();
}

void ReplacingModule::connectSignalsWithSlotsForCopying()
{
    QObject::connect(copyingModule, SIGNAL(copyingCompletedSignal()), this, SLOT(copyingCompleted()));
    QObject::connect(copyingModule, SIGNAL(copyingFailedSignal(QString)), this, SLOT(copyingFailed(const QString&)));
}

void ReplacingModule::connectSignalsWithSlotsForRemoving()
{
    QObject::connect(removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule, SIGNAL(removingFailedSignal(QString)), this, SLOT(removingFailed(const QString&)));
}

ReplacingModule::~ReplacingModule()
{
    delete removingModule;
    delete copyingModule;
}

void ReplacingModule::replace(const QString& replacingObjectPath, const QString& destinationDirectoryPath)
{
    setReplacingObjectPath(replacingObjectPath);
    copyingModule->copy(replacingObjectPath, destinationDirectoryPath);
}

void ReplacingModule::setReplacingObjectPath(const QString& replacingObjectPath)
{
    this->replacingObjectPath = replacingObjectPath;
}

void ReplacingModule::copyingCompleted()
{
    removingModule->remove(replacingObjectPath);
}

void ReplacingModule::copyingFailed(const QString& exceptionInfo)
{
    emit replacingFailedSignal(exceptionInfo);
}

void ReplacingModule::removingCompleted()
{
    emit replacingCompletedSignal();
}

void ReplacingModule::removingFailed(const QString& exceptionInfo)
{
    emit replacingFailedSignal(exceptionInfo);
}
