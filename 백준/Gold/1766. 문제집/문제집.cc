#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, d[32005];
vector<int> v[32005];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        d[b]++;
    }

    for (int i = 1; i <= n; i++)
        if (!d[i])
            pq.push(i);

    while (!pq.empty())
    {
        int pt = pq.top();
        pq.pop();
        cout << pt << " ";

        for (auto i : v[pt])
        {
            d[i]--;
            if (!d[i])
                pq.push(i);
        }
    }

    return 0;
}