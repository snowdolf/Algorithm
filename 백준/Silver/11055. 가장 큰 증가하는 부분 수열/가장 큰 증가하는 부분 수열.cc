#include <iostream>

using namespace std;

int n, a[1010], dt[1010], res;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dt[0] = a[0];
    res = dt[0];
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i] && cnt < dt[j])
                cnt = dt[j];
        }
        dt[i] = a[i];
        if (cnt)
            dt[i] += cnt;
        if (res < dt[i])
            res = dt[i];
    }

    cout << res;

    return 0;
}