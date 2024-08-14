#include "searchingmodule.h"
#include "ui_searchingmodule.h"

SearchingModule::SearchingModule(QWidget* parent) : QDialog(parent), ui(new Ui::SearchingModule)
{
    setUserInterface();

    threadForSearching = new QThread(this);
    searchingService = new SearchingService();

    QObject::connect(this, SIGNAL(destroyed()), threadForSearching, SLOT(quit()));
    QObject::connect(this, SIGNAL(startSearching(QString, QString)), searchingService, SLOT(startSearching(const QString&, const QString&)));
    QObject::connect(searchingService, SIGNAL(searchingFinished(QStringList)), this, SLOT(fillSearchingResultWidget(QStringList)));

    searchingService->moveToThread(threadForSearching);
    threadForSearching->start();
}

void SearchingModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Searching");
}

SearchingModule::~SearchingModule()
{
    delete ui;
    emit threadForSearching->quit();
    threadForSearching->wait();
    delete threadForSearching;
    delete searchingService;
}

void SearchingModule::search()
{
    emit startSearching(currentDirectoryPath, searchingName);
}

void SearchingModule::setCurrentDirectoryPath(const QString& currentDirectoryPath)
{
    this->currentDirectoryPath = currentDirectoryPath;
}

void SearchingModule::setSearchingName(const QString& searchingName)
{
    this->searchingName = searchingName;
}

void SearchingModule::fillSearchingResultWidget(QStringList searchingResult)
{
    if (searchingResult.isEmpty())
    {
	ui->searchingResultWidget->addItem("No matches found");
    }
    else
    {
	ui->searchingResultWidget->addItems(searchingResult);
    }
    emit searchingFinished();
}

void SearchingModule::on_searchingResultWidget_itemClicked(QListWidgetItem* item)
{
    QClipboard* pcb = QApplication::clipboard(); //создание объекта для взаимодействия с буфером обмена
    pcb->setText(item->text(), QClipboard::Clipboard); //копирование выбранного текста в буфер обмена
}

void SearchingModule::on_okButton_clicked()
{
    clearSearchingResultWidget();
    accept();
}

void SearchingModule::clearSearchingResultWidget()
{
    ui->searchingResultWidget->clear();
}
