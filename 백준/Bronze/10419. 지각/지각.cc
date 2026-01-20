#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int d;
        cin >> d;

        for (int i = 1; i <= d; i++)
        {
            if (i + i * i > d)
            {
                cout << i - 1 << "\n";
                break;
            }
        }
    }

    return 0;
}