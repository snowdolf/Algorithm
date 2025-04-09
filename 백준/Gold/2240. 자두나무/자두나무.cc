#include <iostream>
#include <algorithm>

using namespace std;

int t, w, dp[1001][31][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;
    for(int i = 1; i <= t; i++){
        int cnt;
        cin >> cnt;
        dp[i][0][1] = dp[i - 1][0][1] + (cnt == 1);
        for(int j = 1; j <= w; j++){
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + (cnt == 1);
            dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + (cnt == 2);
        }
    }

    int ans = 0;
    for(int i = 0; i <= w; i++){
        ans = max(ans, max(dp[t][i][1], dp[t][i][2]));
    }
    cout << ans;

    return 0;
}