#include <iostream>
#include <queue>

using namespace std;

int n, m, a, b;
int map[1005][1005];
int ans[1005][1005];
bool chk[1005][1005];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                a = i;
                b = j;
            }
            if (map[i][j] == 1)
                ans[i][j] = -1;
        }

    ans[a][b] = 0;
    chk[a][b] = true;
    q.push({a, b});

    while (!q.empty())
    {
        pair<int, int> qf = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> np = {qf.first + dx[i], qf.second + dy[i]};
            if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m)
                continue;
            if (!map[np.first][np.second])
                continue;
            if (chk[np.first][np.second])
                continue;
            ans[np.first][np.second] = ans[qf.first][qf.second] + 1;
            chk[np.first][np.second] = true;
            q.push(np);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}