#ifndef NAMINGMODULE_H
#define NAMINGMODULE_H

#include "namingNotSymbolLinkModule/namingnotsymbollinkmodule.h"
#include "namingSymbolLinkModule/namingsymbollinkmodule.h"

#include <QDir>

class NamingModule
{
public:
    NamingModule() = default;
    void setCurrentDirectory(QDir&);
    void enterNameForNotSymbolLink();
    void enterNameAndLinkedPathForSymbolLink();
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
