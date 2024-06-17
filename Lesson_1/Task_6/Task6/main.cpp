#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int height;
    cout << "Input the height of the tree: ";
    cin >> height;
    int heightCopy = height - 1;
    int mainIndex = 0;

    cout << endl;

    for(int index = 1; index < height * 2; index += 2)
    {
        for(int index = 0; index < heightCopy; index++)
        {
            cout << ' ';
        }
        heightCopy--;
        while(mainIndex != index)
        {
            cout << '*';
            mainIndex++;
        }
        mainIndex = 0;
        cout << endl;
    }

    do
    {
        cout << ' ';
        mainIndex++;
    }while(mainIndex != height - 1);
    cout << '*' << endl;

    return 0;
}
