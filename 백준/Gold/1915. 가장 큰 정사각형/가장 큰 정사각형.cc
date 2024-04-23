#include <iostream>
#include <algorithm>

using namespace std;

int n, m, dt[1010][1010], ans;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            int cnt;
            cnt = min(dt[i - 1][j - 1], min(dt[i - 1][j], dt[i][j - 1]));
            if (s[j - 1] == '1')
                dt[i][j] = cnt + 1;
            ans = max(ans, dt[i][j]);
        }
    }

    cout << ans * ans;

    return 0;
}