#include "copyingmodule.h"

CopyingModule::CopyingModule(QObject* parent) : QObject{parent}
{
    allocateMemory();
    connectSignalsWithSlots();
    setThreadForCopying();
}

void CopyingModule::allocateMemory()
{
    copyingService = new CopyingService();
    threadForCopying = new QThread(this);
}

void CopyingModule::connectSignalsWithSlots()
{
    QObject::connect(this, SIGNAL(destroyed()), threadForCopying, SLOT(quit()));
    QObject::connect(this, SIGNAL(startCopyingSignal(QString, QString)), copyingService, SLOT(startCopying(const QString&, const QString&)));
    QObject::connect(copyingService, SIGNAL(copyingIsNotPerformedSignal()), this, SLOT(copyingIsNotPerformed()));
    QObject::connect(copyingService, SIGNAL(copyingIsPerformedSignal()), this, SLOT(copyingIsPerformed()));
}

void CopyingModule::setThreadForCopying()
{
    copyingService->moveToThread(threadForCopying);
    threadForCopying->start();
}

CopyingModule::~CopyingModule()
{
    emit threadForCopying->quit();
    threadForCopying->wait();
    delete threadForCopying;
    delete copyingService;
}

void CopyingModule::copy(const QString& copyingObjectPath, const QString& destinationDirectoryPath)
{
    emit startCopyingSignal(copyingObjectPath, destinationDirectoryPath);
}

void CopyingModule::copyingIsPerformed()
{
    emit copyingIsPerformedSignal();
}

void CopyingModule::copyingIsNotPerformed()
{
    emit copyingIsNotPerformedSignal();
}
