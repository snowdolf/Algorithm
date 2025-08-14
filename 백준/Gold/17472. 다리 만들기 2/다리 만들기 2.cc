#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            map[i][j]--;
        }
    }

    queue<pair<int, int>> q;

    int islandNum = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = islandNum;
                q.push({i, j});

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dx = -1; dx <= 1; dx++)
                    {
                        for (int dy = -1; dy <= 1; dy++)
                        {
                            if (abs(dx) + abs(dy) != 1) continue;
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (map[nx][ny] == 0)
                            {
                                map[nx][ny] = islandNum;
                                q.push({nx, ny});
                            }
                        }
                    }
                }

                islandNum++;
            }
        }
    }
    islandNum--;

    vector<vector<int>> dist(islandNum + 1, vector<int>(islandNum + 1, 1e5));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] > 0)
            {
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (abs(dx) + abs(dy) != 1) continue;
                        for (int k = 1;; k++)
                        {
                            int nx = i + dx * k;
                            int ny = j + dy * k;
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;

                            if (map[nx][ny] == map[i][j]) break;
                            else if (map[nx][ny] > 0)
                            {
                                if (k >= 3)
                                {
                                    dist[map[nx][ny]][map[i][j]] = min(dist[map[nx][ny]][map[i][j]], k - 1);
                                    dist[map[i][j]][map[nx][ny]] = min(dist[map[i][j]][map[nx][ny]], k - 1);
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    vector<bool> visited(islandNum + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ans += d;

        for (int v = 1; v <= islandNum; v++)
        {
            if (!visited[v])
            {
                pq.push({dist[u][v], v});
            }
        }
    }

    if (ans >= 1e5) ans = -1;
    cout << ans << '\n';

    return 0;
}