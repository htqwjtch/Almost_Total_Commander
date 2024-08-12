#ifndef NAMINGSYMBOLLINKMODULE_H
#define NAMINGSYMBOLLINKMODULE_H

#include <QDialog>

namespace Ui
{
    class NamingSymbolLinkModule;
}

class NamingSymbolLinkModule : public QDialog
{
    Q_OBJECT

public:
    explicit NamingSymbolLinkModule(QWidget* parent = nullptr);
    ~NamingSymbolLinkModule();
    QString getName();
    QString getPath();
    QString getLinkedPath();

private slots:
    void on_nameEdit_textEdited(const QString& arg1);
    void on_linkedPathEdit_textEdited(const QString& arg1);
    void on_okButton_clicked();
    void on_cancelButton_clicked();

    void on_nameEdit_returnPressed();

    void on_linkedPathEdit_returnPressed();

private:
    void setUserInterface();
    void setPath();

private:
    Ui::NamingSymbolLinkModule* ui;
    QString name;
    QString linkedPath;
};

#endif // NAMINGSYMBOLLINKMODULE_H
