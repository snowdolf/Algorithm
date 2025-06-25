#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    getline(cin, str);

    int h = 0, s = 0;

    for (int i = 0; i < str.size() - 2; i++)
    {
        if (str[i] == ':' && str[i + 1] == '-')
        {
            if (str[i + 2] == ')') h++;
            else if (str[i + 2] == '(') s++;
            i += 2;
        }
    }

    if (!h && !s) cout << "none";
    else if (h == s) cout << "unsure";
    else if (h > s) cout << "happy";
    else cout << "sad";

    return 0;
}