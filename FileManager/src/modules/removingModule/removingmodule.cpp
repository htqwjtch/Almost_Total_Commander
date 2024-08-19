#include "removingmodule.h"

RemovingModule::RemovingModule(QObject* parent) : QObject{parent}
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
    QObject::connect(this, SIGNAL(startRemovingSignal(QString)), removingService, SLOT(startRemoving(const QString&)));
    QObject::connect(removingService, SIGNAL(removingFailedSignal(QString)), this, SLOT(removingFailed(const QString&)));
    QObject::connect(removingService, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
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

void RemovingModule::remove(const QString& removingObjectPath)
{
    emit startRemovingSignal(removingObjectPath);
}

void RemovingModule::removingCompleted()
{
    emit removingCompletedSignal();
}

void RemovingModule::removingFailed(const QString& exceptionInfo)
{
    emit removingFailedSignal(exceptionInfo);
}
