#include <QApplication>

#include "modules/mainModule/mainmodule.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainModule mainModule;
    mainModule.show();
    return a.exec();
}
