#include "infobarmodule.h"
#include "ui_infobarmodule.h"

InfoBarModule::InfoBarModule(QWidget* parent) : QWidget(parent), ui(new Ui::InfoBarModule)
{
    ui->setupUi(this);
}

InfoBarModule::~InfoBarModule()
{
    delete ui;
}

void InfoBarModule::setInfoBarForFolder()
{
    setTypeLabel();
    setSizeLabelForFolder();
    setLastModeDateLabel();
}

void InfoBarModule::setTypeLabel()
{
    QModelIndex typeIndex = currentTableView->currentIndex().siblingAtColumn(2);
    ui->typeLabel->setText(typeIndex.data().toString());
}

void InfoBarModule::setSizeLabelForFolder()
{
    QDir folder = QDir(currentFileInfo.absoluteFilePath());
    ui->sizeLabel->setText(QString("").append(QString::number(folder.count() - 2)).append(" items"));
}

void InfoBarModule::setLastModeDateLabel()
{
    QModelIndex lastModeIndex = currentTableView->currentIndex().siblingAtColumn(3);
    ui->lastModeDateLabel->setText(lastModeIndex.data().toString());
}

void InfoBarModule::setInfoBarForFile()
{
    setTypeLabel();
    setSizeLabelForFile();
    setLastModeDateLabel();
}

void InfoBarModule::setSizeLabelForFile()
{
    QModelIndex sizeIndex = currentTableView->currentIndex().siblingAtColumn(1);
    ui->sizeLabel->setText(sizeIndex.data().toString());
}
