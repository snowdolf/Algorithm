#include <iostream>

using namespace std;

int n, dp[16][16][4];
// dp[i][j][0] : 입력
// dp[i][j][1] : 가로
// dp[i][j][2] : 세로
// dp[i][j][3] : 대각선

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)cin >> dp[i][j][0];

    for(int i = 1; i < n; i++){
        if(dp[0][i][0])break;
        dp[0][i][1] = 1;
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(!dp[i][j][0]){
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][3];
                dp[i][j][2] = dp[i - 1][j][2] + dp[i - 1][j][3];
            }
            if(!dp[i][j][0] && !dp[i - 1][j][0] && !dp[i][j - 1][0]){
                dp[i][j][3] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][3];
            }
        }
    }

    cout << dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] + dp[n - 1][n - 1][3];

    return 0;
}