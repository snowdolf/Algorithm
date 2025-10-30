#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> space(n + 1, vector<int>(m + 1));
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(3, 1e7)));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> space[i][j];
            if (i == 1)
            {
                for (int k = 0; k < 3; k++)
                {
                    dp[1][j][k] = space[1][j];
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j + 1 <= m)
            {
                dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]);
                dp[i][j][0] += space[i][j];
            }

            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]);
            dp[i][j][1] += space[i][j];

            if (j - 1 >= 1)
            {
                dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]);
                dp[i][j][2] += space[i][j];
            }
        }
    }

    int ans = 1e7;
    for (int j = 1; j <= m; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            ans = min(ans, dp[n][j][k]);
        }
    }
    cout << ans;
    
    return 0;
} 