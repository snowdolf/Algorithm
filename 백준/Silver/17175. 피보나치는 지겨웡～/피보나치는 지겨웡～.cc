#include <iostream>
#define MOD 1000000007

using namespace std;

long long n, dt[55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++)
        dt[i] = (dt[i - 1] + dt[i - 2] + 2) % MOD;

    cout << dt[n] + 1;

    return 0;
}