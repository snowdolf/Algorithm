#include <iostream>

using namespace std;

int n, p, num, idx[1005];
bool chk[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p;

    num = n;
    if (num < p)
    {
        chk[num] = 1;
        idx[num] = 1;
    }

    for (int i = 2;; i++)
    {
        num = (num * n) % p;
        if (chk[num])
        {
            cout << i - idx[num];
            break;
        }
        chk[num] = 1;
        idx[num] = i;
    }

    return 0;
}