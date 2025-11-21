#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<P>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int s, e;
    cin >> s >> e;

    vector<int> dist(n + 1, 0);
    dist[s] = 1e9;

    priority_queue<P> pq;
    pq.push({dist[s], s});

    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();

        if (dist[u] > c) continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[v] < min(c, w))
            {
                dist[v] = min(c, w);
                pq.push({dist[v], v});
            }
        }
    }

    cout << dist[e] << "\n";

    return 0;
}