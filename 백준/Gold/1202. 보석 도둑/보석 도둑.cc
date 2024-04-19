#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Jew
{
    int m, v;
};
bool cmp(Jew x, Jew y)
{
    if (x.m < y.m)
        return true;
    else if (x.m == y.m)
        return x.v < y.v;
    return false;
}

int n, k, idx;
long long ans;
priority_queue<int> pq;
vector<Jew> j;
vector<int> b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    j.resize(n);
    for (int i = 0; i < n; i++)
        cin >> j[i].m >> j[i].v;

    b.resize(k);
    for (int i = 0; i < k; i++)
        cin >> b[i];

    sort(j.begin(), j.end(), cmp);
    sort(b.begin(), b.end());

    for (auto i : b)
    {
        while (idx < n && j[idx].m <= i)
            pq.push(j[idx++].v);
        if (!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}