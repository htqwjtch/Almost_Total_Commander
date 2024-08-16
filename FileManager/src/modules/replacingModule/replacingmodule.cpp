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
    QObject::connect(copyingModule, SIGNAL(copyingIsPerformedSignal()), this, SLOT(copyingIsPerformed()));
    QObject::connect(copyingModule, SIGNAL(copyingIsNotPerformedSignal()), this, SLOT(copyingIsNotPerformed()));
}

void ReplacingModule::connectSignalsWithSlotsForRemoving()
{
    QObject::connect(removingModule, SIGNAL(removingIsPerformedSignal()), this, SLOT(removingIsPerformed()));
    QObject::connect(removingModule, SIGNAL(removingIsNotPerformedSignal()), this, SLOT(removingIsNotPerformed()));
}

ReplacingModule::~ReplacingModule()
{
    delete removingModule;
    delete copyingModule;
}

void ReplacingModule::setReplacingObjectPath(const QString& replacingObjectPath)
{
    this->replacingObjectPath = replacingObjectPath;
}

void ReplacingModule::replaceIn(const QString& destinationDirectoryPath)
{
    copyingModule->copy(replacingObjectPath, destinationDirectoryPath);
}

void ReplacingModule::copyingIsPerformed()
{
    removingModule->remove(replacingObjectPath);
}

void ReplacingModule::copyingIsNotPerformed()
{
    emit replacingIsNotPerformedSignal();
}

void ReplacingModule::removingIsPerformed()
{
    emit replacingIsPerformedSignal();
}

void ReplacingModule::removingIsNotPerformed()
{
    emit replacingIsNotPerformedSignal();
}
