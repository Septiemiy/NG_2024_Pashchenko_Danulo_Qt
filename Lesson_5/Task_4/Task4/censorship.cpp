#include "censorship.h"
#include "ui_censorship.h"

Censorship::Censorship(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Censorship)
{
    ui->setupUi(this);

    ui->e_inputText->setPlaceholderText("Input your text here...");
    ui->e_outputText->setPlaceholderText("Censored text here...");
    ui->e_outputText->setReadOnly(true);

    loadProfanity();

    connect(ui->b_filterProfanity, &QPushButton::clicked, this, &Censorship::filterProfanity);
}

Censorship::~Censorship()
{
    delete ui;
}

void Censorship::loadProfanity()
{
    QFile profanityFileUA(":/profanity/profanityUA.txt");
    if(profanityFileUA.open(QIODevice::ReadOnly))
    {
        m_profanityList = profanityFileUA.readAll().split('\n');
    }
    else
    {
        qDebug() << "Can`t open profanity file";
    }
}

void Censorship::filterProfanity()
{
    QString inputedText = ui->e_inputText->toPlainText();
    for(QString profanity : m_profanityList)
    {
        profanity.chop(1);
        if(inputedText.contains(profanity, Qt::CaseInsensitive))
        {
            int profanityLenght = profanity.size();
            inputedText.replace(profanity, QString("*").repeated(profanityLenght), Qt::CaseInsensitive);
        }
    }
    ui->e_outputText->setText(inputedText);
}
