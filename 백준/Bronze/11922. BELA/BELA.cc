#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    char b;
    cin >> n >> b;

    int ans = 0;
    for (int i = 0; i < 4 * n; i++)
    {
        string s;
        cin >> s;

        if (s[0] == 'A') ans += 11;
        else if (s[0] == 'K') ans += 4;
        else if (s[0] == 'Q') ans += 3;
        else if (s[0] == 'J' && s[1] == b) ans += 20;
        else if (s[0] == 'J' && s[1] != b) ans += 2;
        else if (s[0] == 'T') ans += 10;
        else if (s[0] == '9' && s[1] == b) ans += 14;
    }
    cout << ans;

    return 0;
}