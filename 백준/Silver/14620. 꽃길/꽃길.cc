#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(int x, int y, const vector<vector<bool>> &visited)
{
    if (visited[x][y] || visited[x - 1][y] || visited[x + 1][y] || visited[x][y - 1] || visited[x][y + 1])
    {
        return false;
    }
    return true;
}

void f(int x, int y, int n, int m, const vector<vector<int>> &g, vector<vector<bool>> &visited, int &ans)
{
    if (m == 3)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                {
                    sum += g[i][j];
                }
            }
        }
        ans = min(ans, sum);
        return;
    }

    if (x >= n - 1) return;

    if (isValid(x, y, visited))
    {
        visited[x][y] = visited[x - 1][y] = visited[x + 1][y] = visited[x][y - 1] = visited[x][y + 1] = true;
        if (y < n - 2)
        {
            f(x, y + 1, n, m + 1, g, visited, ans);
        }
        else
        {
            f(x + 1, 1, n, m + 1, g, visited, ans);
        }
        visited[x][y] = visited[x - 1][y] = visited[x + 1][y] = visited[x][y - 1] = visited[x][y + 1] = false;
    }

    if (y < n - 2)
    {
        f(x, y + 1, n, m, g, visited, ans);
    }
    else
    {
        f(x + 1, 1, n, m, g, visited, ans);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }

    int ans = 2000000;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    f(1, 1, n, 0, g, visited, ans);

    cout << ans;

    return 0;
}