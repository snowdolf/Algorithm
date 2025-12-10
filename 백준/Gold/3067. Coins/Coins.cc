#include <iostream>
#include <vector>

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

        vector<int> v(n);
        for (auto &x : v) cin >> x;

        int m;
        cin >> m;

        vector<int> dp(m + 1, 0);
        dp[0] = 1;

        for (auto x : v)
        {
            for (int i = x; i <= m; i++)
            {
                dp[i] += dp[i - x];
            }
        }

        cout << dp[m] << "\n";
    }
    

    return 0;
}