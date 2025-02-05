#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, dp[10010];
vector<pair<int, int>> vec[10010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    for(int i = 0; i < n; i++){
        int p, q, r;
        cin >> p >> q >> r;
        vec[q].push_back({p, r});
    }

    for(int i = 1; i <= d; i++){
        dp[i] = dp[i - 1] + 1;
        for(auto [j, cost] : vec[i]){
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }

    cout << dp[d];

    return 0;
}