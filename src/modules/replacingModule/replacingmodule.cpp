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
    connectSignalsWithSlotsForCopying();
    connectSignalsWithSlotsForRemoving();
}

void ReplacingModule::connectSignalsWithSlotsForCopying()
{
    QObject::connect(copyingModule,
        SIGNAL(copyingCompletedSignal(QStringList)),
        this,
        SLOT(copyingCompleted(const QStringList &)));
    QObject::connect(copyingModule,
        SIGNAL(copyingFailedSignal(QStringList)),
        this,
        SLOT(copyingFailed(const QStringList &)));
}

void ReplacingModule::connectSignalsWithSlotsForRemoving()
{
    QObject::connect(
        removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule, SIGNAL(removingFailedSignal()), this, SLOT(removingFailed()));
}

ReplacingModule::~ReplacingModule()
{
    delete removingModule;
    delete copyingModule;
}

void ReplacingModule::replace(const QStringList &replacingObjectPathes,
    const QString &destinationFolderPath)
{
    this->replacingObjectPathes = replacingObjectPathes;
    QFileInfo fileInfo = QFileInfo(replacingObjectPathes[0]);
    sourceFolderPath = fileInfo.absolutePath();
    copyingModule->copy(replacingObjectPathes, destinationFolderPath);
}

void ReplacingModule::copyingCompleted(const QStringList &copiedObjectPathes)
{
    replacedObjectPathes = copiedObjectPathes;
    removingModule->remove(replacingObjectPathes);
}

void ReplacingModule::copyingFailed(const QStringList &copiedObjectPathes)
{
    replacedObjectPathes = copiedObjectPathes;
    removingModule->remove(replacingObjectPathes);
}

void ReplacingModule::removingCompleted()
{
    emit replacingCompletedSignal(replacedObjectPathes, sourceFolderPath);
}

void ReplacingModule::removingFailed()
{
    emit replacingFailedSignal(replacedObjectPathes, sourceFolderPath);
}
