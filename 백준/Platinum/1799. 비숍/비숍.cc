#include <iostream>
#include <vector>

using namespace std;

int n, blackCount, whiteCount;
vector<vector<int>> board;
bool diag1[20], diag2[20];

void dfs(int x, int y, int cnt, bool isBlack)
{
    if (y >= n)
    {
        x++;
        y = (x % 2 == (isBlack ? 0 : 1)) ? 0 : 1;
    }
    if (x >= n)
    {
        if (isBlack) blackCount = max(blackCount, cnt);
        else whiteCount = max(whiteCount, cnt);
        return;
    }
    if (board[x][y] && !diag1[x + y] && !diag2[x + (n - 1) - y])
    {
        diag1[x + y] = diag2[x + (n - 1) - y] = true;
        dfs(x, y + 2, cnt + 1, isBlack);
        diag1[x + y] = diag2[x + (n - 1) - y] = false;
    }
    dfs(x, y + 2, cnt, isBlack);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0, 1);
    dfs(0, 1, 0, 0);
    cout << blackCount + whiteCount;

    return 0;
}