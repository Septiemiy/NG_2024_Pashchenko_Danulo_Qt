#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include "QtMath"
#include "QDebug"

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    QString getResult(QStringList eqution);

private slots:
    void setNumbersInTextEdit();
    void setOperationsInTextEdit();
    void setRadicalInTextEdit();
    void outputResult();
    void clearTextEdit();

private:
    Ui::Calculator *ui;

    enum EqutionParts
    {
       FIRST_NUMBER,
       OPERATION,
       SECOND_NUMBER
    };

    enum RadicalParts
    {
       RADICAL,
       NUMBER
    };
};
#endif // CALCULATOR_H
