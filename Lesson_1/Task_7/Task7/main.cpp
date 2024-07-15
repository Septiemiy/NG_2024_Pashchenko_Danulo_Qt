#include <iostream>

using namespace std;

int main()
{
    int radiusField = 0;
    int positionX = 0;
    int positionY = 0;

    cout << "Input field radius: ";
    cin >> radiusField;
    cout << endl << "Input position X: ";
    cin >> positionX;
    cout << endl << "Input position Y: ";
    cin >> positionY;

    cout << "Result: ";
    int frequency = 0;

    if(positionX == positionY || positionX > positionY)
    {
        frequency = abs(radiusField - positionY);
        cout << frequency;
    }
    else if(positionX < positionY)
    {
        frequency = abs(radiusField - positionX);
        cout << frequency;
    }

    return 0;
}
