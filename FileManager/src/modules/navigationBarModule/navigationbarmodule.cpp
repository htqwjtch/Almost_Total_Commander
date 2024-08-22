#include "navigationbarmodule.h"
#include "ui_navigationbarmodule.h"

NavigationBarModule::NavigationBarModule(QWidget* parent) : QWidget(parent), ui(new Ui::NavigationBarModule)
{
    ui->setupUi(this);

    ui->leftLineEdit->setText(leftTableViewFolder.absolutePath());
    ui->rightLineEdit->setText(rightTableViewFolder.absolutePath());

    connect(ui->rightLineEdit, SIGNAL(textEdited(QString)), this, SLOT(on_leftLineEdit_textEdited(QString)));
}

NavigationBarModule::~NavigationBarModule()
{
    delete ui;
}

void NavigationBarModule::on_leftParentButton_clicked()
{
    setTableViewsDirectories();
    setCurrenTableView(ui->leftTableView);
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(leftTableViewFolder.absolutePath())));
    setClickedFolderPath(currentFileInfo.absoluteFilePath());

    QDir clickedFolder = QDir(clickedFolderPath);
    clickedFolder.cdUp();
    currentTableView->setRootIndex(fileSystemModel->index(clickedFolder.absolutePath()));

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

void NavigationBarModule::setCurrentLineEdit(QLineEdit* currentLineEdit)
{
    this->currentLineEdit = currentLineEdit;
}

void NavigationBarModule::on_rightParentButton_clicked()
{
    setTableViewsDirectories();
    setCurrenTableView(ui->rightTableView);
    setCurrentFileInfo(fileSystemModel->fileInfo(fileSystemModel->index(rightTableViewFolder.absolutePath())));
    setClickedFolderPath(currentFileInfo.absoluteFilePath());

    QDir clickedFolder = QDir(clickedFolderPath);
    clickedFolder.cdUp();
    currentTableView->setRootIndex(fileSystemModel->index(clickedFolder.absolutePath()));

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

void NavigationBarModule::on_leftLineEdit_textEdited(const QString& arg1)
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
