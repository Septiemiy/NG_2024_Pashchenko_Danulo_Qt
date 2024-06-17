#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Input your income: ";
    int income = 0;
    cin >> income;

    if(income < 1000)
    {
        cout << "Work more!";
    }
    if(income > 1000)
    {
        if(income > 1000000)
            cout << "Your millionaier!";
        if(income < 1000000)
            cout << "You work good!";
    }

    cout << " But you are well done!";

    return 0;
}
