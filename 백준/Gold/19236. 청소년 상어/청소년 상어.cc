#include <iostream>
#include <algorithm>

using namespace std;

struct Fish
{
    int num, dir;
};

Fish map[4][4];
int ans;
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void h(int x, int y)
{
    map[x][y].dir--;
    while (true)
    {
        map[x][y].dir++;
        if (map[x][y].dir > 8)
            map[x][y].dir = 1;

        int nx = x + dx[map[x][y].dir];
        int ny = y + dy[map[x][y].dir];

        if (nx < 0 || nx > 3 || ny < 0 || ny > 3)
            continue;
        if (map[nx][ny].num == -1)
            continue;

        Fish cnt = map[x][y];
        map[x][y] = map[nx][ny];
        map[nx][ny] = cnt;

        break;
    }
    return;
}

void g(int tar)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j].num == tar)
            {
                h(i, j);
                return;
            }
        }
    }
    return;
}

void f(int x, int sum)
{
    if (x == 16)
        return;

    for (int i = 1; i <= 16; i++)
        g(i);

    int sx, sy;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j].num == -1)
            {
                sx = i;
                sy = j;
            }
        }
    }

    Fish map2[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map2[i][j] = map[i][j];
        }
    }

    Fish shark = map[sx][sy];
    for (int i = 1; i <= 3; i++)
    {
        int dIdx = map[sx][sy].dir;
        int nx = sx + i * dx[dIdx];
        int ny = sy + i * dy[dIdx];

        if (nx < 0 || nx > 3 || ny < 0 || ny > 3)
            break;
        if (map[nx][ny].num == 0)
            continue;

        Fish cnt = map[nx][ny];

        map[sx][sy] = {0, 0};
        map[nx][ny].num = -1;
        ans = max(ans, sum + cnt.num);

        f(x + 1, sum + cnt.num);

        for (int p = 0; p < 4; p++)
        {
            for (int q = 0; q < 4; q++)
            {
                map[p][q] = map2[p][q];
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> map[i][j].num >> map[i][j].dir;
        }
    }

    ans = map[0][0].num;
    map[0][0].num = -1;

    f(1, ans);

    cout << ans;

    return 0;
}