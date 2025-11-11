#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> score(n);
    for (auto &x : score) cin >> x;

    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int minScore = score[i], maxScore = score[i];

        for (int j = i; j >= 0; j--)
        {
            minScore = min(minScore, score[j]);
            maxScore = max(maxScore, score[j]);

            int tmp = maxScore - minScore;
            if (j > 0) tmp += dp[j - 1];

            dp[i] = max(dp[i], tmp);
        }
    }
    cout << dp[n - 1] << "\n";

    return 0;
}