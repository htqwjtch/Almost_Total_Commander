#include "tabmodule.h"
#include "ui_tabmodule.h"

#include <QDebug>

ll Bytes::KB = 1024;
ll Bytes::MB = 1048576;
ll Bytes::GB = 1073741824;
ll Bytes::TB = 1099511627776;

TabModule::TabModule(QWidget* parent) : QDialog(parent), ui(new Ui::TabModule)
{
    setFileSystemModel();
    setUserInterface();
    setCurrenListView(ui->leftListView);
    connectSignalsWithSlots();
    setCurrentFileInfo(QFileInfo(fileSystemModel->filePath(ui->leftListView->rootIndex())));
    setLabelGridLayoutForDirectory(currentFileInfo);
}

void TabModule::setFileSystemModel()
{
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::QDir::AllEntries);
    fileSystemModel->setRootPath("/");
}

void TabModule::setUserInterface()
{
    ui->setupUi(this);
    setListViewsModels();
    setListViewsDirectories();
    setListViewsDirectoriesAsHomeDirectories();
    setListViewsRootIndexes();
    setLineEditsTexts();
    setToolTipsForButtons();
    setButtonsStyleSheets();
}

void TabModule::setListViewsModels()
{
    ui->leftListView->setModel(fileSystemModel);
    ui->rightListView->setModel(fileSystemModel);
}

void TabModule::setListViewsDirectories()
{
    leftListViewDirectory = QDir(fileSystemModel->filePath(ui->leftListView->rootIndex()));
    rightListViewDirectory = QDir(fileSystemModel->filePath(ui->rightListView->rootIndex()));
}

void TabModule::setListViewsDirectoriesAsHomeDirectories()
{
    leftListViewDirectory.cd(leftListViewDirectory.homePath());
    rightListViewDirectory.cd(rightListViewDirectory.homePath());
}

void TabModule::setListViewsRootIndexes()
{
    ui->leftListView->setRootIndex(fileSystemModel->index(leftListViewDirectory.absolutePath()));
    ui->rightListView->setRootIndex(fileSystemModel->index(rightListViewDirectory.absolutePath()));
}

void TabModule::setLineEditsTexts()
{
    ui->leftLineEdit->setText(leftListViewDirectory.absolutePath());
    ui->rightLineEdit->setText(rightListViewDirectory.absolutePath());
    ui->searchingLineEdit->setText("Enter searching name");
}

void TabModule::setToolTipsForButtons()
{
    ui->creatingButton->setToolTip("Create");
    ui->removingButton->setToolTip("Remove");
    ui->copyingButton->setToolTip("Copy");
    ui->replacingButton->setToolTip("Replace");
    ui->renamingButton->setToolTip("Rename");
}

void TabModule::setButtonsStyleSheets()
{
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
}

void TabModule::connectSignalsWithSlots()
{
    connectListViewsSignalsWithSlots();
    connectLineEditsSignalsWithSlots();
}

void TabModule::connectListViewsSignalsWithSlots()
{
    connect(ui->rightListView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_leftListView_clicked(QModelIndex)));
    connect(ui->rightListView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(on_leftListView_doubleClicked(QModelIndex)));
}

void TabModule::connectLineEditsSignalsWithSlots()
{
    connect(ui->rightLineEdit, SIGNAL(textEdited(QString)), this, SLOT(on_leftLineEdit_textEdited(QString)));
}

void TabModule::setCurrenListView(QListView* currentListView)
{
    this->currentListView = currentListView;
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
}

void TabModule::on_leftListView_clicked(const QModelIndex& index)
{
    setCurrenListView((QListView*)sender());
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    QString directoryPath = "";
    QString filePath = "";
    if (isDot(currentFileInfo))
    {
	directoryPath = "";
	filePath = "";
	QFileInfo rootFileInfo = QFileInfo(currentFileInfo.dir().rootPath());
	setLabelGridLayoutForDirectory(rootFileInfo);
    }
    else if (isDotDot(currentFileInfo))
    {
	directoryPath = "";
	filePath = "";
	QFileInfo previousFileInfo = QFileInfo(currentFileInfo.absoluteFilePath());
	setLabelGridLayoutForDirectory(previousFileInfo);
    }
    else if (currentFileInfo.isDir())
    {
	directoryPath = currentFileInfo.absoluteFilePath();
	filePath = "";
	setLabelGridLayoutForDirectory(currentFileInfo);
    }
    else
    {
	directoryPath = "";
	filePath = currentFileInfo.absoluteFilePath();
	setLabelGridLayoutForFile(currentFileInfo);
    }
    setClickedDirectoryPath(directoryPath);
    setClickedFilePath(filePath);
}

void TabModule::setCurrentFileInfo(QFileInfo currentFileInfo)
{
    this->currentFileInfo = currentFileInfo;
}

bool TabModule::isDot(QFileInfo& fileInfo)
{
    return fileInfo.fileName() == ".";
}

bool TabModule::isDotDot(QFileInfo& fileInfo)
{
    return fileInfo.fileName() == "..";
}

void TabModule::setLabelGridLayoutForDirectory(QFileInfo& fileInfo)
{
    setLastModeDateLabel(fileInfo);
    setTypeLabelForDirectory();
    setSizeLabelForDirectory(fileInfo);
}

void TabModule::setLastModeDateLabel(QFileInfo& fileInfo)
{
    QString dateFormat = "dddd, d MMMM yy hh:mm:ss";
    ui->lastModeDateLabel->setText(fileInfo.lastModified().toString(dateFormat));
}

void TabModule::setTypeLabelForDirectory()
{
    ui->typeLabel->setText("directory");
}

void TabModule::setSizeLabelForDirectory(QFileInfo& fileInfo)
{
    QDir directory = QDir(fileInfo.absoluteFilePath());
    ui->sizeLabel->setText(QString("").append(QString::number(directory.count() - 2)).append(" items"));
}

void TabModule::setLabelGridLayoutForFile(QFileInfo& fileInfo)
{
    setLastModeDateLabel(fileInfo);
    setTypeLabelForFile(fileInfo);
    setSizeLabelForFile(fileInfo);
}

void TabModule::setTypeLabelForFile(QFileInfo& fileInfo)
{
    QString type = "";
    if (fileInfo.isSymLink())
    {
	type.append("symbolic link");
    }
    else
    {
	type.append("file");
	if (!fileInfo.suffix().isEmpty())
	{
	    type.append(" .").append(fileInfo.suffix());
	}
    }
    ui->typeLabel->setText(type);
}

void TabModule::setSizeLabelForFile(QFileInfo& fileInfo)
{
    QString size = "";
    if (fileInfo.size() < Bytes::KB)
    {
	size.append(QString::number(fileInfo.size())).append(" B");
    }
    else if (fileInfo.size() >= Bytes::KB && fileInfo.size() < Bytes::MB)
    {
	double d = fileInfo.size() / double(Bytes::KB);
	size.append(QString::number(d)).append(" KB");
    }
    else if (fileInfo.size() >= Bytes::MB && fileInfo.size() < Bytes::GB)
    {
	double d = fileInfo.size() / double(Bytes::MB);
	size.append(QString::number(d)).append(" MB");
    }
    else if (fileInfo.size() >= Bytes::GB && fileInfo.size() < Bytes::TB)
    {
	double d = fileInfo.size() / double(Bytes::GB);
	size.append(QString::number(d)).append(" GB");
    }
    else if (fileInfo.size() >= Bytes::TB)
    {
	double d = fileInfo.size() / double(Bytes::TB);
	size.append(QString::number(d)).append(" TB");
    }
    ui->sizeLabel->setText(size);
}

void TabModule::setClickedDirectoryPath(const QString& clickedDirectoryPath)
{
    this->clickedDirectoryPath = clickedDirectoryPath;
}

void TabModule::setClickedFilePath(const QString& clickedFilePath)
{
    this->clickedFilePath = clickedFilePath;
}

void TabModule::on_leftListView_doubleClicked(const QModelIndex& index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    if (currentFileInfo.isDir())
    {
	if (isDot(currentFileInfo))
	{
	    openDot();
	    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index("/")));
	}
	else if (isDotDot(currentFileInfo))
	{
	    setClickedDirectoryPath(currentFileInfo.dir().absolutePath());
	    openDotDot();
	}
	else
	{
	    openDirectory(clickedDirectoryPath);
	}

	if (currentListView == ui->leftListView)
	{
	    setCurrentLineEdit(ui->leftLineEdit);
	}
	else if (currentListView == ui->rightListView)
	{
	    setCurrentLineEdit(ui->rightLineEdit);
	}
	currentLineEdit->setText(currentFileInfo.absoluteFilePath());
    }
    else
    {
	openFile();
    }
    setClickedFilePath("");
    setClickedDirectoryPath("");
}

void TabModule::openFile()
{
    QDesktopServices::openUrl(QUrl::fromUserInput(clickedFilePath));
}

void TabModule::openDot()
{
    openDirectory("/");
}

void TabModule::openDirectory(const QString& directoryPath)
{
    currentListView->setRootIndex(fileSystemModel->index(directoryPath));
}

void TabModule::openDotDot()
{
    QDir clickedDirectory = QDir(clickedDirectoryPath);
    clickedDirectory.cdUp();
    openDirectory(clickedDirectory.absolutePath());
}

void TabModule::setCurrentLineEdit(QLineEdit* currentLineEdit)
{
    this->currentLineEdit = currentLineEdit;
}

void TabModule::on_leftLineEdit_textEdited(const QString& arg1)
{
    setCurrentLineEdit((QLineEdit*)sender());
    if (currentLineEdit == ui->leftLineEdit)
    {
	setCurrenListView(ui->leftListView);
    }
    else if (currentLineEdit == ui->rightLineEdit)
    {
	setCurrenListView(ui->rightListView);
    }
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(arg1)));
    if (currentFileInfo.isDir())
    {
	selectDirectory(currentFileInfo);
    }
    else if (currentFileInfo.isFile() || currentFileInfo.isSymLink())
    {
	selectFile(currentFileInfo);
    }
}

void TabModule::selectFile(QFileInfo& fileInfo)
{
    currentListView->setRootIndex(fileSystemModel->index(fileInfo.absolutePath()));
    currentListView->setCurrentIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    currentListView->selectionModel()->select(fileSystemModel->index(fileInfo.absoluteFilePath()),
					      QItemSelectionModel::Select | QItemSelectionModel::Rows);
    on_leftListView_clicked(fileSystemModel->index(fileInfo.absoluteFilePath()));
}

void TabModule::selectDirectory(QFileInfo& fileInfo)
{
    currentListView->setRootIndex(fileSystemModel->index(fileInfo.absoluteFilePath()));
    setLabelGridLayoutForDirectory(fileInfo);
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
	setListViewsDirectories();
	checkCurrentDirectory();
	ui->searchingButton->setEnabled(false);
	setSearchingModule();
	searchingModule->search(searchingName, currentDirectory.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
}

void TabModule::checkCurrentDirectory()
{
    if (currentListView == ui->leftListView)
    {
	setCurrentDirectory(leftListViewDirectory);
    }
    if (currentListView == ui->rightListView)
    {
	setCurrentDirectory(rightListViewDirectory);
    }
    if (!currentDirectory.absolutePath().contains(currentDirectory.homePath()))
    {
	throw ExceptionService("There is no access to perform any operation in this directory!");
    }
}

void TabModule::setCurrentDirectory(QDir& currentDirectory)
{
    this->currentDirectory = currentDirectory;
}

void TabModule::setSearchingModule()
{
    searchingModule = new SearchingModule(this);
    QObject::connect(searchingModule, SIGNAL(searchingCompletedSignal()), this, SLOT(searchingCompleted()));
}

void TabModule::on_creatingButton_clicked()
{
    try
    {
	setListViewsDirectories();
	checkCurrentDirectory();
	CreatingModule creatingModule = CreatingModule(currentDirectory, this);
	creatingModule.exec();
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedDirectoryPath("");
    setClickedFilePath("");
}

void TabModule::on_removingButton_clicked()
{
    try
    {
	setListViewsDirectories();
	checkCurrentDirectory();
	if (!clickedDirectoryPath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedDirectoryPath);
	}
	else if (!clickedFilePath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedFilePath);
	}
	else
	{
	    throw ExceptionService("You was not choose a file or a directory!");
	}
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
    setClickedDirectoryPath("");
    setClickedFilePath("");
}

void TabModule::setRemovingModule()
{
    removingModule = new RemovingModule(this);
    QObject::connect(removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule, SIGNAL(removingFailedSignal(QString)), this, SLOT(removingFailed(const QString&)));
}

void TabModule::on_copyingButton_clicked()
{
    try
    {
	setListViewsDirectories();
	if (!leftListViewDirectory.absolutePath().contains(leftListViewDirectory.homePath())
	    || !rightListViewDirectory.absolutePath().contains(rightListViewDirectory.homePath()))
	{
	    throw ExceptionService("There is no access to perform any operation in this directory!");
	}
	if (!clickedFilePath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedFilePath);
	}
	else if (!clickedDirectoryPath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedDirectoryPath);
	}
	else
	{
	    throw ExceptionService("You was not choose a file or a directory!");
	}
	ui->copyingButton->setEnabled(false);
	setCopyingModule();
	copyingModule->copy(currentFileInfo.absoluteFilePath(), rightListViewDirectory.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedDirectoryPath("");
    setClickedFilePath("");
}

void TabModule::setCopyingModule()
{
    copyingModule = new CopyingModule(this);
    QObject::connect(copyingModule, SIGNAL(copyingCompletedSignal()), this, SLOT(copyingCompleted()));
    QObject::connect(copyingModule, SIGNAL(copyingFailedSignal(QString)), this, SLOT(copyingFailed(const QString&)));
}

void TabModule::on_replacingButton_clicked()
{
    try
    {
	setListViewsDirectories();
	if (!leftListViewDirectory.absolutePath().contains(leftListViewDirectory.homePath())
	    || !rightListViewDirectory.absolutePath().contains(rightListViewDirectory.homePath()))
	{
	    throw ExceptionService("There is no access to perform any operation in this directory!");
	}
	if (!clickedFilePath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedFilePath);
	}
	else if (!clickedDirectoryPath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedDirectoryPath);
	}
	else
	{
	    throw ExceptionService("You was not choose a file or a directory!");
	}
	ui->replacingButton->setEnabled(false);
	setReplacingModule();
	replacingModule->replace(currentFileInfo.absoluteFilePath(), rightListViewDirectory.absolutePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedDirectoryPath("");
    setClickedFilePath("");
}

void TabModule::setReplacingModule()
{
    replacingModule = new ReplacingModule(this);
    QObject::connect(replacingModule, SIGNAL(replacingCompletedSignal()), this, SLOT(replacingCompleted()));
    QObject::connect(replacingModule, SIGNAL(replacingFailedSignal(QString)), this, SLOT(replacingFailed(const QString&)));
}

void TabModule::on_renamingButton_clicked()
{
    try
    {
	setListViewsDirectories();
	checkCurrentDirectory();
	if (!clickedDirectoryPath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedDirectoryPath);
	}
	else if (!clickedFilePath.isEmpty())
	{
	    currentFileInfo = QFileInfo(clickedFilePath);
	}
	else
	{
	    throw ExceptionService("You was not choose a file or a directory!");
	}
	NamingModule namingModule;
	namingModule.setCurrentDirectory(currentDirectory);
	namingModule.rename(currentFileInfo.absoluteFilePath());
    }
    catch (ExceptionService exceptionService)
    {
	QMessageBox::warning(this, "", exceptionService.getInfo());
    }
    setClickedDirectoryPath("");
    setClickedFilePath("");
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

void TabModule::searchingCompleted()
{
    ui->searchingButton->setEnabled(true);
    searchingModule->exec();
    delete searchingModule;
}
