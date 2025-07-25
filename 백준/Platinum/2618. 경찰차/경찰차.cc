#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w, dp[1010][1010];
vector<pair<int, int>> v;
pair<int, int> p[1010][1010];

int dist(int x, int y)
{
    pair<int, int> a, b;

    if (x == 0) a = {1, 1};
    else a = v[x];

    if (y == 0) b = {n, n};
    else b = v[y];

    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    cin >> n >> w;
    v.resize(w + 1);
    for (int i = 1; i <= w; i++) cin >> v[i].first >> v[i].second;

    for (int i = 0; i <= w; i++) for (int j = 0; j <= w; j++) dp[i][j] = 1e9;
    dp[0][0] = 0;

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int k = max(i, j) + 1;

            int cnt = dp[i][j] + dist(i, k);
            if (cnt < dp[k][j])
            {
                dp[k][j] = cnt;
                p[k][j] = {i, j};
            }

            cnt = dp[i][j] + dist(k, j);
            if (cnt < dp[i][k])
            {
                dp[i][k] = cnt;
                p[i][k] = {i, j};
            }
        }
    }

    int ans = 1e9;
    pair<int, int> end;
    for (int i = 0; i < w; i++)
    {
        if (dp[w][i] < ans)
        {
            ans = dp[w][i];
            end = {w, i};
        }
        if (dp[i][w] < ans)
        {
            ans = dp[i][w];
            end = {i, w};
        }
    }

    vector<int> path;
    while (end.first || end.second)
    {
        pair<int, int> prev = p[end.first][end.second];
        if (end.first == prev.first) path.push_back(2);
        else path.push_back(1);
        end = prev;
    }
    reverse(path.begin(), path.end());

    cout << ans << "\n";
    for (auto x : path) cout << x << "\n";

    return 0;
}