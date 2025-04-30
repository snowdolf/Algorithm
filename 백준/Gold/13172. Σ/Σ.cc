#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

ll modpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modinv(ll a)
{
    return modpow(a, mod - 2);
}

ll m, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    while (m--)
    {
        ll n, s, tmp;
        cin >> n >> s;

        tmp = s * modinv(n) % mod;
        ans += tmp;
        ans %= mod;
    }

    cout << ans;

    return 0;
}