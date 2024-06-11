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

    string str = y.substr(0, y.length() - 1);

    if (y[y.length() - 1] == 'A')
        f(x, str);
    else
    {
        reverse(str.begin(), str.end());
        f(x, str);
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