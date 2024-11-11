#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int INF = 300010;
int n, m, k, x, a, b;

vector<P> edge[300010];
int d[300010];

priority_queue<P, vector<P>, greater<P>> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edge[a].push_back(P(b, 1));
    }

    for (int i = 1; i <= n; i++)
        d[i] = INF;
    d[x] = 0;
    que.push(P(0, x));

    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        if (d[p.second] < p.first)
            continue;

        for (auto i : edge[p.second])
        {
            if (d[i.first] > d[p.second] + i.second)
            {
                d[i.first] = d[p.second] + i.second;
                que.push(P(d[i.first], i.first));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == k)
        {
            ans++;
            cout << i << "\n";
        }
    }
    if (ans == 0)
        cout << "-1";

    return 0;
}