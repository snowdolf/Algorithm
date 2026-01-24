#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, n;
    cin >> c >> n;

    vector<pair<int, int>> promo(n);
    for (auto &x : promo)
    {
        cin >> x.first >> x.second;
    }

    vector<int> dp(c + 101, 1000000);
    dp[0] = 0;

    for (int i = 1; i <= c + 100; i++)
    {
        for (auto x : promo)
        {
            if (i - x.second >= 0)
            {
                dp[i] = min(dp[i], dp[i - x.second] + x.first);
            }
        }
    }

    int ans = dp[c];
    for (int i = c; i <= c + 100; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";

    return 0;
}