#include <iostream>
#include <cmath>

using namespace std;

int t;
long long x, y;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> x >> y;

        // 1
        // 1 1
        // 1 2 1
        // 1 2 2 1
        // 1 2 3 2 1

        // 1 2 ... n-2 n-1 n-2 ...     2 1     => (n-1)(n-1)
        // 1 2 ... n-2 n-1 n-1 n-2 ... 3 2 1   => (n-1)n
        // 1 2 ... n-2 n-1 n   n-1 ... 4 3 2 1 =>  n^2

        y -= x;
        x = (long long)sqrt(y);
        if (y == x * x)
            cout << 2 * x - 1 << "\n";
        else if (y <= x * (x + 1))
            cout << 2 * x << "\n";
        else
            cout << 2 * x + 1 << "\n";
    }

    return 0;
}