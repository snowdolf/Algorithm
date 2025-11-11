#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> score(n);
    for (auto &x : score) cin >> x;

    vector<int> dp(n, 0);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int l = 10000, r = 0;
            for (int k = j; k <= i; k++)
            {
                l = min(l, score[k]);
                r = max(r, score[k]);
            }
            int tmp = r - l;
            if (j > 0) tmp += dp[j - 1];
            dp[i] = max(dp[i], tmp);
        }
    }
    cout << dp[n - 1] << "\n";

    return 0;
}