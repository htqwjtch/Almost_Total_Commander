#ifndef CREATINGMODULE_H
#define CREATINGMODULE_H

#include "../../services/creatingService/creatingservice.h"

#include <QDialog>
#include <QMessageBox>

namespace Ui
{
    class CreatingModule;
}

class CreatingModule : public QDialog
{
    Q_OBJECT

public:
    CreatingModule(QDir&, QWidget* parent = nullptr);
    ~CreatingModule();

private:
    void setUserInterface();
    void setButtonsStyleSheets();

private slots:
    void on_fileCreationButton_clicked();
    void on_directoryCreationButton_clicked();
    void on_symbolLinkCreationButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreatingModule* ui;
    CreatingService* creatingService;
};

#endif // CREATINGMODULE_H
