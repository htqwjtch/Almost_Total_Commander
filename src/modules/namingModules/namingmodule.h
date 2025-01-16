#ifndef NAMINGMODULE_H
#define NAMINGMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "namingNotSymbolLinkModule/namingnotsymbollinkmodule.h"
#include "namingSymbolLinkModule/namingsymbollinkmodule.h"

#include <QDir>
#include <QMessageBox>

class NamingModule : public QObject
{
    Q_OBJECT

  public:
    explicit NamingModule(QDir &, QObject *parent = nullptr);
    void setNameAndPathForNotSymbolLink();
    void setNameAndPathesForSymbolLink();
    QString getName();
    QString getPath();
    QString getLinkedPath();
    void rename(const QString &);

  private:
    void checkName(const QString &);

  private:
    NamingNotSymbolLinkModule namingNotSymbolLinkModule;
    NamingSymbolLinkModule namingSymbolLinkModule;
    QDir currentFolder;
    QString name = "";
    QString path = "";
    QString linkedPath = "";

  signals:
    void namingCompletedSignal(QString, QString, QString);
};

#endif // NAMINGMODULE_H
