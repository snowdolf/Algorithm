#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, t;
int ans = 0;

void f(string x, string y)
{
    if (ans)
        return;
    if (x.length() == y.length())
    {
        if (x == y)
            ans = 1;
        return;
    }

    string str1 = y.substr(0, y.length() - 1);
    string str2 = y.substr(1, y.length());

    if (y[y.length() - 1] == 'A')
        f(x, str1);
    if (y[0] == 'B')
    {
        reverse(str2.begin(), str2.end());
        f(x, str2);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> t;

    f(s, t);

    cout << ans;

    return 0;
}