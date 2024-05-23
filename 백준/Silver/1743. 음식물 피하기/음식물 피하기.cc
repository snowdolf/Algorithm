#include <iostream>
#include <queue>

using namespace std;

int n, m, k, r, c, res, cnt;
int map[105][105];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c;
        map[r][c] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!map[i][j])
                continue;

            cnt = 1;
            map[i][j] = 0;
            que.push({i, j});

            while (!que.empty())
            {
                pair<int, int> qf = que.front();
                que.pop();

                for (int l = 0; l < 4; l++)
                {
                    pair<int, int> np = {qf.first + dx[l], qf.second + dy[l]};
                    if (np.first < 1 || np.first > n || np.second < 1 || np.second > m)
                        continue;
                    if (!map[np.first][np.second])
                        continue;

                    cnt++;
                    map[np.first][np.second] = 0;
                    que.push(np);
                }
            }

            res = res < cnt ? cnt : res;
        }
    }

    cout << res;

    return 0;
}