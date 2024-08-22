#ifndef NAVIGATIONBARMODULE_H
#define NAVIGATIONBARMODULE_H

#include <QLineEdit>
#include <QWidget>

namespace Ui
{
    class NavigationBarModule;
}

class NavigationBarModule : public QWidget
{
    Q_OBJECT

public:
    explicit NavigationBarModule(QWidget* parent = nullptr);
    ~NavigationBarModule();

private:
    void setCurrentLineEdit(QLineEdit*);

private slots:
    void on_leftParentButton_clicked();
    void on_rightParentButton_clicked();
    void on_leftLineEdit_textEdited(const QString& arg1);

private:
    Ui::NavigationBarModule* ui;

    QLineEdit* currentLineEdit;
};

#endif // NAVIGATIONBARMODULE_H
