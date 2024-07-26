#include <iostream>

using namespace std;

typedef long long ll;

ll n, q, x, y, a, b;
ll bit[100010];

ll sum(ll i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += bit[i];
        i -= i & -i;
    }
    return ret;
}

void add(ll i, ll k)
{
    while (i <= n)
    {
        bit[i] += k;
        i += i & -i;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        cin >> x;
        add(i, x);
    }
    while (q--)
    {
        cin >> x >> y >> a >> b;
        if(x > y)x ^= y ^= x ^= y;

        cout << sum(y) - sum(x - 1) << "\n";

        ll cnt = sum(a) - sum(a - 1);
        add(a, b - cnt);
    }

    return 0;
}