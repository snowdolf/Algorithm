#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prim(const vector<int> &power, const vector<vector<pair<int, int>>> &adj)
{
    int ret = 0;

    vector<bool> visited(adj.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (auto &x : power) pq.push({0, x});
    while(!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ret += w;

        for (auto &[v, w] : adj[u])
        {
            if (!visited[v]) pq.push({w, v});
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> power(k);
    for (auto &x : power) cin >> x;

    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    cout << prim(power, adj) << "\n";

    return 0;
}