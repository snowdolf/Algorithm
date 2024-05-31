#include <iostream>
#include <algorithm>

using namespace std;

int n, dt[22][22], arr[22];
int res = 400, cnt, sum;
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            dt[i][j] = str[j] == 'T' ? 1 : 0;
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[j] = i & (1 << j) ? 1 : 0;
        }

        sum = 0;
        for (int j = 0; j < n; j++)
        {
            cnt = 0;
            for (int k = 0; k < n; k++)
            {
                cnt += arr[k] ? 1 - dt[k][j] : dt[k][j];
            }
            sum += min(cnt, n - cnt);
        }
        res = min(res, sum);
    }

    cout << res;

    return 0;
}