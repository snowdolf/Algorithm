#include <iostream>
#include <list>

using namespace std;

int n;
string str;
list<char> li;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    while (n--)
    {
        cin >> str;

        li.clear();
        auto it = li.end();

        for (auto ch : str)
        {
            switch (ch)
            {
            case '<':
                if (it != li.begin())
                    it--;
                break;
            case '>':
                if (it != li.end())
                    it++;
                break;
            case '-':
                if (it != li.begin())
                    it = li.erase(--it);
                break;
            default:
                li.insert(it, ch);
                break;
            }
        }

        for (auto ch : li)
            cout << ch;
        cout << "\n";
    }

    return 0;
}