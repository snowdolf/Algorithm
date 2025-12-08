#include <iostream>
#include <vector>

using namespace std;

bool hasZero(int n)
{
    while (n)
    {
        if (n % 10 == 0) return true;
        n /= 10;
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 1;
    vector<int> v(10000, 10000);

    for (int i = 1111; i <= 9999; i++)
    {
        if (hasZero(i)) continue;

        int tmp = i;
        for (int j = 0; j < 3; j++)
        {
            tmp = tmp / 10 + (tmp % 10) * 1000;
            v[i] = min(v[i], v[tmp]);
        }

        if (v[i] == 10000) v[i] = cnt++;
    }

    int n = 0;
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        n = n * 10 + x;
    }

    int ans = v[n];
    for (int i = 0; i < 3; i++)
    {
        n = n / 10 + (n % 10) * 1000;
        ans = min(ans, v[n]);
    }

    cout << ans << "\n";

    return 0;
}