#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    istringstream iss(str);
    vector<string> words;
    string tmp;

    while (iss >> tmp) words.push_back(tmp);

    for (const string &word : words)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (i > 0 && word[i] == 'p' && i + 1 < word.size() && isVowel(word[i - 1]) && word[i + 1] == word[i - 1])
            {
                i += 2;
                if (i < word.size())
                {
                    cout << word[i];
                }
            }
            else
            {
                cout << word[i];
            }
        }
        cout << " ";
    }

    return 0;
}