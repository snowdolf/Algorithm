#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, arr[505][505], a, b;
queue<pair<int, int>> que;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int cnt = 0;
            if (!arr[i][j])
                continue;
            while (!que.empty())
                que.pop();

            que.push({i, j});
            arr[i][j] = 0;
            cnt++;

            while (!que.empty())
            {
                pair<int, int> qf = que.front();
                que.pop();

                for (int k = 0; k < 4; k++)
                {
                    pair<int, int> np = {qf.first + dx[k], qf.second + dy[k]};
                    if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m)
                        continue;
                    if (!arr[np.first][np.second])
                        continue;

                    que.push(np);
                    arr[np.first][np.second] = 0;
                    cnt++;
                }
            }

            a++;
            b = max(b, cnt);
        }

    cout << a << "\n"
         << b;

    return 0;
}