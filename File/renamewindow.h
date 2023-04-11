#ifndef RENAMEWINDOW_H
#define RENAMEWINDOW_H

#include <QDialog>

namespace Ui
{
    class RenameWindow;
}

class RenameWindow : public QDialog // класс переименования объекта
{
    Q_OBJECT

    Ui::RenameWindow* ui; // указатель на объект соотв типа в классе основной формы
    QString name = "";    // переменная для хранения нового имени выбранного файла

private slots:
    void on_btnOK_clicked(); // слот нажатия на "OK"

    void on_btnCancel_clicked(); // слот нажатия на "Cancel"

    void on_name_textEdited(const QString& arg1); // слот получения имени объекта

public:
    explicit RenameWindow(QWidget* parent = nullptr);
    ~RenameWindow();
    QString getName(); // метод передачи имени
};

#endif // RENAMEWINDOW_H
