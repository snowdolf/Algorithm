#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;

    vector<vector<double>> dist(n, vector<double>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
        }
    }

    vector<bool> visited(n, false);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    double ans = 0;

    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [w, p] = pq.top();
        pq.pop();

        if (visited[p]) continue;

        visited[p] = true;
        ans += w;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                pq.push({dist[p][i], i});
            }
        }
    }

    cout << fixed << setprecision(2) << ans << '\n';

    return 0;
}