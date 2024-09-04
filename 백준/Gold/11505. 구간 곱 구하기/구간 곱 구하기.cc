#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll n, m, k, a, b, c, treeSize;
vector<ll> seg;

void init()
{
    treeSize = 1;
    while (treeSize < n)
        treeSize *= 2;

    seg.assign(2 * treeSize, 1);
}

void update(int idx, ll x)
{
    idx += treeSize - 1;
    seg[idx] = x;
    while (idx > 1)
    {
        idx /= 2;
        seg[idx] = seg[2 * idx] * seg[2 * idx + 1] % MOD;
    }
}

ll query(int idx, int l, int r)
{
    if (c < l || r < b)
        return 1;

    if (b <= l && r <= c)
        return seg[idx];

    return query(2 * idx, l, (l + r) / 2) * query(2 * idx + 1, (l + r) / 2 + 1, r) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    init();

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a);
    }

    for (int i = 1; i <= m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        else
            cout << query(1, 1, treeSize) << "\n";
    }

    return 0;
}