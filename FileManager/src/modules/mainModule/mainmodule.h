#ifndef MAINMODULE_H
#define MAINMODULE_H

#include "../tabModule/tabmodule.h"

#include <QMainWindow>
#include <QToolButton>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainModule;
}
QT_END_NAMESPACE

class MainModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainModule(QWidget* parent = nullptr);
    ~MainModule();

private:
    void setUserInterface();
    void setAddTabButton();
    void setAddTabButtonTab();

private slots:
    void on_actionAdd_Tab_triggered();
    void addTab();
    void on_actionClose_Tab_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionLeft_tab_triggered();
    void on_actionRight_Tab_triggered();
    void on_actionExit_triggered();
    void on_actionSearch_triggered();
    void on_actionCreate_triggered();
    void on_actionRemove_triggered();
    void on_actionCopy_triggered();
    void on_actionReplace_triggered();
    void on_actionRename_triggered();

private:
    Ui::MainModule* ui;
    QToolButton* addTabButton;
    TabModule* tabModule;
};

#endif // MAINMODULE_H
