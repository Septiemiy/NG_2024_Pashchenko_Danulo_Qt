#include "transferfileclient.h"
#include "ui_transferfileclient.h"

TransferFileClient::TransferFileClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TransferFileClient)
{
    ui->setupUi(this);

    ui->sb_port->setMaximum(16000);

    m_socket = new QTcpSocket();

    connect(ui->b_getFile, &QPushButton::clicked, this, &TransferFileClient::toConnect);
    connect(m_socket, &QTcpSocket::readyRead, this, &TransferFileClient::getFile);
}

TransferFileClient::~TransferFileClient()
{
    delete ui;
}

void TransferFileClient::toConnect()
{
    QString address = ui->e_host->text();
    int port = ui->sb_port->value();

    m_socket->connectToHost(address, port);
    if(!m_socket->waitForConnected(1000))
    {
       ui->e_message->setText("Failed to connect server");
    }
}

void TransferFileClient::getFile()
{
    ui->e_message->setText("Getting file...");
    QByteArray data = m_socket->readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);

    makeFile(&jsonDoc);
}

void TransferFileClient::makeFile(QJsonDocument *jsonDoc)
{
    QFile file(jsonDoc->object().value("filename").toString());
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(jsonDoc->object().value("filedata").toString().toLocal8Bit());
    }
    file.close();
    ui->e_message->setText("File transfed");
    delete jsonDoc;
}
