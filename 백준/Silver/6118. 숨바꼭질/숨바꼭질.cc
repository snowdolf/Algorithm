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

    vector<int> adj[n + 1];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<int, int>> q;
    vector<int> dist(n + 1, -1);
    int a, b = 0, c;

    q.push({1, 0});
    dist[1] = 0;
    while (!q.empty())
    {
        auto [u, d] = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = d + 1;
                q.push({v, d + 1});

                if (b < dist[v])
                {
                    a = v;
                    b = dist[v];
                    c = 1;
                }
                else
                {
                    c++;
                    if (a > v) a = v;
                }
            }
        }
    }

    cout << a << " " << b << " " << c;

    return 0;
}