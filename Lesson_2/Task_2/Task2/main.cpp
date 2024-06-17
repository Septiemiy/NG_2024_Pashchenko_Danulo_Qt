#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int firstNumber = 0;
    int secondNumber = 0;

    cout << "Input first number: ";
    cin >> firstNumber;
    cout << endl << "Input second number: ";
    cin >> secondNumber;

    cout << endl << "Result: " << firstNumber + secondNumber << endl;

    return 0;
}
