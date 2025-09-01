#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dp[35][35];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    cout << dp[n - 1][k - 1];

    return 0;
}