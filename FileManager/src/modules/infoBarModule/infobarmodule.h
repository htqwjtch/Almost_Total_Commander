#ifndef INFOBARMODULE_H
#define INFOBARMODULE_H

#include <QWidget>

namespace Ui
{
    class InfoBarModule;
}

class InfoBarModule : public QWidget
{
    Q_OBJECT

public:
    explicit InfoBarModule(QWidget* parent = nullptr);
    ~InfoBarModule();

private:
    void setInfoBarForFolder();
    void setTypeLabel();
    void setSizeLabelForFolder();
    void setLastModeDateLabel();
    void setInfoBarForFile();
    void setSizeLabelForFile();

private:
    Ui::InfoBarModule* ui;
};

#endif // INFOBARMODULE_H
