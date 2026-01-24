#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int time = 0, count = 0, last = 0;

    vector<vector<int>> cheeze(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cheeze[i][j];
            if (cheeze[i][j] == 1)
            {
                count++;
                last++;
            }
        }
    }

    while (count > 0)
    {
        vector<vector<bool>> check(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> que;

        que.push({0, 0});
        check[0][0] = true;
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            for (auto [dx, dy] : directions)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny])
                {
                    continue;
                }

                if (cheeze[nx][ny] == 1)
                {
                    cheeze[nx][ny] = 2;
                }
                else if (cheeze[nx][ny] == 0)
                {
                    que.push({nx, ny});
                    check[nx][ny] = true;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (cheeze[i][j] == 2)
                {
                    cheeze[i][j] = 0;
                    count--;
                }
            }
        }

        time++;
        if (count > 0)
        {
            last = count;
        }
    }

    cout << time << "\n" << last << "\n";

    return 0;
}