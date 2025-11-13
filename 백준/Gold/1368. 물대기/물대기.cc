#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int prim(int n, const vector<int> &w, const vector<vector<int>> &p)
{
    int ret = 0;

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) pq.push({w[i], i});
    while (!pq.empty())
    {
        auto [c, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ret += c;

        for (int v = 0; v < n; v++)
        {
            if (u != v && !visited[v])
            {
                pq.push({p[u][v], v});
            }
        }
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> w(n);
    for (auto &x : w) cin >> x;

    vector<vector<int>> p(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> p[i][j];

    cout << prim(n, w, p) << "\n";

    return 0;
}