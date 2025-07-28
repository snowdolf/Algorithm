#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, c, d, e;
string s[1010];
pair<int, int> h;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
        int cnt = 0;
        for (char c : s[i]) if (c == '*') cnt++;
        if (cnt >= 3) h.first = i;
    }
    for (int i = 0; i < n; i++) if (s[h.first - 1][i] == '*') h.second = i;

    for (int i = h.second - 1; i >= 0; i--) if (s[h.first][i] == '*') a++;
    for (int i = h.second + 1; i < n; i++) if (s[h.first][i] == '*') b++;
    for (int i = h.first + 1; i < n; i++) if (s[i][h.second] == '*') c++;
    for (int i = h.first + c + 1; i < n; i++) if (s[i][h.second - 1] == '*') d++;
    for (int i = h.first + c + 1; i < n; i++) if (s[i][h.second + 1] == '*') e++;

    cout << h.first + 1 << " " << h.second + 1 << "\n";
    cout << a << " " << b << " " << c << " " << d << " " << e << "\n";

    return 0;
}