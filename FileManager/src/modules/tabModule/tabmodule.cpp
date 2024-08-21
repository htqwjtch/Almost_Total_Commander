#include "tabmodule.h"
#include "ui_tabmodule.h"

#include <QDebug>

TabModule::TabModule(QWidget* parent) : QDialog(parent), ui(new Ui::TabModule)
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

    setTableViewsDirectories();

    leftTableViewFolder.cd(leftTableViewFolder.homePath());
    rightTableViewFolder.cd(rightTableViewFolder.homePath());

    ui->leftTableView->setRootIndex(fileSystemModel->index(leftTableViewFolder.absolutePath()));
    ui->rightTableView->setRootIndex(fileSystemModel->index(rightTableViewFolder.absolutePath()));

    ui->leftLineEdit->setText(leftTableViewFolder.absolutePath());
    ui->rightLineEdit->setText(rightTableViewFolder.absolutePath());
    ui->searchingLineEdit->setText("Enter searching name");

    ui->creatingButton->setToolTip("Create");
    ui->removingButton->setToolTip("Remove");
    ui->copyingButton->setToolTip("Copy");
    ui->replacingButton->setToolTip("Replace");
    ui->renamingButton->setToolTip("Rename");
    ui->showHiddenButton->setToolTip("Show Hidden");
    ui->leftAboveButton->setToolTip("Parent Folder");
    ui->rightAboveButton->setToolTip("Parent Folder");
    ui->sortingBox->setToolTip("Sort By");

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
    ui->showHiddenButton->setStyleSheet("QPushButton {"
					"    border: none;"
					"}"
					"QPushButton:hover {"
					"    border: 1px ridge grey;"
					"}");

    connect(ui->rightTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_leftTableView_clicked(QModelIndex)));
    connect(ui->rightTableView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_leftTableView_doubleClicked(QModelIndex)));

    connect(ui->rightLineEdit, SIGNAL(textEdited(QString)), this, SLOT(on_leftLineEdit_textEdited(QString)));

    connect(ui->sortingBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabModule::on_sortingBox_currentIndexChanged);

    setCurrenTableView(ui->leftTableView);
    on_sortingBox_currentIndexChanged(0);
}

void TabModule::setTableViewsDirectories()
{
    leftTableViewFolder = QDir(fileSystemModel->filePath(ui->leftTableView->rootIndex()));
    rightTableViewFolder = QDir(fileSystemModel->filePath(ui->rightTableView->rootIndex()));
}

void TabModule::setCurrenTableView(QTableView* currentTableView)
{
    this->currentTableView = currentTableView;
}

TabModule::~TabModule()
{
    delete fileSystemModel;
    delete ui;
}

void TabModule::execute(const QString& operation)
{
    if (operation == "Search")
    {
	on_searchingButton_clicked();
    }
    else if (operation == "Create")
    {
	on_creatingButton_clicked();
    }
    else if (operation == "Remove")
    {
	on_removingButton_clicked();
    }
    else if (operation == "Copy")
    {
	on_copyingButton_clicked();
    }
    else if (operation == "Replace")
    {
	on_replacingButton_clicked();
    }
    else if (operation == "Rename")
    {
	on_renamingButton_clicked();
    }
    else if (operation == "Show Hidden")
    {
	on_showHiddenButton_clicked();
    }
}

void TabModule::on_leftAboveButton_clicked()
{
    setTableViewsDirectories();
    setCurrenTableView(ui->leftTableView);
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(leftTableViewFolder.absolutePath())));
    setClickedFolderPath(currentFileInfo.absoluteFilePath());
    openDotDot();
    if (currentTableView == ui->leftTableView)
    {
	setCurrentLineEdit(ui->leftLineEdit);
    }
    else if (currentTableView == ui->rightTableView)
    {
	setCurrentLineEdit(ui->rightLineEdit);
    }
    currentLineEdit->setText(currentFileInfo.absolutePath());
    resetLabelGridLayout();
    setClickedFolderPath("");
}

void TabModule::setCurrentFileInfo(QFileInfo currentFileInfo)
{
    this->currentFileInfo = currentFileInfo;
}

void TabModule::setClickedFolderPath(const QString& clickedFolderPath)
{
    this->clickedFolderPath = clickedFolderPath;
}

void TabModule::openDotDot()
{
    QDir clickedFolder = QDir(clickedFolderPath);
    clickedFolder.cdUp();
    openFolder(clickedFolder.absolutePath());
}

void TabModule::openFolder(const QString& folderPath)
{
    currentTableView->setRootIndex(fileSystemModel->index(folderPath));
}

void TabModule::setCurrentLineEdit(QLineEdit* currentLineEdit)
{
    this->currentLineEdit = currentLineEdit;
}

void TabModule::resetLabelGridLayout()
{
    ui->typeLabel->clear();
    ui->sizeLabel->clear();
    ui->lastModeDateLabel->clear();
}

void TabModule::on_rightAboveButton_clicked()
{
    setTableViewsDirectories();
    setCurrenTableView(ui->rightTableView);
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(rightTableViewFolder.absolutePath())));
    setClickedFolderPath(currentFileInfo.absoluteFilePath());
    openDotDot();
    if (currentTableView == ui->leftTableView)
    {
	setCurrentLineEdit(ui->leftLineEdit);
    }
    else if (currentTableView == ui->rightTableView)
    {
	setCurrentLineEdit(ui->rightLineEdit);
    }
    currentLineEdit->setText(currentFileInfo.absolutePath());
    resetLabelGridLayout();
    setClickedFolderPath("");
}

void TabModule::on_leftTableView_clicked(const QModelIndex& index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    QString folderPath = "";
    QString filePath = "";
    setCurrenTableView((QTableView*)sender());
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

void TabModule::setLabelGridLayoutForFolder()
{
    setTypeLabel();
    setSizeLabelForFolder();
    setLastModeDateLabel();
}

void TabModule::setTypeLabel()
{
    QModelIndex typeIndex = currentTableView->currentIndex().siblingAtColumn(2);
    ui->typeLabel->setText(typeIndex.data().toString());
}

void TabModule::setSizeLabelForFolder()
{
    QDir folder = QDir(currentFileInfo.absoluteFilePath());
    ui->sizeLabel->setText(QString("").append(QString::number(folder.count() - 2)).append(" items"));
}

void TabModule::setLastModeDateLabel()
{
    QModelIndex lastModeIndex = currentTableView->currentIndex().siblingAtColumn(3);
    ui->lastModeDateLabel->setText(lastModeIndex.data().toString());
}

void TabModule::setLabelGridLayoutForFile()
{
    setTypeLabel();
    setSizeLabelForFile();
    setLastModeDateLabel();
}

void TabModule::setSizeLabelForFile()
{
    QModelIndex sizeIndex = currentTableView->currentIndex().siblingAtColumn(1);
    ui->sizeLabel->setText(sizeIndex.data().toString());
}

void TabModule::setClickedFilePath(const QString& clickedFilePath)
{
    this->clickedFilePath = clickedFilePath;
}

void TabModule::on_leftTableView_doubleClicked(const QModelIndex& index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    if (currentFileInfo.isDir())
    {
	openFolder(clickedFolderPath);
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

void TabModule::on_leftLineEdit_textEdited(const QString& arg1)
{
    setCurrentLineEdit((QLineEdit*)sender());
    if (currentLineEdit == ui->leftLineEdit)
    {
	setCurrenTableView(ui->leftTableView);
    }
    else if (currentLineEdit == ui->rightLineEdit)
    {
	setCurrenTableView(ui->rightTableView);
    }
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(arg1)));
    if (currentFileInfo.isDir())
    {
	selectFolder(currentFileInfo);
    }
    else if (currentFileInfo.isFile() || currentFileInfo.isSymLink())
    {
	selectFile(currentFileInfo);
    }
    setClickedFolderPath("");
    setClickedFilePath("");
}

void TabModule::selectFolder(QFileInfo& fileInfo)
{
    currentTableView->setRootIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    setLabelGridLayoutForFolder();
}

void TabModule::selectFile(QFileInfo& fileInfo)
{
    currentTableView->setRootIndex(fileSystemModel->index(fileInfo.absolutePath()));
    currentTableView->setCurrentIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    currentTableView->selectionModel()->clearSelection();
    currentTableView->selectionModel()->select(fileSystemModel->index(fileInfo.absoluteFilePath()),
					       QItemSelectionModel::Select | QItemSelectionModel::Rows);
    setLabelGridLayoutForFile();
}

void TabModule::on_searchingLineEdit_textEdited(const QString& arg1)
{
    searchingName = arg1;
}

void TabModule::on_searchingLineEdit_returnPressed()
{
    on_searchingButton_clicked();
}

void TabModule::on_searchingButton_clicked()
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

void TabModule::on_creatingButton_clicked()
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

void TabModule::on_removingButton_clicked()
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

void TabModule::on_copyingButton_clicked()
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

void TabModule::on_replacingButton_clicked()
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

void TabModule::on_renamingButton_clicked()
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

void TabModule::on_showHiddenButton_clicked()
{
    static bool showHidden = false;
    if (showHidden)
    {
	fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot);
	ui->showHiddenButton->setToolTip("Show Hidden");
	showHidden = false;
    }
    else
    {
	fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot | QDir::QDir::Hidden);
	ui->showHiddenButton->setToolTip("Don't Show Hidden");
	showHidden = true;
    }
}

void TabModule::on_sortingBox_currentIndexChanged(int index)
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

