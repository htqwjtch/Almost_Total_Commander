#include "creatingmodule.h"
#include "ui_creatingmodule.h"

CreatingModule::CreatingModule(QDir &currentFolder, QWidget *parent) :
    QDialog(parent), ui(new Ui::CreatingModule)
{
    setUserInterface();
    creatingService = new CreatingService(currentFolder);
    QObject::connect(creatingService,
        SIGNAL(creatingFinishedSignal(QString)),
        this,
        SLOT(creatingFinished(const QString &)));
}

void CreatingModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Creating");
    setButtonsStyleSheets();
}

void CreatingModule::setButtonsStyleSheets()
{
    ui->fileCreationButton->setStyleSheet("QPushButton {"
                                          "    border: none;"
                                          "}"
                                          "QPushButton:hover {"
                                          "    border: 1px ridge grey;"
                                          "}");
    ui->folderCreationButton->setStyleSheet("QPushButton {"
                                            "    border: none;"
                                            "}"
                                            "QPushButton:hover {"
                                            "    border: 1px ridge grey;"
                                            "}");
    ui->symbolLinkCreationButton->setStyleSheet("QPushButton {"
                                                "    border: none;"
                                                "}"
                                                "QPushButton:hover {"
                                                "    border: 1px ridge grey;"
                                                "}");
}

CreatingModule::~CreatingModule()
{
    delete creatingService;
    delete ui;
}

void CreatingModule::on_fileCreationButton_clicked()
{
    try
    {
        creatingService->createFile();
    }
    catch (ExceptionService exceptionService)
    {
        QMessageBox::warning(this, " ", exceptionService.getInfo());
    }
}

void CreatingModule::on_folderCreationButton_clicked()
{
    try
    {
        creatingService->createFolder();
    }
    catch (ExceptionService exceptionService)
    {
        QMessageBox::warning(this, " ", exceptionService.getInfo());
    }
}

void CreatingModule::on_symbolLinkCreationButton_clicked()
{
    try
    {
        creatingService->createSymbolLink();
    }
    catch (ExceptionService exceptionService)
    {
        QMessageBox::warning(this, " ", exceptionService.getInfo());
    }
}

void CreatingModule::on_cancelButton_clicked() { accept(); }

void CreatingModule::creatingFinished(const QString &createdObjectPath)
{
    emit creatingCompletedSignal(createdObjectPath);
}
