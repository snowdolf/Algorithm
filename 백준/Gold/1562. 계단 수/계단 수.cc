#include <iostream>

using namespace std;

const int MOD = 1e9;

long long dp[1 << 10][101][11];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int j = 1; j <= 9; j++) dp[1 << j][1][j] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int m = 0; m < (1 << 10); m++)
            {
                if (j < 9)
                {
                    dp[m | (1 << j)][i][j] = (dp[m | (1 << j)][i][j] + dp[m][i - 1][j + 1]) % MOD;
                }
                if (j > 0)
                {
                    dp[m | (1 << j)][i][j] = (dp[m | (1 << j)][i][j] + dp[m][i - 1][j - 1]) % MOD;
                }
            }
        }
    }

    long long ans = 0;
    for (int j = 0; j <= 9; j++)
    {
        ans = (ans + dp[(1 << 10) - 1][n][j]) % MOD;
    }
    cout << ans;

    return 0;
}