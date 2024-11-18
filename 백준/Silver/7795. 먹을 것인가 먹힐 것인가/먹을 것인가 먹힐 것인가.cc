#include <iostream>
#include <algorithm>

using namespace std;

int t, n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int j = 0; j < m; j++)
            cin >> b[j];
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        int ans = 0;

        for (int i = 0, j = 0; i < n && j < m; i++)
        {
            if (a[i] > b[j])
                ans += m - j;
            else
                j++, i--;
        }

        cout << ans << "\n";
    }

    return 0;
}