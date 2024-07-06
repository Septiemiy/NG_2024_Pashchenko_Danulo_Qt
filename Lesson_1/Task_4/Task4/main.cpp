#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int firstNumber = 0;
    int secondNumber = 0;
    char operation = '+';

    cout << endl << "Input operation (+, -, *, /, ^, sqrt -> (s)): ";
    cin >> operation;
    cout << "Input first number: ";
    cin >> firstNumber;
    if(operation != 's')
    {
        cout << endl << "Input second number: ";
        cin >> secondNumber;
    }

    cout << endl << "Result: ";

    switch(operation)
    {
        case '+':
            cout << firstNumber + secondNumber;
            break;
        case '-':
            cout << firstNumber - secondNumber;
            break;
        case '*':
            cout << firstNumber * secondNumber;
            break;
        case '/':
            cout << firstNumber / secondNumber;
            break;
        case '^':
            cout << pow(firstNumber, secondNumber);
            break;
        case 's':
            cout << sqrt(firstNumber);
            break;
        default:
            cout << "Error";
    }
    cout << endl;

    return 0;
}
