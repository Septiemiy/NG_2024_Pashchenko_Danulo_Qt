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
    string word = "";
    if(sentence != "" && sentence != " ")
    {
        while ((position = sentence.find(space)) != -1) {
            word = sentence.substr(0, position);
            try
            {
                stoi(word);
            }
            catch(...)
            {
                wordsCount++;
            }
            sentence.erase(0, position + space.length());
        }
        try
        {
            stoi(sentence);
        }
        catch(...)
        {
            wordsCount++;
        }
    }

    cout << endl << "Count words: " << wordsCount;
    return 0;
}
