#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        string s;
        cin >> s;

        if (s == "#") break;

        int ans = 0;
        for (char c : s)
        {
            ans *= 8;
            if (c == '\\') ans += 1;
            else if (c == '(') ans += 2;
            else if (c == '@') ans += 3;
            else if (c == '?') ans += 4;
            else if (c == '>') ans += 5;
            else if (c == '&') ans += 6;
            else if (c == '%') ans += 7;
            else if (c == '/') ans -= 1;
        }
        cout << ans << "\n";
    }

    return 0;
}