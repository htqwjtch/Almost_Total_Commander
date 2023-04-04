#ifndef LINKELEMENTWINDOW_H
#define LINKELEMENTWINDOW_H

#include <QDialog>

namespace Ui {
class LinkElementWindow;
}

class LinkElementWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LinkElementWindow(QWidget *parent = nullptr);
    ~LinkElementWindow();
    QString GetPath();

private slots:
    void on_btnOK_clicked();

    void on_btnCancel_clicked();

    void on_path_textEdited(const QString &arg1);

private:
    Ui::LinkElementWindow *ui;
    QString path="";    //переменная для хранения нового имени выбранного файла
};

#endif // LINKELEMENTWINDOW_H
