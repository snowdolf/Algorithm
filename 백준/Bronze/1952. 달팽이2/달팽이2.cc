#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    int ans = 0;

    while (m > 1 && n > 1)
    {
        if (m > 1) ans ++;
        if (n > 1) ans ++;
        m--;
        n--;
    }
    if (m > 1) ans++;

    cout << ans;

    return 0;
}