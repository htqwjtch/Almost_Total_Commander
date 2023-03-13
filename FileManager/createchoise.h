#ifndef CREATECHOISE_H
#define CREATECHOISE_H

#include <QDialog>

namespace Ui {
class CreateChoise;
}

class CreateChoise : public QDialog //класс для выбора создаваемого объекта
{
    Q_OBJECT

public:
    explicit CreateChoise(QWidget *parent = nullptr);
    ~CreateChoise();
    void ChooseFile(bool);  //метод установки создания файла
    void ChooseFolder(bool);    //метод установки создания директории
    bool GetFile(); //метод, сообщающий о выборе создании файла
    bool GetFolder();   //метод, сообщающий о выборе создания директории
private slots:
    void on_btnFile_clicked();  // слот выбора о создании файла

    void on_btnFolder_clicked();    // слот выбора о создании директории

    void on_btnCancel_clicked();    // слот нажатия на "Cancel"

private:
    Ui::CreateChoise *ui;   //указатель для связи с соответствующим ui-файлом
    QString fileName="";    //переменная для хранения имени созданного файла
    QString folderName="";  //переменная для хранения имени созданной директории
    bool file=0;    //флаг выбора файла
    bool folder=0;  //флаг выбора директории
};

#endif // CREATECHOISE_H
