#ifndef NAMINGMODULE_H
#define NAMINGMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "namingNotSymbolLinkModule/namingnotsymbollinkmodule.h"
#include "namingSymbolLinkModule/namingsymbollinkmodule.h"

#include <QDir>
#include <QMessageBox>

class NamingModule
{
public:
    NamingModule() = default;
    void setCurrentFolder(QDir&);
    void setNameAndPathForNotSymbolLink();
    void setNameAndPathesForSymbolLink();
    QString getName();
    QString getPath();
    QString getLinkedPath();
    void rename(const QString&);

private:
    void checkName(const QString&);

private:
    NamingNotSymbolLinkModule namingNotSymbolLinkModule;
    NamingSymbolLinkModule namingSymbolLinkModule;
    QDir currentFolder;
    QString name = "";
    QString path = "";
    QString linkedPath = "";
};

#endif // NAMINGMODULE_H
