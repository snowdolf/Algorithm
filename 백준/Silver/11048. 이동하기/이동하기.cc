#include <iostream>
#include <algorithm>

using namespace std;

int n, m, maze[1010][1010], dp[1010][1010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> maze[i][j];

    dp[1][1] = maze[1][1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + maze[i + 1][j]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + maze[i][j + 1]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + maze[i + 1][j + 1]);
        }
    }

    cout << dp[n][m];

    return 0;
}