#include "trashmodule.h"
#include "ui_trashmodule.h"

#include <QDebug>
#include <QDir>
#include <QFile>

TrashModule::TrashModule(QWidget *parent) : QDialog(parent), ui(new Ui::TrashModule)
{
    ui->setupUi(this);
}

TrashModule::~TrashModule() { delete ui; }

bool TrashModule::checkTrash() { return QDir(QDir::homePath() + "/.local/share/Trash").exists(); }

void TrashModule::moveToTrash(const QStringList &removingObjectPathes)
{
    foreach (QString removingObjectPath, removingObjectPathes)
    {
        if (!QFile::moveToTrash(removingObjectPath))
        {
            emit removingFailedSignal("Removing failed!");
        }
    }
    emit removingCompletedSignal();
}

void TrashModule::removePermanently(const QStringList &removingObjectPathes)
{
    setRemovingModule();
    removingModule->remove(removingObjectPathes);
}

void TrashModule::setRemovingModule()
{
    removingModule = new RemovingModule(this);
    QObject::connect(
        removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule,
        SIGNAL(removingFailedSignal(QString)),
        this,
        SLOT(removingFailed(const QString &)));
}

void TrashModule::removingFailed(const QString &exceptionInfo)
{
    emit removingFailedSignal(exceptionInfo);
    delete removingModule;
}

void TrashModule::removingCompleted()
{
    emit removingCompletedSignal();
    delete removingModule;
}

void TrashModule::on_restoringButton_clicked() {}

void TrashModule::on_removingButton_clicked() {}

void TrashModule::on_tableView_clicked(const QModelIndex &index) {}

void TrashModule::on_tableView_doubleClicked(const QModelIndex &index) {}
