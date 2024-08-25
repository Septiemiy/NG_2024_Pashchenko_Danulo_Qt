#ifndef TRANSFERFILECLIENT_H
#define TRANSFERFILECLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFileInfo>
#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class TransferFileClient;
}
QT_END_NAMESPACE

class TransferFileClient : public QMainWindow
{
    Q_OBJECT

public:
    TransferFileClient(QWidget *parent = nullptr);
    ~TransferFileClient();

private slots:
    void login();
    void connectionEstablished();
    void sendMessage();
    void messageReceived();
    void getFileFromUser();

private:
    QString getFileData(QString filePath);
    void makeFile(QJsonDocument *jsonDoc);
    void createFileStatusBar();

private:
    Ui::TransferFileClient *ui;
    QTcpSocket *m_socket;
    QString m_filePath;
    QLineEdit *m_fileStatusBar;
};
#endif // TRANSFERFILECLIENT_H
