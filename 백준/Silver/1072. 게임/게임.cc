#include <iostream>

using namespace std;

long long x, y, z, l, r, n, nz;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x >> y;

    z = 100 * y / x;

    if (z >= 99)
        cout << "-1";
    else
    {
        l = 1, r = x;

        while (l <= r)
        {
            n = (l + r) / 2;
            nz = 100 * (y + n) / (x + n);

            if (nz > z)
                r = n - 1;
            else
                l = n + 1;
        }

        cout << l;
    }

    return 0;
}