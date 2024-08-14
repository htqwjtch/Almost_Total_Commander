#ifndef MAINMODULE_H
#define MAINMODULE_H

#include "form/form.h"

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

private:
    Ui::MainModule* ui;
    QToolButton* addTabButton;
    Form* tabModule;
};

#endif // MAINMODULE_H
