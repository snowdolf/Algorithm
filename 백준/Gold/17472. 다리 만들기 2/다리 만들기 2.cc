#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y;
};

const int INF = 1e5;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

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
    int islandCount = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                map[i][j] = ++islandCount;
                q.push({i, j});

                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                        if (map[nx][ny] == 0)
                        {
                            map[nx][ny] = islandCount;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    vector<vector<int>> dist(islandCount + 1, vector<int>(islandCount + 1, INF));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] > 0)
            {
                int u = map[i][j];
                for (int dir = 0; dir < 4; dir++)
                {
                    for (int k = 1;; k++)
                    {
                        int nx = i + dx[dir] * k;
                        int ny = j + dy[dir] * k;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) break;

                        int v = map[nx][ny];
                        if (v == u) break;
                        if (v > 0)
                        {
                            if (k - 1 >= 2)
                            {
                                dist[u][v] = min(dist[u][v], k - 1);
                                dist[v][u] = min(dist[v][u], k - 1);
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    vector<bool> visited(islandCount + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int ans = 0;
    int visitedCount = 0;

    pq.push({0, 1});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        ans += d;
        visitedCount++;

        for (int v = 1; v <= islandCount; v++)
        {
            if (!visited[v] && dist[u][v] < INF)
            {
                pq.push({dist[u][v], v});
            }
        }
    }

    if (visitedCount < islandCount) ans = -1;
    cout << ans << '\n';

    return 0;
}