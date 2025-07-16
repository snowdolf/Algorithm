#include <iostream>
#include <queue>

using namespace std;

int r, c, s, w;
char arr[255][255];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == '#') continue;
            while (!q.empty()) q.pop();

            int scnt = 0, wcnt = 0;

            q.push({i, j});
            if (arr[i][j] == 'k') scnt++;
            if (arr[i][j] == 'v') wcnt++;
            arr[i][j] = '#';

            while (!q.empty())
            {
                pair<int, int> qf = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int nx = qf.first + dx[k];
                    int ny = qf.second + dy[k];
                    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                    if (arr[nx][ny] == '#') continue;

                    q.push({nx, ny});
                    if (arr[nx][ny] == 'k') scnt++;
                    if (arr[nx][ny] == 'v') wcnt++;
                    arr[nx][ny] = '#';
                }
            }

            if (scnt > wcnt) s += scnt;
            else w += wcnt;
        }
    }

    cout << s << " " << w;

    return 0;
}