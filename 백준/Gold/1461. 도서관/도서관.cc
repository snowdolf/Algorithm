#include <iostream>
#include <queue>

using namespace std;

int f(priority_queue<int> &pq, int m)
{
    int ret = 0;
    while (!pq.empty())
    {
        int x = pq.top();
        for (int i = 0; i < m && !pq.empty(); i++) pq.pop();
        ret += 2 * x;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    priority_queue<int> pq1, pq2;

    while (n--)
    {
        int x;
        cin >> x;
        if (x > 0) pq1.push(x);
        else pq2.push(-x);
    }

    int ans = -max(pq1.empty() ? 0 : pq1.top(), pq2.empty() ? 0 : pq2.top());

    ans += f(pq1, m);
    ans += f(pq2, m);

    cout << ans << "\n";

    return 0;
}