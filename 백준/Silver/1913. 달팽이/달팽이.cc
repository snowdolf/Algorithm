#include <iostream>

using namespace std;

int n, m, snail[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int center = n / 2;
    snail[center][center] = 1;

    int cnt = 2;
    for (int layer = 1; layer <= center; layer++)
    {
        int x = center - layer, y = center - layer;
        for (int dir = 0; dir < 4; dir++)
        {
            for (int step = 1; step <= 2 * layer; step++)
            {
                x += dx[dir], y += dy[dir];
                snail[x][y] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << snail[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (snail[i][j] == m)
            {
                cout << i + 1 << " " << j + 1 << "\n";
                return 0;
            }
        }
    }

    return 0;
}