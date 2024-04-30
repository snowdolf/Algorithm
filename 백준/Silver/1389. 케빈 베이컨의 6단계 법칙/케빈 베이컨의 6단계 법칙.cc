#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a, b, d[105][105];
int INF = 10000;
int cnt, sum, ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = INF;
    for (int i = 0; i < n; i++)
        d[i][i] = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        d[a - 1][b - 1] = min(d[a - 1][b - 1], 1);
        d[b - 1][a - 1] = min(d[b - 1][a - 1], 1);
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    sum = INF;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += d[i][j];
        if (sum > cnt)
        {
            sum = cnt;
            ans = i + 1;
        }
    }

    cout << ans;

    return 0;
}