#ifndef LINKEDPATH_H
#define LINKEDPATH_H

#include <QDialog>

namespace Ui
{
    class LinkedPath;
}

class LinkedPath : public QDialog
{
    Q_OBJECT;

public:
    explicit LinkedPath(QWidget* parent = nullptr);
    ~LinkedPath();
    QString get_path(); // метод передачи имени

private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

    void on_path_textEdited(const QString& arg1);

private:
    Ui::LinkedPath* ui;
    QString path = ""; // переменная для хранения нового имени выбранного файла
};

#endif // LINKEDPATH_H
