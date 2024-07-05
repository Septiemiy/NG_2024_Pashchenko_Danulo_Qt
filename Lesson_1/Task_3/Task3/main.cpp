#include <iostream>

using namespace std;

int main()
{
    cout << "Input your income: ";
    int income = 0;
    cin >> income;

    if(income < 1000)
    {
        cout << "Work more!";
    }
    if(income > 999)
    {
        if(income > 999999)
            cout << "Your millionaier!";
        if(income < 1000000)
            cout << "You work good!";
    }

    cout << " But you are well done!";

    return 0;
}
