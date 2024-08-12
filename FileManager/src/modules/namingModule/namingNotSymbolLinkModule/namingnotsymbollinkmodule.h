#ifndef NAMINGNOTSYMBOLLINKMODULE_H
#define NAMINGNOTSYMBOLLINKMODULE_H

#include <QDialog>

namespace Ui
{
    class NamingNotSymbolLinkModule;
}

class NamingNotSymbolLinkModule : public QDialog
{
    Q_OBJECT

public:
    explicit NamingNotSymbolLinkModule(QWidget* parent = nullptr);
    ~NamingNotSymbolLinkModule();
    QString getName();

private:
    void setUserInterface();

private slots:
    void on_nameEdit_textEdited(const QString& arg1);
    void on_nameEdit_returnPressed();
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::NamingNotSymbolLinkModule* ui;
    QString name;
};

#endif // NAMINGNOTSYMBOLLINKMODULE_H
