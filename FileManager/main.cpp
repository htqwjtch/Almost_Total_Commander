#include "src/modules/mainModule/mainmodule.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    MainModule mainModule;
    mainModule.show();
    return a.exec();
}
