#ifndef CREATECHOICE_H
#define CREATECHOICE_H

#include <QDialog>

namespace Ui
{
    class CreateChoice;
}

class CreateChoice : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChoice(QWidget* parent = nullptr);
    ~CreateChoice();
    bool get_file(); // метод, сообщающий о создании файла
    bool get_dir();  // директории
    bool get_link(); // символьной ссылки

private slots:
    void on_btnFile_clicked();

    void on_btnDir_clicked();

    void on_btnLink_clicked();

    void on_btnCancel_clicked();

private:
    Ui::CreateChoice* ui;
    QString fileName = ""; // переменная для хранения имени файла
    QString dirName = "";  // директории
    QString linkName = ""; // символьной ссылки
    bool file = 0;         // флаг выбора файла
    bool dir = 0;          // директории
    bool link = 0;         // символьной ссылки
};
#endif // CREATECHOICE_H
