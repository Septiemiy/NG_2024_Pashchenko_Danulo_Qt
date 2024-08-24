#include "transferfileserver.h"

TransferFileServer::TransferFileServer(QWidget *parent)
    : QMainWindow(parent)
{
    m_server = new QTcpServer();

    connect(m_server, &QTcpServer::newConnection, this, &TransferFileServer::newClient);
}

TransferFileServer::~TransferFileServer()
{
    if(m_server->isListening())
    {
        m_server->close();
    }
    delete m_server;
}

void TransferFileServer::start(QString host, int port)
{
    bool online = m_server->listen(QHostAddress(host), port);
    if(online == true)
    {
        qDebug() << "Server online";
    }
    else
    {
        qDebug() << "Error starting server: " << m_server->errorString();
    }
}

void TransferFileServer::newClient()
{
    QTcpSocket *client = m_server->nextPendingConnection();
    qDebug() << "Client is connected: " << client->localAddress().toString();

    sendFile(client);
}

void TransferFileServer::sendFile(QTcpSocket *client)
{
    QFileInfo fileInfo(m_file.fileName());
    QJsonObject json {
        {"filename", fileInfo.fileName()},
        {"filedata", getFileData()}
    };
    QJsonDocument jsonDoc { json };

    client->write(jsonDoc.toJson());
    m_file.close();
}

QString TransferFileServer::getFileData()
{
    if(m_file.open(QIODevice::ReadOnly))
    {
        return m_file.readAll();
    }
    else
    {
        qDebug() << "Open file failed...";
    }
}
