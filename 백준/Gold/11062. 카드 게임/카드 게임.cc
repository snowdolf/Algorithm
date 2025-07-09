#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++) dp[i][i] = arr[i];
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                int j = i + l - 1;

                int left = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int right = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);

                dp[i][j] = max(left, right);
            }
        }
        cout << dp[0][n - 1] << "\n";
    }

    return 0;
}