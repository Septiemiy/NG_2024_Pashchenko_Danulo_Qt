#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int numberA = 0;
    int numberB = 0;
    int numberC = 0;

    cout << "Input number A: ";
    cin >> numberA;
    cout << endl << "Input number B: ";
    cin >> numberB;
    cout << endl << "Input number C: ";
    cin >> numberC;

    int discriminant = pow(numberB, 2) - 4 * numberA * numberC;

    cout << endl << "Result: first x = ";
    if(discriminant > 0)
    {
        float firstX = (-(numberB) + sqrt(discriminant)) / (2 * numberA);
        float secondX = (-(numberB) - sqrt(discriminant)) / (2 * numberA);
        cout << firstX << " ,second x = " << secondX;
    }
    else if(discriminant == 0)
    {
        float firstX = - (numberB / (2.0 * numberA));
        cout << firstX;
    }
    else if(discriminant < 0)
    {
        float realNumber = - (numberB / (2.0 * numberA));
        cout << realNumber << " + " << sqrt(discriminant * (-1)) / (2 * numberA) << "i"
             << " ,second x = " << realNumber << " - " << sqrt(discriminant * (-1)) / (2 * numberA) << "i";
    }
    return 0;
}
