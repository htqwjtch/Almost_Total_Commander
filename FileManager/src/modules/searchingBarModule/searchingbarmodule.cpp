#include "searchingbarmodule.h"
#include "ui_searchingbarmodule.h"

SearchingBarModule::SearchingBarModule(QWidget* parent) : QWidget(parent), ui(new Ui::SearchingBarModule)
{
    ui->setupUi(this);
}

SearchingBarModule::~SearchingBarModule()
{
    delete ui;
}

void SearchingBarModule::on_searchingLineEdit_textEdited(const QString& arg1)
{
    searchingName = arg1;
}

void SearchingBarModule::on_searchingLineEdit_returnPressed()
{
    on_searchingButton_clicked();
}

void SearchingBarModule::on_searchingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	checkCurrentFolder();
	ui->searchingButton->setEnabled(false);
	setSearchingModule();
	searchingModule->search(searchingName, currentFolder.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void TabModule::checkCurrentFolder()
{
    if (currentTableView == ui->leftTableView)
    {
	setCurrentFolder(leftTableViewFolder);
    }
    if (currentTableView == ui->rightTableView)
    {
	setCurrentFolder(rightTableViewFolder);
    }
    if (!currentFolder.absolutePath().contains(currentFolder.homePath()))
    {
	throw ExceptionService("There is no access to perform any operation in this folder!");
    }
}

void TabModule::setCurrentFolder(QDir& currentFolder)
{
    this->currentFolder = currentFolder;
}

void TabModule::setSearchingModule()
{
    searchingModule = new SearchingModule(this);
    QObject::connect(searchingModule, SIGNAL(searchingCompletedSignal()), this, SLOT(searchingCompleted()));
}

void TabModule::searchingCompleted()
{
    ui->searchingButton->setEnabled(true);
    ui->searchingLineEdit->setText("Enter searching name");
    searchingModule->exec();
    delete searchingModule;
}
