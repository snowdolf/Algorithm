#include <iostream>
#include <vector>

const int MOD = 1e9;

using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 0)
    {
        cout << "0\n0";
    }
    else if (n > 0)
    {
        cout << "1\n";
        vector<int> f = {1, 1, 0};
        for (int i = 2; i <= n; i++)
        {
            f[0] = (f[1] + f[2]) % MOD;
            f[2] = f[1];
            f[1] = f[0];
        }
        cout << f[0];
    }
    else
    {
        vector<int> f = {0, 0, 1};
        for (int i = -1; i >= n; i--)
        {
            f[0] = (f[2] - f[1]) % MOD;
            f[2] = f[1];
            f[1] = f[0];
        }
        cout << (f[0] < 0 ? "-1\n" : "1\n");
        cout << abs(f[0]);
    }

    return 0;
}