#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int g[6] = {1, 2, 3, 3, 4, 10};
    int s[7] = {1, 2, 2, 2, 3, 5, 10};

    for (int i = 1; i <= t; i++)
    {
        int gsum = 0, ssum = 0, cnt;
        for (int j = 0; j < 6; j++)
        {
            cin >> cnt;
            gsum += cnt * g[j];
        }
        for (int j = 0; j < 7; j++)
        {
            cin >> cnt;
            ssum += cnt * s[j];
        }
        cout << "Battle " << i << ": ";
        if (gsum > ssum)
            cout << "Good triumphs over Evil\n";
        else if (gsum < ssum)
            cout << "Evil eradicates all trace of Good\n";
        else
            cout << "No victor on this battle field\n";
    }

    return 0;
}