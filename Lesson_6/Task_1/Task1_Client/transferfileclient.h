#ifndef TRANSFERFILECLIENT_H
#define TRANSFERFILECLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

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
    void toConnect();
    void getFile();
    void makeFile(QJsonDocument *jsonDoc);

private:
    Ui::TransferFileClient *ui;

    QTcpSocket *m_socket;
};
#endif // TRANSFERFILECLIENT_H
