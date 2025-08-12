#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pair<double, double>> points(n + 1);
    for (int i = 1; i <= n; i++) cin >> points[i].first >> points[i].second;

    vector<vector<double>> dist(n + 1, vector<double>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dist[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dist[x][y] = dist[y][x] = 0;
    }

    vector<bool> visited(n + 1, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    double ans = 0;

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ans += d;

        for (int v = 1; v <= n; v++)
        {
            if (!visited[v])
            {
                pq.push({dist[u][v], v});
            }
        }
    }

    cout << fixed << setprecision(2) << ans << "\n";

    return 0;
}