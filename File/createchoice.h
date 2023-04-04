#ifndef CREATECHOICE_H
#define CREATECHOICE_H

#include <QDialog>

namespace Ui {
class CreateChoice;
}

class CreateChoice : public QDialog
{
    Q_OBJECT

public:
    explicit CreateChoice(QWidget *parent = nullptr);
    ~CreateChoice();
    void ChooseFile(bool);  //метод установки создания файла
    void ChooseDir(bool);    //метод установки создания директории
    void ChooseLink(bool);
    bool GetFile(); //метод, сообщающий о выборе создании файла
    bool GetDir();   //метод, сообщающий о выборе создания директории
    bool GetLink();
private slots:
    void on_btnFile_clicked();

    void on_btnDir_clicked();

    void on_btnLink_clicked();

private:
    Ui::CreateChoice *ui;
    QString fileName="";    //переменная для хранения имени созданного файла
    QString dirName="";  //переменная для хранения имени созданной директории
    QString linkName="";
    bool file=0;    //флаг выбора файла
    bool dir=0;  //флаг выбора директории
    bool link=0;
};

#endif // CREATECHOICE_H
