#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int maxs = m;
    bool isValid = true;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        m += x;
        m -= y;
        maxs = max(maxs, m);
        if (m < 0) isValid = false;
    }

    if (isValid && m >= 0) cout << maxs << endl;
    else cout << 0 << endl;

    return 0;
}