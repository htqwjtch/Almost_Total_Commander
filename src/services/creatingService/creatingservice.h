#ifndef CREATINGSERVICE_H
#define CREATINGSERVICE_H

#include "../../modules/namingModules/namingmodule.h"
#include "../exceptionService/exceptionservice.h"

#include <QDir>
#include <QFile>
#include <QObject>
#include <unistd.h>

class CreatingService : public QObject
{
    Q_OBJECT

  public:
    explicit CreatingService(QDir &, QObject *parent = nullptr);
    ~CreatingService();
    void createFile();
    void createFolder();
    void createSymbolLink();

  private:
    void createNameAndPathForNotSymbolLink();
    void createNameAndPathesForSymbolLink();

  private:
    QDir currentFolder;
    NamingModule *namingModule;

  signals:
    void creatingFinishedSignal(QString);
};

#endif // CREATINGSERVICE_H
