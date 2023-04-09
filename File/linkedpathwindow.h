#ifndef LINKEDPATHWINDOW_H
#define LINKEDPATHWINDOW_H

#include <QDialog>

namespace Ui
{
class LinkedPathWindow;
}

class LinkedPathWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LinkedPathWindow(QWidget* parent = nullptr);
    ~LinkedPathWindow();
    QString getPath(); // метод передачи имени

private slots:
    void on_btnCancel_clicked();

    void on_btnOK_clicked();

    void on_path_textEdited(const QString& arg1);

private:
    Ui::LinkedPathWindow* ui;
    QString path = ""; // переменная для хранения нового имени выбранного файла
};

#endif // LINKEDPATHWINDOW_H
