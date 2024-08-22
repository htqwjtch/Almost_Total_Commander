#ifndef TOOLBARMODULE_H
#define TOOLBARMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "../copyingModule/copyingmodule.h"
#include "../creatingModule/creatingmodule.h"
#include "../namingModules/namingmodule.h"
#include "../removingModule/removingmodule.h"
#include "../replacingModule/replacingmodule.h"

#include <QMessageBox>
#include <QWidget>

namespace Ui
{
    class ToolBarModule;
}

class ToolBarModule : public QWidget
{
    Q_OBJECT

public:
    explicit ToolBarModule(QWidget* parent = nullptr);
    ~ToolBarModule();

private slots:
    void on_creatingButton_clicked();

    void on_removingButton_clicked();

    void on_copyingButton_clicked();

    void on_replacingButton_clicked();

    void on_renamingButton_clicked();

    void on_hiddenButton_clicked();

    void on_sortingBox_currentIndexChanged(int index);

private:
    Ui::ToolBarModule* ui;

    CreatingModule* creatingModule;
    RemovingModule* removingModule;
    CopyingModule* copyingModule;
    ReplacingModule* replacingModule;
};

#endif // TOOLBARMODULE_H
