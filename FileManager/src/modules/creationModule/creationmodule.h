#ifndef CREATIONMODULE_H
#define CREATIONMODULE_H

#include "../../localException/localexception.h"
#include "newName/newname.h"
#include "sysElem/syselem.h"

#include <QDialog>
#include <QDir>
#include <QMessageBox>
#include <QString>

namespace Ui
{
    class CreationModule;
}

class CreationModule : public QDialog
{
    Q_OBJECT

public:
    explicit CreationModule(QDir&, QWidget* parent = nullptr);
    ~CreationModule();

private:
    void create_new_element_name();
    void create_file();
    void create_directory();
    void create_symbol_link();
    QString get_new_element_path();
    void is_new_element_name_unique();

private slots:
    void on_fileCreationButton_clicked();
    void on_directoryCreationButton_clicked();
    void on_symbolLinkCreationButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreationModule* ui;
    QDir currentDirectory;
    NewName newElementName;
};

#endif // CREATIONMODULE_H
