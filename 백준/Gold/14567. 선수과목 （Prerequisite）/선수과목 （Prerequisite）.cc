#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int u, vector<bool> &visited, vector<int> &ord, vector<int> adj[])
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, visited, ord, adj);
        }
    }
    ord.push_back(u);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<bool> visited(n + 1, false);
    vector<int> ord;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, ord, adj);
        }
    }
    reverse(ord.begin(), ord.end());

    vector<int> dist(n + 1, 1);
    for (int u : ord)
    {
        for (int v : adj[u])
        {
            dist[v] = max(dist[v], dist[u] + 1);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}