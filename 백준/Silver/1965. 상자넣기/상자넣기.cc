#include <iostream>
#include <algorithm>

using namespace std;

int n, box[1010], dp[1010] = {0, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)cin >> box[i];

    int ans = 0;
    for(int i = 2; i <= n; i++){
        for(int j = i - 1; j > 0; j--){
            if(box[j] >= box[i])continue;
            dp[i] = max(dp[i], dp[j]);
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}