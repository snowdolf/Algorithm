#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(31);
    dp[0] = 1;

    for (int i = 2; i <= 30; i += 2)
    {
        int cnt = 0;
        for (int j = i - 2; j >= 0; j -= 2)
        {
            cnt += dp[j];
        }
        dp[i] = dp[i - 2] + 2 * cnt;
    }

    cout << dp[n];

    return 0;
}