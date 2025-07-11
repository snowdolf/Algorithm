#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, idx;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '*')
        {
            ans += (s[i] - '0') * (i % 2 == 0 ? 1 : 3);
        }
        else
        {
            idx = i;
        }
    }
    if (idx % 2 == 0)
    {
        for (int i = 0; i < 10; i++)
        {
            if ((ans + i) % 10 == 0)
            {
                cout << i << "\n";
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if ((ans + i * 3) % 10 == 0)
            {
                cout << i << "\n";
                break;
            }
        }
    }

    return 0;
}