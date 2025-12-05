#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ans = 0;

    if (n < 6) ans = 0;
    else
    {
        for (int i = 2; i <= n - 4; i += 2)
        {
            for (int j = 1; j < n - i; j++)
            {
                if ((j + 2) <= (n - i - j)) ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}