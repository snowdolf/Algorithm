#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> life(n + 1), happy(n + 1);
    for (int i = 1; i <= n; i++) cin >> life[i];
    for (int i = 1; i <= n; i++) cin >> happy[i];

    vector<vector<int>> dp(n + 1, vector<int>(101, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            if (j <= life[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - life[i]] + happy[i]);
            }
        }
    }

    cout << dp[n][100] <<"\n";

    return 0;
}