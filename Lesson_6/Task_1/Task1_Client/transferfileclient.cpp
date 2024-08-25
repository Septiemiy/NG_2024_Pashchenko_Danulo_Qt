#include "transferfileclient.h"
#include "ui_transferfileclient.h"

TransferFileClient::TransferFileClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TransferFileClient)
{
    ui->setupUi(this);

    m_socket = new QTcpSocket();
    m_fileStatusBar = new QLineEdit();
    m_fileStatusBar->setText("File upload. Write message and press Send or just send file.");
    ui->vl_statusFileBar->addWidget(m_fileStatusBar);
    m_fileStatusBar->hide();

    ui->sb_port->setMaximum(16000);
    ui->te_chat->setReadOnly(true);

    connect(ui->b_login, &QPushButton::clicked, this, &TransferFileClient::login);
    connect(ui->b_send, &QPushButton::clicked, this, &TransferFileClient::sendMessage);
    connect(m_socket, &QTcpSocket::connected, this, &TransferFileClient::connectionEstablished);
    connect(m_socket, &QTcpSocket::readyRead, this, &TransferFileClient::messageReceived);
    connect(ui->b_sendFile, &QPushButton::clicked, this, &TransferFileClient::getFileFromUser);
}

TransferFileClient::~TransferFileClient()
{
    delete ui;
}

void TransferFileClient::login()
{
    QString address = ui->e_address->text();
    int port = ui->sb_port->value();

    m_socket->connectToHost(QHostAddress(address),port);
}

void TransferFileClient::connectionEstablished()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void TransferFileClient::sendMessage()
{
    QFileInfo fileInfo(m_filePath);
    QJsonObject json;
    json["message"] = ui->te_input->toPlainText();
    if(!m_filePath.isEmpty())
    {
        json["filename"] = fileInfo.fileName();
        json["filedata"] = getFileData(m_filePath);
    };
    QJsonDocument jsonDoc { json };

    m_socket->write(jsonDoc.toJson());

    m_filePath.clear();
    m_fileStatusBar->hide();
    ui->te_input->clear();
}

void TransferFileClient::messageReceived()
{
    QByteArray dataFromClient = m_socket->readAll();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(dataFromClient);

    if(jsonDoc.object().value("message") != "")
    {
        ui->te_chat->append(jsonDoc.object().value("message").toString());
    }
    makeFile(&jsonDoc);
}

void TransferFileClient::getFileFromUser()
{
    m_filePath = QFileDialog::getOpenFileName(this, tr("Open txt file"), "/", tr("Text file (*.txt)"));
    if(!m_filePath.isNull())
    {
        createFileStatusBar();
    }
}

QString TransferFileClient::getFileData(QString filePath)
{
    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        file.close();
        return data;
    }
    else
    {
        qDebug() << "Open file failed...";
    }
}

void TransferFileClient::makeFile(QJsonDocument *jsonDoc)
{
    if(jsonDoc->object().contains("filename"))
    {
        QFile file(jsonDoc->object().value("filename").toString());
        if(file.open(QIODevice::WriteOnly))
        {
            file.write(jsonDoc->object().value("filedata").toString().toLocal8Bit());
        }
        file.close();
        ui->te_chat->append("(User send file)");
    }
}

void TransferFileClient::createFileStatusBar()
{
    m_fileStatusBar->show();
}
