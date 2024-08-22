#ifndef SEARCHINGBARMODULE_H
#define SEARCHINGBARMODULE_H

#include "../../services/exceptionService/exceptionservice.h"
#include "../searchingModule/searchingmodule.h"

#include <QMessageBox>
#include <QWidget>

namespace Ui
{
    class SearchingBarModule;
}

class SearchingBarModule : public QWidget
{
    Q_OBJECT

public:
    explicit SearchingBarModule(QWidget* parent = nullptr);
    ~SearchingBarModule();

private slots:
    void on_searchingLineEdit_textEdited(const QString& arg1);
    void on_searchingLineEdit_returnPressed();
    void on_searchingButton_clicked();

private:
    Ui::SearchingBarModule* ui;

    QString searchingName = "";

    SearchingModule* searchingModule;
};

#endif // SEARCHINGBARMODULE_H
