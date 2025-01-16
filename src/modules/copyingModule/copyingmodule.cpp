#include "copyingmodule.h"

CopyingModule::CopyingModule(QObject *parent) : QObject{parent}
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
    QObject::connect(this,
        SIGNAL(startCopyingSignal(QStringList, QString)),
        copyingService,
        SLOT(startCopying(const QStringList &, const QString &)));
    QObject::connect(copyingService,
        SIGNAL(copyingFinishedSignal(QStringList)),
        this,
        SLOT(copyingFinished(const QStringList &)));
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

void CopyingModule::copy(const QStringList &copyingObjectPathes,
    const QString &destinationFolderPath)
{
    this->copyingObjectPathes = copyingObjectPathes;
    emit startCopyingSignal(copyingObjectPathes, destinationFolderPath);
}

void CopyingModule::copyingFinished(const QStringList &copiedObjectPathes)
{
    if (copyingObjectPathes.length() == copiedObjectPathes.length())
    {
        emit copyingCompletedSignal(copiedObjectPathes);
    }
    else
    {
        emit copyingFailedSignal(copiedObjectPathes);
    }
}
