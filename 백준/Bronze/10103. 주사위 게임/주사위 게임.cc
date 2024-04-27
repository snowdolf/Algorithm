#include <iostream>

using namespace std;

int n, a, b, x = 100, y = 100;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        cin >> a >> b;
        if (a < b)
            x -= b;
        if (a > b)
            y -= a;
    }

    cout << x << "\n"
         << y;

    return 0;
}