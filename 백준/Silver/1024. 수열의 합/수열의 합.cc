#include <iostream>

using namespace std;

typedef long long ll;

ll n, l, cnt = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (ll i = l; i * (i - 1) / 2 <= n && i <= 100; i++)
    {
        if (i % 2 == 1)
        {
            if (n % i == 0)
            {
                cnt = n / i - i / 2;
                l = i;
                break;
            }
        }
        else
        {
            if (n % (i / 2) == 0)
            {
                if ((n / (i / 2)) % 2 == 1)
                {
                    cnt = n / (i / 2) / 2 - i / 2 + 1;
                    l = i;
                    break;
                }
            }
        }
    }

    if (cnt < 0)
    {
        cout << "-1";
    }
    else
    {
        for (int i = 0; i < l; i++)
        {
            cout << cnt + i << " ";
        }
    }

    return 0;
}