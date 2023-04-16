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
    void chooseFile(bool); // метод установки создания файла
    void chooseDir(bool);  // метод установки создания директории
    void chooseLink(bool);
    bool getFile(); // метод, сообщающий о выборе создании файла
    bool getDir();  // метод, сообщающий о выборе создания директории
    bool getLink();

private slots:
    void on_btnFile_clicked();

    void on_btnDir_clicked();

    void on_btnLink_clicked();

    void on_btnCancel_clicked();

private:
    Ui::CreateChoice* ui;
    QString fileName = ""; // переменная для хранения имени созданного файла
    QString dirName = "";  // переменная для хранения имени созданной директории
    QString linkName = "";
    bool file = 0; // флаг выбора файла
    bool dir = 0;  // флаг выбора директории
    bool link = 0;
};
#endif // CREATECHOICE_H
