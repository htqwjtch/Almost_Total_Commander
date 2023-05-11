#ifndef NEWNAME_H
#define NEWNAME_H

#include <QDialog>

namespace Ui
{
    class NewName;
}

class NewName : public QDialog
{
    Q_OBJECT

    Ui::NewName* ui;
    QString name = ""; // переменная для хранения нового имени выбранного файла

private slots:
    void on_name_textEdited(const QString& arg1);

    void on_btnCancel_clicked();

    void on_btnOK_clicked();

public:
    explicit NewName(QWidget* parent = nullptr);
    ~NewName();
    QString get_name(); // метод передачи имени
};

#endif // NEWNAME_H
