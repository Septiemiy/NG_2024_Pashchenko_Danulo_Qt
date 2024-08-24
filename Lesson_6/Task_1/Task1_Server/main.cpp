#include "transferfileserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TransferFileServer server;
    server.start("127.0.0.1", 8080);
    return a.exec();
}
