#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, h[1010][5], dp[1010][5][5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)for(int j = 1; j <= 3; j++)cin >> h[i][j];

    for(int i = 1; i <= n; i++){
        for(int s = 1; s <= 3; s++){
            for(int e = 1; e <= 3; e++){
                dp[i][s][e] = 1e9;
                if(i == 1){
                    if(s == e)dp[i][s][e] = h[i][s];
                    continue;
                }
                for(int m = 1; m <= 3; m++){
                    if(m == e)continue;
                    dp[i][s][e] = min(dp[i][s][e], dp[i - 1][s][m] + h[i][e]);
                }
            }
        }
    }

    int ans = 1e9;
    for(int s = 1; s <= 3; s++){
        for(int e = 1; e <= 3; e++){
            if(s == e)continue;
            ans = min(ans, dp[n][s][e]);
        }
    }
    cout << ans;

    return 0;
}