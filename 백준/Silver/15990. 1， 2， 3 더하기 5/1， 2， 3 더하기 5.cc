#include <iostream>

using namespace std;

const long long MOD = 1000000009;

int t, n;
long long dp[100010][4];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][3] = 1;

    for(int i = 2; i <= 100000; i++){
        if(i > 1)dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        if(i > 2)dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        if(i > 3)dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }

    cin >> t;

    while(t--){
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << "\n";
    }

    return 0;
}