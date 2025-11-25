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

    vector<int> d(n + 1, 5e7);
    d[1] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({d[1], 1});

    while (!pq.empty())
    {
        auto [w, u] = pq.top();
        pq.pop();

        if (d[u] < w) continue;

        for (auto [v, w] : adj[u])
        {
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }

    cout << d[n] << "\n";

    return 0;
}