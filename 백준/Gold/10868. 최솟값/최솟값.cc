#include <iostream>
#include <algorithm>

using namespace std;

const int INTMAX = 1000000000;

int n, m, a, b, length;
int seg[400010];

void init()
{
    length = 1;
    while (length < n)
        length *= 2;

    for (int i = 1; i < 2 * length; i++)
        seg[i] = INTMAX;
}

void update(int idx, int x)
{
    idx += length - 1;
    seg[idx] = x;
    while (idx > 1)
    {
        idx /= 2;
        seg[idx] = min(seg[2 * idx], seg[2 * idx + 1]);
    }
}

int query(int idx, int l, int r)
{
    if (b < l || r < a)
        return INTMAX;

    if (a <= l && r <= b)
        return seg[idx];
    else
        return min(query(2 * idx, l, (l + r) / 2), query(2 * idx + 1, (l + r) / 2 + 1, r));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    init();

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a);
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        cout << query(1, 1, length) << "\n";
    }

    return 0;
}