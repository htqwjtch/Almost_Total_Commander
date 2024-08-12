#include "namingnotsymbollinkmodule.h"
#include "ui_namingnotsymbollinkmodule.h"

NamingNotSymbolLinkModule::NamingNotSymbolLinkModule(QWidget* parent) : QDialog(parent), ui(new Ui::NamingNotSymbolLinkModule)
{
    setUserInterface();
}

void NamingNotSymbolLinkModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Naming");
    ui->nameEdit->setText("Enter name");
}

NamingNotSymbolLinkModule::~NamingNotSymbolLinkModule()
{
    delete ui;
}

QString NamingNotSymbolLinkModule::getName()
{
    return name;
}

void NamingNotSymbolLinkModule::on_nameEdit_textEdited(const QString& arg1)
{
    name = arg1;
}

void NamingNotSymbolLinkModule::on_nameEdit_returnPressed()
{
    on_okButton_clicked();
}

void NamingNotSymbolLinkModule::on_okButton_clicked()
{
    accept();
}

void NamingNotSymbolLinkModule::on_cancelButton_clicked()
{
    name.clear();
    accept();
}
