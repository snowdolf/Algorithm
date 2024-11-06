#include <iostream>
#include <vector>

using namespace std;

int ans, bingo;
vector<vector<int>> board(5, vector<int>(5, 0)), ord(5, vector<int>(5, 0));
vector<vector<bool>> chk(5, vector<bool>(5, false));

void checkBingo(int x, int y)
{
    bool row = true, col = true, diag1 = true, diag2 = true;

    for (int i = 0; i < 5; i++)
    {
        if (!chk[x][i])
            row = false;
        if (!chk[i][y])
            col = false;
        if (!chk[i][i] || x != y)
            diag1 = false;
        if (!chk[i][4 - i] || x + y != 4)
            diag2 = false;
    }

    if (row)
        bingo++;
    if (col)
        bingo++;
    if (diag1)
        bingo++;
    if (diag2)
        bingo++;

    return;
}

void checkNumber(int num)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (board[i][j] == num && !chk[i][j])
            {
                chk[i][j] = true;
                checkBingo(i, j);
                break;
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> ord[i][j];

    for (; ans < 25 && bingo < 3; ans++)
        checkNumber(ord[ans / 5][ans % 5]);

    cout << ans;

    return 0;
}