#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, cost;
    Edge(int _from, int _to, int _cost)
    {
        from = _from;
        to = _to;
        cost = _cost;
    }
};

int tc, n, m, w, s, e, t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tc;
    while (tc--)
    {
        cin >> n >> m >> w;

        vector<Edge> edges;
        for (int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            edges.push_back(Edge(s, e, t));
            edges.push_back(Edge(e, s, t));
        }
        for (int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            edges.push_back(Edge(s, e, -t));
        }

        bool negative_cycle = false;
        vector<int> dist(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto edge : edges)
            {
                if (dist[edge.to] > dist[edge.from] + edge.cost)
                {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                    if (i == n - 1)
                    {
                        negative_cycle = true;
                        break;
                    }
                }
            }
        }

        if (negative_cycle)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}