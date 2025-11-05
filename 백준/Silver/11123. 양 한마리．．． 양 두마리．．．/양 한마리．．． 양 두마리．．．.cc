#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, h, w;
    cin >> t;

    while (t--)
    {
        cin >> h >> w;
        vector<vector<char>> grid(h, vector<char>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> grid[i][j];
            }
        }

        int ans = 0;

        queue<pair<int, int>> que;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (grid[i][j] == '#')
                {
                    que.push({i, j});
                    grid[i][j] = '.';
                    ans++;

                    while (!que.empty())
                    {
                        auto [x, y] = que.front();
                        que.pop();

                        int dx[4] = {1, -1, 0, 0};
                        int dy[4] = {0, 0, 1, -1};

                        for (int dir = 0; dir < 4; dir++)
                        {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];

                            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == '#')
                            {
                                que.push({nx, ny});
                                grid[nx][ny] = '.';
                            }
                        }
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}