#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        int m, n;
        cin >> m >> n;

        if (m == 0) break;

        vector<pair<int, int>> adj[m];

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
            sum += z;
        }

        vector<bool> visited(m, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans = 0;

        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            ans += d;

            for (auto [v, w] : adj[u])
            {
                if (!visited[v])
                {
                    pq.push({w, v});
                }
            }
        }

        cout << sum - ans << '\n';
    }

    return 0;
}