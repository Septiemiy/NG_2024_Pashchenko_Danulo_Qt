#include <iostream>

using namespace std;

const int MAX_ARRAY_SIZE = 20;

int main()
{
    int chandelier[MAX_ARRAY_SIZE] = {};
    int element = -1;
    int max_element = 0;
    int array_lenght = 0;
    for(int index = 0; index < MAX_ARRAY_SIZE; index++)
    {
        cout << "Input chandelier elements (print '0' to stop input): ";
        cin >> element;
        chandelier[index] = element;
        array_lenght++;
        if(element > max_element)
        {
            max_element = element;
        }
        if(element == 0)
        {
            break;
        }
    }

    cout << endl;

    for(int mainIndex = 0; mainIndex < array_lenght; mainIndex++)
    {
        for(int index = 0; index < (max_element - chandelier[mainIndex]) / 2; index++)
        {
            cout << ' ';
        }
        for(int index = 0; index < chandelier[mainIndex]; index++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
