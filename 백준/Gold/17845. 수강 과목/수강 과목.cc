#include <iostream>

using namespace std;

int n, k, a[10010], b[10010], dp[1010][10010];

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= k; i++)
    {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (b[i] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
            }
        }
    }

    cout << dp[k][n];

    return 0;
}