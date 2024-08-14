#ifndef CREATINGSERVICE_H
#define CREATINGSERVICE_H

#include "../../modules/namingModules/namingmodule.h"

class CreatingService
{
public:
    CreatingService() = default;
    CreatingService(QDir&);
    void createFile();
    void createDirectory();
    void createSymbolLink();

private:
    void isNewElementNameUnique();

public:
    QDir currentDirectory;
    NamingModule namingModule;
};

#endif // CREATINGSERVICE_H
