#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prim(const vector<vector<pair<int, int>>> &adj)
{
    int ret = 0;

    vector<bool> visited(adj.size(), false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ret += w;

        for (auto [v, w] : adj[u])
        {
            if (!visited[v])
            {
                pq.push({w, v});
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    cout << prim(adj) << "\n";

    return 0;
}