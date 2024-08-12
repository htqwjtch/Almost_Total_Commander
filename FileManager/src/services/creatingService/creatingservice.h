#ifndef CREATINGSERVICE_H
#define CREATINGSERVICE_H

#include "../../localException/localexception.h"
#include "../../modules/namingModules/namingmodule.h"
#include "sysElem/syselem.h"

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
