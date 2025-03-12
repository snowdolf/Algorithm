#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, ans = 0;

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        ans += (n * i + i);
    }

    cout << ans;

    return 0;
}