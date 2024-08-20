#ifndef CREATINGSERVICE_H
#define CREATINGSERVICE_H

#include "../../modules/namingModules/namingmodule.h"

class CreatingService
{
public:
    CreatingService(QDir&);
    void createFile();
    void createDirectory();
    void createSymbolLink();

private:
    void createNameAndPathForNotSymbolLink();
    void createNameAndPathesForSymbolLink();

private:
    QDir currentDirectory;
    NamingModule namingModule;
};

#endif // CREATINGSERVICE_H
