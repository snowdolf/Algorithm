#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long n, dp[10][3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        dp[0][1] = dp[1][0] + dp[2][0];
        dp[1][1] = dp[0][0] + dp[2][0] + dp[3][0];
        dp[2][1] = dp[0][0] + dp[1][0] + dp[3][0] + dp[4][0];
        dp[3][1] = dp[1][0] + dp[2][0] + dp[4][0] + dp[5][0];
        dp[4][1] = dp[2][0] + dp[3][0] + dp[5][0] + dp[6][0];
        dp[5][1] = dp[3][0] + dp[4][0] + dp[7][0];
        dp[6][1] = dp[4][0] + dp[7][0];
        dp[7][1] = dp[5][0] + dp[6][0];
        for(int j = 0; j < 8; j++)dp[j][0] = dp[j][1] % MOD;
    }
    cout << dp[0][0];

    return 0;
}