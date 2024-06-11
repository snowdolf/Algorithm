#include <iostream>

using namespace std;

long long n;

void f(long long x)
{
    long long y = x / 2;
    long long z = x % 2;
    if (!x)
        return;
    if (z)
    {
        f(y);
        cout << z;
    }
    else
    {
        f(y);
        cout << z;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    f(n);

    return 0;
}