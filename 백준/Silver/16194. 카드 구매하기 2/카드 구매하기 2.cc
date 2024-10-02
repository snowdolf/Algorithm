#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[1010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> dp[i];

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            dp[j] = min(dp[j], dp[j - i] + dp[i]);

    cout << dp[n];

    return 0;
}