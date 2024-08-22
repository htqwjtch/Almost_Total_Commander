#include "toolbarmodule.h"
#include "ui_toolbarmodule.h"

ToolBarModule::ToolBarModule(QWidget* parent) : QWidget(parent), ui(new Ui::ToolBarModule)
{
    ui->setupUi(this);

    ui->creatingButton->setStyleSheet("QPushButton {"
				      "    border: none;"
				      "}"
				      "QPushButton:hover {"
				      "    border: 1px ridge grey;"
				      "}");
    ui->removingButton->setStyleSheet("QPushButton {"
				      "    border: none;"
				      "}"
				      "QPushButton:hover {"
				      "    border: 1px ridge grey;"
				      "}");
    ui->copyingButton->setStyleSheet("QPushButton {"
				     "    border: none;"
				     "}"
				     "QPushButton:hover {"
				     "    border: 1px ridge grey;"
				     "}");
    ui->replacingButton->setStyleSheet("QPushButton {"
				       "    border: none;"
				       "}"
				       "QPushButton:hover {"
				       "    border: 1px ridge grey;"
				       "}");
    ui->renamingButton->setStyleSheet("QPushButton {"
				      "    border: none;"
				      "}"
				      "QPushButton:hover {"
				      "    border: 1px ridge grey;"
				      "}");
    ui->hiddenButton->setStyleSheet("QPushButton {"
				    "    border: none;"
				    "}"
				    "QPushButton:hover {"
				    "    border: 1px ridge grey;"
				    "}");

    connect(ui->sortingBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ToolBarModule::on_sortingBox_currentIndexChanged);

    on_sortingBox_currentIndexChanged(0);
}

ToolBarModule::~ToolBarModule()
{
    delete ui;
}

void ToolBarModule::on_creatingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	checkCurrentFolder();
	CreatingModule creatingModule = CreatingModule(currentFolder, this);
	creatingModule.exec();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void ToolBarModule::on_removingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	checkCurrentFolder();
	checkClickedObjectsPathes();
	QMessageBox::StandardButton answerButton
	    = QMessageBox::question(this, "", "Do you want to perform removing?", QMessageBox::Cancel | QMessageBox::Ok);
	if (answerButton == QMessageBox::Ok)
	{
	    ui->removingButton->setEnabled(false);
	    setRemovingModule();
	    removingModule->remove(currentFileInfo.absoluteFilePath());
	}
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void TabModule::checkClickedObjectsPathes()
{
    if (!clickedFolderPath.isEmpty())
    {
	setCurrentFileInfo(QFileInfo(clickedFolderPath));
    }
    else if (!clickedFilePath.isEmpty())
    {
	setCurrentFileInfo(QFileInfo(clickedFilePath));
    }
    else
    {
	throw ExceptionService("You was not choose a file or a folder!");
    }
}

void TabModule::setRemovingModule()
{
    removingModule = new RemovingModule(this);
    QObject::connect(removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule, SIGNAL(removingFailedSignal(QString)), this, SLOT(removingFailed(const QString&)));
}

void TabModule::removingFailed(const QString& exceptionInfo)
{
    removingCompleted();
    QMessageBox::warning(this, "", exceptionInfo);
}

void TabModule::removingCompleted()
{
    ui->removingButton->setEnabled(true);
    delete removingModule;
}

void ToolBarModule::on_copyingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	if (!leftTableViewFolder.absolutePath().contains(leftTableViewFolder.homePath())
	    || !rightTableViewFolder.absolutePath().contains(rightTableViewFolder.homePath()))
	{
	    throw ExceptionService("There is no access to perform any operation in this folder!");
	}
	checkClickedObjectsPathes();
	ui->copyingButton->setEnabled(false);
	setCopyingModule();
	copyingModule->copy(currentFileInfo.absoluteFilePath(), rightTableViewFolder.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void TabModule::setCopyingModule()
{
    copyingModule = new CopyingModule(this);
    QObject::connect(copyingModule, SIGNAL(copyingCompletedSignal()), this, SLOT(copyingCompleted()));
    QObject::connect(copyingModule, SIGNAL(copyingFailedSignal(QString)), this, SLOT(copyingFailed(const QString&)));
}

void TabModule::copyingFailed(const QString& exceptionInfo)
{
    copyingCompleted();
    QMessageBox::warning(this, "", exceptionInfo);
}

void TabModule::copyingCompleted()
{
    ui->copyingButton->setEnabled(true);
    delete copyingModule;
}

void ToolBarModule::on_replacingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	if (!leftTableViewFolder.absolutePath().contains(leftTableViewFolder.homePath())
	    || !rightTableViewFolder.absolutePath().contains(rightTableViewFolder.homePath()))
	{
	    throw ExceptionService("There is no access to perform any operation in this folder!");
	}
	checkClickedObjectsPathes();
	ui->replacingButton->setEnabled(false);
	setReplacingModule();
	replacingModule->replace(currentFileInfo.absoluteFilePath(), rightTableViewFolder.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void TabModule::setReplacingModule()
{
    replacingModule = new ReplacingModule(this);
    QObject::connect(replacingModule, SIGNAL(replacingCompletedSignal()), this, SLOT(replacingCompleted()));
    QObject::connect(replacingModule, SIGNAL(replacingFailedSignal(QString)), this, SLOT(replacingFailed(const QString&)));
}

void TabModule::replacingFailed(const QString& exceptionInfo)
{
    replacingCompleted();
    QMessageBox::warning(this, "", exceptionInfo);
}

void TabModule::replacingCompleted()
{
    ui->replacingButton->setEnabled(true);
    delete replacingModule;
}

void ToolBarModule::on_renamingButton_clicked()
{
    try
    {
	setTableViewsDirectories();
	checkCurrentFolder();
	checkClickedObjectsPathes();
	NamingModule namingModule;
	namingModule.setCurrentFolder(currentFolder);
	namingModule.rename(currentFileInfo.absoluteFilePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void ToolBarModule::on_hiddenButton_clicked()
{
    static bool showHidden = false;
    if (showHidden)
    {
	fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot);
	ui->hiddenButton->setToolTip("Show Hidden");
	showHidden = false;
    }
    else
    {
	fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot | QDir::QDir::Hidden);
	ui->hiddenButton->setToolTip("Don't Show Hidden");
	showHidden = true;
    }
}

void ToolBarModule::on_sortingBox_currentIndexChanged(int index)
{
    QHeaderView* currentHeaderView;
    if (currentTableView == ui->leftTableView)
    {
	currentHeaderView = ui->leftTableView->horizontalHeader();
    }
    else
    {
	currentHeaderView = ui->rightTableView->horizontalHeader();
    }

    switch (index)
    {
    case 0:
	currentHeaderView->setSortIndicator(0, Qt::AscendingOrder);
	currentTableView->sortByColumn(0, Qt::AscendingOrder);
	break;
    case 1:
	currentHeaderView->setSortIndicator(0, Qt::DescendingOrder);
	currentTableView->sortByColumn(0, Qt::DescendingOrder);
	break;
    case 2:
	currentHeaderView->setSortIndicator(1, Qt::AscendingOrder);
	currentTableView->sortByColumn(1, Qt::AscendingOrder);
	break;
    case 3:
	currentHeaderView->setSortIndicator(2, Qt::AscendingOrder);
	currentTableView->sortByColumn(2, Qt::AscendingOrder);
	break;
    case 4:
	currentHeaderView->setSortIndicator(3, Qt::AscendingOrder);
	currentTableView->sortByColumn(3, Qt::AscendingOrder);
	break;
    case 5:
	currentHeaderView->setSortIndicator(3, Qt::DescendingOrder);
	currentTableView->sortByColumn(3, Qt::DescendingOrder);
	break;
    }
}
