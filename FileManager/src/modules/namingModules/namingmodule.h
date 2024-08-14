#ifndef NAMINGMODULE_H
#define NAMINGMODULE_H

#include "../../modules/namingModules/namingNotSymbolLinkModule/namingnotsymbollinkmodule.h"
#include "../../modules/namingModules/namingSymbolLinkModule/namingsymbollinkmodule.h"

#include <QDir>

class NamingModule
{
public:
    NamingModule() = default;
    void setCurrentDirectory(QDir&);
    void setNameAndPathForNotSymbolLink();
    void setNameAndPathesForSymbolLink();
    QString getName();
    QString getPath();
    QString getLinkedPath();

private:
    NamingNotSymbolLinkModule namingNotSymbolLinkModule;
    NamingSymbolLinkModule namingSymbolLinkModule;
    QDir currentDirectory;
    QString name = "";
    QString path = "";
    QString linkedPath = "";
};

#endif // NAMINGMODULE_H
