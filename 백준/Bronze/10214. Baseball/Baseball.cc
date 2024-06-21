#include <iostream>

using namespace std;

int t, y, k, a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        y = k = 0;
        for (int i = 0; i < 9; i++)
        {
            cin >> a >> b;
            y += a;
            k += b;
        }
        if (y > k)
            cout << "Yonsei\n";
        else if (y < k)
            cout << "Korea\n";
        else
            cout << "Draw\n";
    }

    return 0;
}