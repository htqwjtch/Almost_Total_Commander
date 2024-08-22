#include "viewingbarmodule.h"
#include "ui_viewingbarmodule.h"

ViewingBarModule::ViewingBarModule(QWidget* parent) : QWidget(parent), ui(new Ui::ViewingBarModule)
{
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot);
    fileSystemModel->setRootPath(QDir::rootPath());

    ui->setupUi(this);

    ui->leftTableView->setModel(fileSystemModel);
    ui->rightTableView->setModel(fileSystemModel);

    ui->leftTableView->setShowGrid(false);
    ui->rightTableView->setShowGrid(false);
    ui->leftTableView->horizontalHeader()->hide();
    ui->rightTableView->horizontalHeader()->hide();
    ui->leftTableView->verticalHeader()->hide();
    ui->rightTableView->verticalHeader()->hide();
    ui->leftTableView->setColumnHidden(1, true);
    ui->leftTableView->setColumnHidden(2, true);
    ui->leftTableView->setColumnHidden(3, true);
    ui->rightTableView->setColumnHidden(1, true);
    ui->rightTableView->setColumnHidden(2, true);
    ui->rightTableView->setColumnHidden(3, true);
    ui->leftTableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->rightTableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->leftTableView->setSortingEnabled(true);
    ui->rightTableView->setSortingEnabled(true);

    setTableViewsFolders();

    leftTableViewFolder.cd(leftTableViewFolder.homePath());
    rightTableViewFolder.cd(rightTableViewFolder.homePath());

    ui->leftTableView->setRootIndex(fileSystemModel->index(leftTableViewFolder.absolutePath()));
    ui->rightTableView->setRootIndex(fileSystemModel->index(rightTableViewFolder.absolutePath()));

    connect(ui->rightTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_leftTableView_clicked(QModelIndex)));
    connect(ui->rightTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_leftTableView_doubleClicked(QModelIndex)));

    setCurrentTableView(ui->leftTableView);
}

void ViewingBarModule::setTableViewsFolders()
{
    leftTableViewFolder = QDir(fileSystemModel->filePath(ui->leftTableView->rootIndex()));
    rightTableViewFolder = QDir(fileSystemModel->filePath(ui->rightTableView->rootIndex()));
}

void ViewingBarModule::setCurrentTableView(QTableView* currentTableView)
{
    this->currentTableView = currentTableView;
}

ViewingBarModule::~ViewingBarModule()
{
    delete ui;
}

void ViewingBarModule::on_leftTableView_clicked(const QModelIndex& index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    QString folderPath = "";
    QString filePath = "";
    setCurrentTableView((QTableView*)sender());
    if (currentFileInfo.isDir())
    {
	folderPath = currentFileInfo.absoluteFilePath();
	filePath = "";
	setLabelGridLayoutForFolder();
    }
    else
    {
	folderPath = "";
	filePath = currentFileInfo.absoluteFilePath();
	setLabelGridLayoutForFile();
    }
    setClickedFolderPath(folderPath);
    setClickedFilePath(filePath);
}

void ViewingBarModule::setCurrentFileInfo(QFileInfo currentFileInfo)
{
    this->currentFileInfo = currentFileInfo;
}

void ViewingBarModule::setClickedFolderPath(const QString& clickedFolderPath)
{
    this->clickedFolderPath = clickedFolderPath;
}

void ViewingBarModule::setClickedFilePath(const QString& clickedFilePath)
{
    this->clickedFilePath = clickedFilePath;
}

void ViewingBarModule::on_leftTableView_doubleClicked(const QModelIndex& index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    if (currentFileInfo.isDir())
    {
	currentTableView->setRootIndex(fileSystemModel->index(clickedFolderPath));
	if (currentTableView == ui->leftTableView)
	{
	    setCurrentLineEdit(ui->leftLineEdit);
	}
	else if (currentTableView == ui->rightTableView)
	{
	    setCurrentLineEdit(ui->rightLineEdit);
	}
	currentLineEdit->setText(currentFileInfo.absoluteFilePath());
    }
    else
    {
	QDesktopServices::openUrl(QUrl::fromUserInput(clickedFilePath));
    }
    setClickedFilePath("");
    setClickedFolderPath("");
}

void ViewingBarModule::selectFolder(QFileInfo& fileInfo)
{
    currentTableView->setRootIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    setLabelGridLayoutForFolder();
}

void ViewingBarModule::selectFile(QFileInfo& fileInfo)
{
    currentTableView->setRootIndex(fileSystemModel->index(fileInfo.absolutePath()));
    currentTableView->setCurrentIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    currentTableView->selectionModel()->clearSelection();
    currentTableView->selectionModel()->select(fileSystemModel->index(fileInfo.absoluteFilePath()),
					       QItemSelectionModel::Select | QItemSelectionModel::Rows);
    setLabelGridLayoutForFile();
}
