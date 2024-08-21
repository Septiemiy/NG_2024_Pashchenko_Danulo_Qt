#include "censorship.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Censorship w;
    w.show();
    return a.exec();
}
