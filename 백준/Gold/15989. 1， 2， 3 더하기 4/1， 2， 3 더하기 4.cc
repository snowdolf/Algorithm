#include <iostream>

using namespace std;

int t, n, dp[10005][5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    dp[0][1] = 1;
    for(int i = 1; i <= 10000; i++){
        dp[i][1] = dp[i - 1][1];
        if(i >= 2)dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        if(i >= 3)dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    while(t--){
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }

    return 0;
}