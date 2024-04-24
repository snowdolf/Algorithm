#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int n, m, a, b, c;
int INF = 100000000;

vector<P> edge[1010];
int d[1010], past[1010];
vector<int> path;

priority_queue<P, vector<P>, greater<P>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        edge[a].push_back(P(b, c));
    }
    cin >> a >> b;

    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[a] = 0;
    pq.push(P(0, a));

    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();

        if (d[p.second] < p.first)
            continue;
        for (auto i : edge[p.second])
        {
            if (d[i.first] > d[p.second] + i.second)
            {
                d[i.first] = d[p.second] + i.second;
                pq.push(P(d[i.first], i.first));
                past[i.first] = p.second;
            }
        }
    }

    cout << d[b] << "\n";

    for (int i = b; i > 0; i = past[i])
        path.push_back(i);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (auto i : path)
        cout << i << " ";

    return 0;
}