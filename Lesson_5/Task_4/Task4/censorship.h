#ifndef CENSORSHIP_H
#define CENSORSHIP_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Censorship;
}
QT_END_NAMESPACE

class Censorship : public QMainWindow
{
    Q_OBJECT

public:
    Censorship(QWidget *parent = nullptr);
    ~Censorship();

public:
    void loadProfanity();

public slots:
    void filterProfanity();

private:
    Ui::Censorship *ui;

    QList<QByteArray> m_profanityList;
};
#endif // CENSORSHIP_H
