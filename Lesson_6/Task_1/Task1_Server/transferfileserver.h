#ifndef TRANSFERFILESERVER_H
#define TRANSFERFILESERVER_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFileInfo>

class TransferFileServer : public QMainWindow
{
    Q_OBJECT

public:
    TransferFileServer(QWidget *parent = nullptr);
    ~TransferFileServer();

public slots:
    void start(QString host, int port);

private slots:
    void newClient();

private:
    void sendFile(QTcpSocket *client);
    QString getFileData();

private:

    QTcpServer *m_server = nullptr;
    QFile m_file = QFile(":/HelloWorld.txt");
};
#endif // TRANSFERFILESERVER_H
