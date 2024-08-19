#include "namingsymbollinkmodule.h"
#include "ui_namingsymbollinkmodule.h"

NamingSymbolLinkModule::NamingSymbolLinkModule(QWidget* parent) : QDialog(parent), ui(new Ui::NamingSymbolLinkModule)
{
    setUserInterface();
}

void NamingSymbolLinkModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Naming");
    ui->nameEdit->setText("Enter name");
    ui->linkedPathEdit->setText("Enter linked path");
}

NamingSymbolLinkModule::~NamingSymbolLinkModule()
{
    delete ui;
}

QString NamingSymbolLinkModule::getName()
{
    return name;
}

QString NamingSymbolLinkModule::getLinkedPath()
{
    return linkedPath;
}

void NamingSymbolLinkModule::on_nameEdit_textEdited(const QString& arg1)
{
    name = arg1;
}

void NamingSymbolLinkModule::on_nameEdit_returnPressed()
{
    ui->linkedPathEdit->clear();
}

void NamingSymbolLinkModule::on_linkedPathEdit_textEdited(const QString& arg1)
{
    linkedPath = arg1;
}

void NamingSymbolLinkModule::on_linkedPathEdit_returnPressed()
{
    on_okButton_clicked();
}

void NamingSymbolLinkModule::on_okButton_clicked()
{
    accept();
}

void NamingSymbolLinkModule::on_cancelButton_clicked()
{
    name.clear();
    linkedPath.clear();
    accept();
}
