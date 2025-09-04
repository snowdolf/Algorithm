#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ans += (1 + 3 * i);
        ans %= 45678;
    }

    cout << ans;

    return 0;
}