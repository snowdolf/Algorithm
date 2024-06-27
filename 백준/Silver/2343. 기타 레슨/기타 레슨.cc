#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[1000010], l, r;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = max(l, arr[i]);
        r += arr[i];
    }

    while (l < r)
    {
        int cnt = 1, sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + arr[i] > (l + r) / 2)
            {
                cnt++;
                sum = 0;
            }
            sum += arr[i];
        }

        if (cnt > m)
            l = (l + r + 1) / 2;
        else
            r = (l + r) / 2;
    }

    cout << l;

    return 0;
}