#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<pair<int, int>> adj[10005];

int prim()
{
    vector<bool> added(v + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int ret = 0;

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [weight, p] = pq.top();
        pq.pop();

        if (added[p])
            continue;

        added[p] = true;
        ret += weight;

        for (auto [q, weight] : adj[p])
        {
            if (!added[q])
            {
                pq.push({weight, q});
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    cout << prim();

    return 0;
}