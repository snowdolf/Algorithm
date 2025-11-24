#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> house(n, vector<char>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> house[i][j];

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (house[i][j] == '.') continue;

            int x = i, y = j, dx = 0, dy = 0;

            if (house[i][j] == '-') dy++;
            else dx++;

            house[x][y] = '.';

            while (1)
            {
                x += dx, y += dy;
                if (x == n || y == m) break;

                if (dx)
                {
                    if (house[x][y] == '|') house[x][y] = '.';
                    else break;
                }

                if (dy)
                {
                    if (house[x][y] == '-') house[x][y] = '.';
                    else break;
                }
            }

            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}