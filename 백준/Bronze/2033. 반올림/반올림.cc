#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long m = 10;

    while (n > m)
    {
        if (n % m >= m / 2)
        {
            n -= n % m;
            n += m;
        }
        else
        {
            n -= n % m;
        }
        m *= 10;
    }

    cout << n << "\n";

    return 0;
}