#include <iostream>
#include <vector>

using namespace std;

int t, n, coin[25], m, dt[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> coin[i];
        cin >> m;

        for (int i = 1; i <= m; i++)
            dt[i] = 0;
        dt[0] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j < coin[i])
                    continue;
                dt[j] += dt[j - coin[i]];
            }
        }

        cout << dt[m] << "\n";
    }

    return 0;
}
