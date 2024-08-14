#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../form/form.h"

#include <QMainWindow> //предоставляет главное окно приложения

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow //класс главного окна приложения
{
    Q_OBJECT
    //теперь можем использовать сигналы-слоты в классе
    Ui::MainWindow* ui; //указатель на объект соотв типа в классе основной формы
    Form* form;         //указатель для связи с моделью данных для файловой системы

    // ThreadToSearch* thSearch;

    // SearchResult* window;

private slots:

    void on_tabWidget_tabCloseRequested(int index);

    void on_CtrlX_triggered();

    void on_CtrlC_triggered();

    void on_CtrlEsc_triggered();

    void on_CtrlN_triggered();

    void on_CtrlLeft_triggered();

    void on_CtrlRight_triggered();

    void on_CtrlDel_triggered();

    void on_CtrlT_triggered();

    void on_CtrlR_triggered();

    void on_CtrlD_triggered();

    void on_CtrlF_triggered();

public slots:
    void add_tab();

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
