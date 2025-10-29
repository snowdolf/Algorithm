#include <iostream>

using namespace std;

int n;
bool chk1[55][55], chk2[55][55];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == 'Y')
            {
                chk1[i][j] = chk1[j][i] = true;
                chk2[i][j] = chk2[j][i] = true;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (!chk1[i][j]) continue;
            for (int k = 0; k < n; k++)
            {
                if (k == i) continue;
                if (chk1[j][k])
                {
                    chk2[i][k] = chk2[k][i] = true;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (chk2[i][j]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
} 