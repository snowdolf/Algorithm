#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0, sum = 0;

    while (n--)
    {
        int cnt;
        cin >> cnt;

        sum += cnt;
        if (sum > m)
        {
            ans++;
            sum = cnt;
        }
    }
    if (sum > 0)
    {
        ans++;
    }

    cout << ans << "\n";

    return 0;
}