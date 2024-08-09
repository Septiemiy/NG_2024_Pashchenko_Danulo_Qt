#include "carcatalog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarCatalog w;
    w.show();
    return a.exec();
}
