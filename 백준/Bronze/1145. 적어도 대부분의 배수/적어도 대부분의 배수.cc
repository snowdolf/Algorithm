#include <iostream>

using namespace std;

int a[10], ans = 1000000, idx[5];

int gcd(int x, int y)
{
    if (x < y)
        return gcd(y, x);
    if (!y)
        return x;
    return gcd(y, x % y);
}

void g()
{
    int cnt = a[idx[1]] * a[idx[2]] / gcd(a[idx[1]], a[idx[2]]);
    cnt = cnt * a[idx[3]] / gcd(cnt, a[idx[3]]);

    if (ans > cnt)
        ans = cnt;

    return;
}

void f(int n, int x)
{
    if (x > 3)
    {
        g();
        return;
    }
    if (n > 5)
    {
        return;
    }

    f(n + 1, x);

    idx[x] = n;
    f(n + 1, x + 1);
    idx[x] = 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i <= 5; i++)
        cin >> a[i];

    f(1, 1);

    cout << ans;

    return 0;
}
