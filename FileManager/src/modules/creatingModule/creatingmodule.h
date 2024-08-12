#ifndef CREATINGMODULE_H
#define CREATINGMODULE_H

#include "../../localException/localexception.h"
#include "../namingModule/namingmodule.h"
#include "sysElem/syselem.h"

#include <QDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>

namespace Ui
{
    class CreatingModule;
}

class CreatingModule : public QDialog
{
    Q_OBJECT

public:
    explicit CreatingModule(QDir&, QWidget* parent = nullptr);
    ~CreatingModule();

private:
    void setUserInterface();
    void setButtonsInvisible();
    void isNewElementNameUnique();
    void createFile();
    void createDirectory();
    void createSymbolLink();

private slots:
    void on_fileCreationButton_clicked();
    void on_directoryCreationButton_clicked();
    void on_symbolLinkCreationButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreatingModule* ui;
    QDir currentDirectory;
    NamingModule namingModule;
};

#endif // CREATINGMODULE_H
