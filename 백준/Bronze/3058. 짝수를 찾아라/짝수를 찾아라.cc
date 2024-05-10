#include <iostream>

using namespace std;

int t, sum, ans, cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--)
    {
        sum = 0;
        ans = 100;
        for (int i = 0; i < 7; i++)
        {
            cin >> cnt;
            if (cnt % 2 == 0)
            {
                sum += cnt;
                ans = ans > cnt ? cnt : ans;
            }
        }
        cout << sum << " " << ans << "\n";
    }

    return 0;
}