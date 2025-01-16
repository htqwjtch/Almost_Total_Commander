#include "removingmodule.h"

RemovingModule::RemovingModule(QObject *parent) : QObject{parent}
{
    allocateMemory();
    connectSignalsWithSlots();
    setThreadForRemoving();
}

void RemovingModule::allocateMemory()
{
    removingService = new RemovingService();
    threadForRemoving = new QThread(this);
}

void RemovingModule::connectSignalsWithSlots()
{
    QObject::connect(this, SIGNAL(destroyed()), threadForRemoving, SLOT(quit()));
    QObject::connect(this,
        SIGNAL(startRemovingSignal(QStringList)),
        removingService,
        SLOT(startRemoving(const QStringList &)));
    QObject::connect(removingService,
        SIGNAL(removingFinishedSignal(QStringList)),
        this,
        SLOT(removingFinished(const QStringList &)));
}

void RemovingModule::setThreadForRemoving()
{
    removingService->moveToThread(threadForRemoving);
    threadForRemoving->start();
}

RemovingModule::~RemovingModule()
{
    emit threadForRemoving->quit();
    threadForRemoving->wait();
    delete threadForRemoving;
    delete removingService;
}

void RemovingModule::remove(const QStringList &removingObjectPathes)
{
    this->removingObjectPathes = removingObjectPathes;
    emit startRemovingSignal(removingObjectPathes);
}

void RemovingModule::removingFinished(const QStringList &removedObjectNames)
{
    if (removingObjectPathes.length() == removedObjectNames.length())
    {
        emit removingCompletedSignal();
    }
    else
    {
        emit removingFailedSignal();
    }
}
