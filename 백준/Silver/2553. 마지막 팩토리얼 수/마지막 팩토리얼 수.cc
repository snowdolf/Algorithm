#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    long long ans = 1;

    for (long long i = 2; i <= n; i++)
    {
        long long cnt = i;
        while (cnt % 10 == 0) cnt /= 10;
        ans *= cnt;
        while (ans % 10 == 0) ans /= 10;
        ans %= 100000000;
    }
    while (ans % 10 == 0) ans /= 10;
    cout << ans % 10;

    return 0;
}