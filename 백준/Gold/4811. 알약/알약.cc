#include <iostream>

using namespace std;

long long n, dp[33][33];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 1; i <= 30; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    while(1){
        cin >> n;
        if(n == 0) break;
        cout << dp[n][n] << "\n";
    }

    return 0;
}