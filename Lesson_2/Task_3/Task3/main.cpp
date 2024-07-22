#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 5;

int main()
{

    int some_shit[MAX_ARRAY_SIZE] = {};
    int element = 0;
    int max_element = 0;
    for(int index = 0; index < MAX_ARRAY_SIZE; index++)
    {
        cout << "Input some shit amount in " << index + 1 << " elements: ";
        cin >> element;
        some_shit[index] = element;
        if(element > max_element)
        {
            max_element = element;
        }
    }

    cout << endl;

    for(int mainIndex = 0; mainIndex < max_element; mainIndex++)
    {
        for(int index = 0; index < MAX_ARRAY_SIZE; index++)
        {
            if(some_shit[index] != 0)
            {
                cout << "*";
                some_shit[index] -= 1;
            }
            else
            {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
