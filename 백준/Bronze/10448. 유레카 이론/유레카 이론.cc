#include <iostream>

using namespace std;

int t, n, tn[1005][5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 1; i * (i + 1) / 2 <= 1000; i++){
        tn[i * (i + 1) / 2][1] = 1;
    }

    for (int i = 1; i <= 1000; i++)
    {
        if(!tn[i][1])continue;
        for (int j = 1; i + j <= 1000; j++)
        {
            if(!tn[j][1])continue;
            tn[i + j][2] = 1;
        }
    }

    for (int i = 1; i <= 1000; i++)
    {
        if(!tn[i][1])continue;
        for (int j = 1; i + j <= 1000; j++)
        {
            if(!tn[j][2])continue;
            tn[i + j][3] = 1;
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << tn[n][3] << "\n";
    }

    return 0;
}
