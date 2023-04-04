#ifndef CONFIRMDELETE_H
#define CONFIRMDELETE_H

#include <QDialog>

namespace Ui {
class ConfirmDelete;
}

class ConfirmDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDelete(QWidget *parent = nullptr);
    ~ConfirmDelete();
    void SetConfirm(bool);  // метод установки подтверждения удаления
    bool Confirm(); //метод срабатывания подтверждения удаления

private slots:
    void on_btnOK_clicked();     // слот нажатия на "OK"

    void on_btnCancel_clicked();    // слот нажатия на "Cancel"

private:
    Ui::ConfirmDelete *ui;
    bool confirm=false; //флаг установки подтверждения
};

#endif // CONFIRMDELETE_H
