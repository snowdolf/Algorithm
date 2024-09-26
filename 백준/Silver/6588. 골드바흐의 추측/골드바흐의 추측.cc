#include <iostream>

using namespace std;

const int MAX = 1000000;

int n;
bool chk[MAX + 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= MAX; i++)
    {
        if (chk[i])
            continue;
        for (int j = 2 * i; j <= MAX; j += i)
        {
            chk[j] = true;
        }
    }

    while (1)
    {
        cin >> n;
        if (!n)
            break;

        bool cnt = false;

        for (int i = 3; i <= n / 2; i += 2)
        {
            if (!chk[i] && !chk[n - i])
            {
                cout << n << " = " << i << " + " << n - i << "\n";
                cnt = true;
                break;
            }
        }

        if (!cnt)
            cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}