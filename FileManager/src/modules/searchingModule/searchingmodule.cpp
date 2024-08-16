#include "searchingmodule.h"
#include "ui_searchingmodule.h"

SearchingModule::SearchingModule(QWidget* parent) : QDialog(parent), ui(new Ui::SearchingModule)
{
    setUserInterface();
    allocateMemory();
    connectSignalsWithSlots();
    setThreadForSearching();
}

void SearchingModule::setUserInterface()
{
    ui->setupUi(this);
    setWindowTitle("Searching");
}

void SearchingModule::allocateMemory()
{
    searchingService = new SearchingService();
    threadForSearching = new QThread(this);
}

void SearchingModule::connectSignalsWithSlots()
{
    QObject::connect(this, SIGNAL(destroyed()), threadForSearching, SLOT(quit()));
    QObject::connect(this, SIGNAL(startSearchingSignal(QString, QString)), searchingService, SLOT(startSearching(const QString&, const QString&)));
    QObject::connect(searchingService, SIGNAL(searchingIsPerformedSignal(QStringList)), this, SLOT(fillSearchingResultWidget(QStringList)));
}

void SearchingModule::setThreadForSearching()
{
    searchingService->moveToThread(threadForSearching);
    threadForSearching->start();
}

SearchingModule::~SearchingModule()
{
    emit threadForSearching->quit();
    threadForSearching->wait();
    delete threadForSearching;
    delete searchingService;
    delete ui;
}

void SearchingModule::search(const QString& searchingName, const QString& currentDirectoryPath)
{
    emit startSearchingSignal(searchingName, currentDirectoryPath);
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
    emit searchingIsPerformedSignal();
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
