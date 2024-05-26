#include <iostream>
#include <string>

using namespace std;

int n, res, chk, cnt;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin.ignore();

    while (n--)
    {
        getline(cin, str);
        res = 0;
        chk = 0;
        for (int i = 0; i < 26; i++)
        {
            cnt = 0;
            for (char j : str)
                if (j == char('a' + i))
                    cnt++;
            if (res < cnt)
            {
                res = cnt;
                chk = i;
            }
            else if (res == cnt)
                chk = -1;
        }
        if (chk < 0)
            cout << "?\n";
        else
            cout << char('a' + chk) << "\n";
    }

    return 0;
}