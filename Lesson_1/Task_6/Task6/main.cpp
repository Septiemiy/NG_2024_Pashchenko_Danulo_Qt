#include <iostream>

using namespace std;

int main()
{
    int height;
    cout << "Input the height of the tree: ";
    cin >> height;

    cout << endl;

    for(int mainIndex = 0; mainIndex < height; mainIndex++)
    {
        for(int index = height; index > mainIndex; index--)
        {
            cout << ' ';
        }
        for(int index = 0; index <= (mainIndex * 2); index++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for(int index = 0; index < height; index++)
    {
        cout << ' ';
    }
    cout << '*';

    return 0;
}
