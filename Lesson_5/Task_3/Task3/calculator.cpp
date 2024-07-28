#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->e_result->setAlignment(Qt::AlignRight);
    ui->e_result->setFontPointSize(12.5);
    ui->e_result->setReadOnly(true);

    connect(ui->b_zero, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_one, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_two, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_three, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_four, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_five, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_six, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_seven, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_eight, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_nine, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);
    connect(ui->b_dot, &QPushButton::clicked, this, &Calculator::setNumbersInTextEdit);

    connect(ui->b_plus, &QPushButton::clicked, this, &Calculator::setOperationsInTextEdit);
    connect(ui->b_minus, &QPushButton::clicked, this, &Calculator::setOperationsInTextEdit);
    connect(ui->b_multiplication, &QPushButton::clicked, this, &Calculator::setOperationsInTextEdit);
    connect(ui->b_division, &QPushButton::clicked, this, &Calculator::setOperationsInTextEdit);
    connect(ui->b_power, &QPushButton::clicked, this, &Calculator::setOperationsInTextEdit);

    connect(ui->b_radical, &QPushButton::clicked, this, &Calculator::setRadicalInTextEdit);

    connect(ui->b_equal, &QPushButton::clicked, this, &Calculator::outputResult);

    connect(ui->b_clear, &QPushButton::clicked, this, &Calculator::clearTextEdit);
}

Calculator::~Calculator()
{
    delete ui;
}

QString Calculator::getResult(QStringList eqution)
{
    if(eqution[RadicalParts::RADICAL] == "√")
    {
        return QString::number(qSqrt(eqution[RadicalParts::NUMBER].toFloat()));
    }
    else
    {
        switch(*eqution[EqutionParts::OPERATION].toLocal8Bit().data())
        {
            case '+':
                return QString::number(eqution[EqutionParts::FIRST_NUMBER].toFloat() + eqution[EqutionParts::SECOND_NUMBER].toFloat());
                break;
            case '-':
                return QString::number(eqution[EqutionParts::FIRST_NUMBER].toFloat() - eqution[EqutionParts::SECOND_NUMBER].toFloat());
                break;
            case '*':
                return QString::number(eqution[EqutionParts::FIRST_NUMBER].toFloat() * eqution[EqutionParts::SECOND_NUMBER].toFloat());
                break;
            case '/':
                return QString::number(eqution[EqutionParts::FIRST_NUMBER].toFloat() / eqution[EqutionParts::SECOND_NUMBER].toFloat());
                break;
            case '^':
                return QString::number(qPow(eqution[EqutionParts::FIRST_NUMBER].toFloat(), eqution[EqutionParts::SECOND_NUMBER].toFloat()));
                break;
        }
    }
}

void Calculator::setNumbersInTextEdit()
{
    QPushButton *button = (QPushButton*)sender();
    ui->e_result->insertPlainText(button->text());
}

void Calculator::setOperationsInTextEdit()
{
    QPushButton *button = (QPushButton*)sender();
    ui->e_result->insertPlainText(" " + button->text() + " ");
}

void Calculator::setRadicalInTextEdit()
{
    if(ui->e_result->toPlainText() == "")
    {
        ui->e_result->insertPlainText("√ ");
    }
    else
    {
        QString eqution = ui->e_result->toPlainText();
        ui->e_result->clear();
        ui->e_result->insertPlainText("√ " + eqution);
        ui->e_result->setAlignment(Qt::AlignRight);
    }
}

void Calculator::outputResult()
{
    QStringList eqution = ui->e_result->toPlainText().split(" ");
    QString result = getResult(eqution);
    ui->e_result->clear();
    ui->e_result->insertPlainText(result);
    ui->e_result->setAlignment(Qt::AlignRight);
}

void Calculator::clearTextEdit()
{
    ui->e_result->clear();
    ui->e_result->setAlignment(Qt::AlignRight);
}
