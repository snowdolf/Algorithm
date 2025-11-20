#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool chk1(vector<pair<int, int>> girls)
{
    vector<vector<int>> used(5, vector<int>(5, 0));

    for (auto [x, y] : girls)
    {
        used[x][y] = 1;
    }

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    queue<pair<int, int>> q;
    int cnt = 0;

    q.push(girls[0]);
    used[girls[0].first][girls[0].second] = 2;
    cnt++;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (used[nx][ny] != 1) continue;

            q.push({nx, ny});
            used[nx][ny] = 2;
            cnt++;
        }
    }

    return cnt == 7;
}

bool chk2(const vector<vector<char>> &board, vector<pair<int, int>> girls) 
{
    int s = 0;

    for (auto [x, y] : girls)
    {
        if (board[x][y] == 'S')
        {
            s++;
        }
    }

    return s >= 4;
}

void dfs(const vector<vector<char>> &board, vector<pair<int, int>> &girls, int idx, int *ans)
{
    if (girls.size() == 7)
    {
        if (chk1(girls) && chk2(board, girls))
        {
            (*ans)++;
        }
        return;
    }

    if (idx == 25)
    {
        return;
    }

    girls.push_back({idx / 5, idx % 5});
    dfs(board, girls, idx + 1, ans);

    girls.pop_back();
    dfs(board, girls, idx + 1, ans);

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> board(5, vector<char>(5));
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> board[i][j];
        }
    }

    int ans = 0;

    vector<pair<int, int>> girls;
    dfs(board, girls, 0, &ans);

    cout << ans << "\n";

    return 0;
}