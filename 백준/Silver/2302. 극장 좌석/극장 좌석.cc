#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 0), vip(m + 1, 0);
    for(int i = 1; i <= m; i++)cin >> vip[i];

    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int ans = 1;
    for(int i = 1; i <= m; i++){
        ans *= dp[vip[i] - vip[i - 1] - 1];
    }
    ans *= dp[n - vip[m]];

    cout << ans;

    return 0;
}