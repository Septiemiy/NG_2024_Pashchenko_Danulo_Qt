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
    void leftClient();
    void sendToAll(QByteArray message);
    void messageFromClient();

private:

    QTcpServer *m_server = nullptr;
    QVector<QTcpSocket *> m_clients;
};
#endif // TRANSFERFILESERVER_H
