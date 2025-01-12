#include "trashmodule.h"
#include "ui_trashmodule.h"

#include <QMap>

TrashModule::TrashModule(QWidget *parent) : QDialog(parent), ui(new Ui::TrashModule)
{
    setFileSystemModel();
    setUserInterFace();
}

void TrashModule::setFileSystemModel()
{
    fileSystemModel = new QFileSystemModel(this);
    fileSystemModel->setFilter(QDir::QDir::AllEntries | QDir::QDir::NoDotAndDotDot);
    fileSystemModel->setRootPath(rootPath);
}

void TrashModule::setUserInterFace()
{
    ui->setupUi(this);
    setWindowTitle("Trash");
    setTableView();
    ui->tableView->setRootIndex(fileSystemModel->index(rootPath));
    setToolTips();
    // setButtonStyleSheets();
}

void TrashModule::setTableView()
{
    ui->tableView->setModel(fileSystemModel);

    ui->tableView->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->tableView->setShowGrid(false);

    ui->tableView->verticalHeader()->hide();
    ui->tableView->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    ui->tableView->setSortingEnabled(true);
}

void TrashModule::setToolTips()
{
    ui->restoringButton->setToolTip("Restore");
    ui->removingButton->setToolTip("Remove");
}

void TrashModule::setButtonStyleSheets()
{
    ui->restoringButton->setStyleSheet("QPushButton {"
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
}

TrashModule::~TrashModule()
{
    delete fileSystemModel;
    delete ui;
}

bool TrashModule::checkTrash() { return QDir(rootPath).exists(); }

void TrashModule::moveToTrash(const QStringList &removingObjectPathes)
{
    foreach (QString removingObjectPath, removingObjectPathes)
    {
        if (!QFile::moveToTrash(removingObjectPath))
        {
            emit removingFailedSignal("Removing failed!");
        }
    }
    emit removingCompletedSignal();
}

void TrashModule::removePermanently(const QStringList &removingObjectPathes)
{
    setRemovingModule();
    removingModule->remove(removingObjectPathes);
}

void TrashModule::setRemovingModule()
{
    removingModule = new RemovingModule(this);
    QObject::connect(
        removingModule, SIGNAL(removingCompletedSignal()), this, SLOT(removingCompleted()));
    QObject::connect(removingModule,
        SIGNAL(removingFailedSignal(QString)),
        this,
        SLOT(removingFailed(const QString &)));
}

void TrashModule::removingFailed(const QString &exceptionInfo)
{
    ui->removingButton->setEnabled(true);
    delete removingModule;
    emit removingFailedSignal(exceptionInfo);
}

void TrashModule::removingCompleted()
{
    ui->removingButton->setEnabled(true);
    delete removingModule;
    emit removingCompletedSignal();
}

void TrashModule::on_restoringButton_clicked()
{
    try
    {
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();

        if (selectedIndexes.isEmpty())
        {
            throw ExceptionService("You was not choose a file or a folder!");
        }

        QMap<int32_t, QString> selectedRowsObjectNames;
        for (const QModelIndex &index : selectedIndexes)
        {
            QFileInfo fileInfo = fileSystemModel->fileInfo(index);
            if (index.column() == 0)
            {
                selectedRowsObjectNames.insert(index.row(), fileSystemModel->fileName(index));
            }
        }
        QStringList selectedObjectNames = selectedRowsObjectNames.values();

        ui->restoringButton->setEnabled(false);
        restore(selectedObjectNames);
    }
    catch (ExceptionService exceptionService)
    {
        QMessageBox::warning(this, " ", exceptionService.getInfo());
    }
    ui->restoringButton->setEnabled(true);
    ui->tableView->selectionModel()->clear();
}

void TrashModule::restore(const QStringList &restoringObjectNames)
{
    QDir trashDir(QDir::homePath() + "/.local/share/Trash");
    QDir filesDir(trashDir.filePath("files"));
    QDir infoDir(trashDir.filePath("info"));

    foreach (QString restoringObjectName, restoringObjectNames)
    {
        QString trashFilePath = filesDir.filePath(restoringObjectName);
        QString infoFilePath = infoDir.filePath(restoringObjectName + ".trashinfo");

        if (!QFile::exists(trashFilePath) || !QFile::exists(infoFilePath))
        {
            throw ExceptionService("File or metadata not found in Trash.");
        }

        QFile infoFile(infoFilePath);
        if (!infoFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            throw ExceptionService("Failed to open .trashinfo file.");
        }

        QString originalPath;
        QTextStream stream(&infoFile);
        while (!stream.atEnd())
        {
            QString line = stream.readLine();
            if (line.startsWith("Path="))
            {
                originalPath = line.mid(5); // Delete "Path=".
                break;
            }
        }
        infoFile.close();

        if (originalPath.isEmpty())
        {
            throw ExceptionService("Original path not found in .trashinfo.");
        }

        QFileInfo originalFileInfo(originalPath);
        QDir targetDir = originalFileInfo.absoluteDir();
        if (!targetDir.exists())
        {
            throw ExceptionService("Target directory does not exist.");
        }

        if (QFile::rename(trashFilePath, originalPath))
        {
            if (!QFile::remove(infoFilePath))
            {
                throw ExceptionService("Removing failed!");
            }
        }
        else
        {
            throw ExceptionService("Failed to restore file.");
        }
    }
}

void TrashModule::on_removingButton_clicked()
{
    try
    {
        QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();

        if (selectedIndexes.isEmpty())
        {
            throw ExceptionService("You was not choose a file or a folder!");
        }

        QMap<int32_t, QString> selectedRowsObjectPathes;
        for (const QModelIndex &index : selectedIndexes)
        {
            QFileInfo fileInfo = fileSystemModel->fileInfo(index);
            if (index.column() == 0)
            {
                selectedRowsObjectPathes.insert(index.row(), fileSystemModel->filePath(index));
            }
        }
        QStringList selectedObjectPathes = selectedRowsObjectPathes.values();

        ui->removingButton->setEnabled(false);
        QMessageBox::StandardButton answerButton = QMessageBox::question(this,
            " ",
            "Do you want to perform removing permanently?",
            QMessageBox::Cancel | QMessageBox::Ok);
        if (answerButton == QMessageBox::Ok)
        {
            QStringList selectedObjectTrashInfoPathes = QStringList();
            foreach (QString selectedObjectPath, selectedObjectPathes)
            {
                QFileInfo fileInfo(selectedObjectPath);
                QString selectedObjectTrashInfoPath = QDir::homePath() +
                    "/.local/share/Trash/info/" + fileInfo.fileName() + ".trashinfo";
                selectedObjectTrashInfoPathes.append(selectedObjectTrashInfoPath);
            }
            removePermanently(selectedObjectTrashInfoPathes);
            removePermanently(selectedObjectPathes);
        }
        else
        {
            ui->removingButton->setEnabled(true);
        }
    }
    catch (ExceptionService exceptionService)
    {
        QMessageBox::warning(this, " ", exceptionService.getInfo());
    }
    ui->tableView->selectionModel()->clear();
}

void TrashModule::on_tableView_clicked(const QModelIndex &index)
{
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    QString folderPath = "";
    QString filePath = "";
    if (currentFileInfo.isDir())
    {
        folderPath = currentFileInfo.absoluteFilePath();
        filePath = "";
    }
    else
    {
        folderPath = "";
        filePath = currentFileInfo.absoluteFilePath();
    }
}

void TrashModule::setCurrentFileInfo(QFileInfo currentFileInfo)
{
    this->currentFileInfo = currentFileInfo;
}

void TrashModule::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->tableView->selectionModel()->clear();
    setCurrentFileInfo(fileSystemModel->fileInfo(index));
    if (currentFileInfo.isDir())
    {
        ui->tableView->setRootIndex(fileSystemModel->index(currentFileInfo.absoluteFilePath()));
    }
    else
    {
        QDesktopServices::openUrl(QUrl::fromUserInput(currentFileInfo.absoluteFilePath()));
    }
}

void TrashModule::on_aboveButton_clicked()
{
    ui->tableView->selectionModel()->clear();
    if (fileSystemModel->filePath(ui->tableView->rootIndex()) != rootPath)
    {
        QDir currentDir = QDir(fileSystemModel->filePath(ui->tableView->rootIndex()));
        currentDir.cdUp();
        ui->tableView->setRootIndex(fileSystemModel->index(currentDir.absolutePath()));
    }
}
