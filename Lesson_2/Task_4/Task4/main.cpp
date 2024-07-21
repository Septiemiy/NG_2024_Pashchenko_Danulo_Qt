#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence = "";
    int wordsCount = 0;
    string space = " ";

    cout << "Input sentence for count words: ";
    getline(cin, sentence);

    size_t position = 0;
    while ((position = sentence.find(space)) != -1) {
        wordsCount++;
        sentence.erase(0, position + space.length());
    }
    wordsCount++;

    cout << endl << "Count words: " << wordsCount;
    return 0;
}
