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

    connect (client, &QTcpSocket::disconnected, this, &TransferFileServer::leftClient);
    connect (client, &QTcpSocket::readyRead, this, &TransferFileServer::messageFromClient);

    m_clients.append(client);
}

void TransferFileServer::leftClient()
{
    QTcpSocket *socket = (QTcpSocket *)sender();

    qDebug() << "Client " << socket->localAddress().toString() << " has been left";
    m_clients.removeOne(socket);
}

void TransferFileServer::sendToAll(QByteArray message)
{
    for (QTcpSocket *client : m_clients)
        client->write(message);
}

void TransferFileServer::messageFromClient()
{
    QTcpSocket *socket = (QTcpSocket *)sender();
    sendToAll(socket->readAll());
}
