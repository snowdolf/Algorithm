#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int countIce(vector<vector<int>> ice)
{
    int count = 0;

    vector<vector<bool>> visited(ice.size(), vector<bool>(ice[0].size(), false));

    for (int i = 0; i < ice.size(); i++)
    {
        for (int j = 0; j < ice[0].size(); j++)
        {
            if (ice[i][j] == 0 || visited[i][j]) continue;

            queue<pair<int, int>> q;

            q.push({i, j});
            visited[i][j] = true;

            while (!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();

                int dx[4] = {1, -1, 0, 0};
                int dy[4] = {0, 0, 1, -1};

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx < 0 || nx >= ice.size() || ny < 0 || ny >= ice[0].size()) continue;
                    if (ice[nx][ny] == 0 || visited[nx][ny]) continue;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }

            count++;
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> ice(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
        }
    }

    int year = 0;

    while (true)
    {
        int cnt = countIce(ice);
        if (cnt == 0)
        {
            cout << 0 << "\n";
            break;
        }
        if (cnt >= 2)
        {
            cout << year << "\n";
            break;
        }

        vector<vector<int>> melt(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ice[i][j] == 0) continue;

                int dx[4] = {-1, 1, 0, 0};
                int dy[4] = {0, 0, -1, 1};

                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (ice[nx][ny] == 0)
                    {
                        melt[i][j]++;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ice[i][j] = max(0, ice[i][j] - melt[i][j]);
            }
        }

        year++;
    }

    return 0;
}