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

    vector<int> a(n), dp(n, n);
    for(int i = 0; i < n; i++)cin >> a[i];

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= a[i] && (i + j) < n; j++){
            dp[i + j] = min(dp[i + j], dp[i] + 1);
        }
    }

    cout << (dp[n - 1] == n ? -1 : dp[n - 1]);

    return 0;
}