#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        adj[x].push_back(y);
        adj[y].push_back(x);

        dist[x][y] = z;
        dist[y][x] = z;
    }

    for (int i = 1; i <= n; i++)
    {
        vector<bool> visited(n + 1, false);
        queue<pair<int, int>> que;
            
        que.push({i, 0});
        visited[i] = true;

        while (!que.empty())
        {
            auto [u, w] = que.front();
            que.pop();

            for (auto v : adj[u])
            {
                if (!visited[v])
                {
                    que.push({v, w + dist[u][v]});
                    visited[v] = true;

                    dist[i][v] = w + dist[u][v];
                    dist[v][i] = w + dist[u][v];
                }
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << dist[x][y] << "\n";
    }

    return 0;
}