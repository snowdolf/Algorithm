#include <iostream>
#include <queue>

using namespace std;

struct Cell
{
    int cnt, rx, ry, bx, by, dir;
};

int n, m, rx, ry, bx, by;
char board[15][15];
string str;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool chk[15][15][15][15];

queue<Cell> que;

bool move(int &x, int &y, int dir, bool &goal)
{
    while (true)
    {
        x += dx[dir];
        y += dy[dir];
        if (board[x][y] == 'O')
        {
            goal = true;
            return true;
        }
        if (board[x][y] == '#')
        {
            x -= dx[dir];
            y -= dy[dir];
            return false;
        }
    }
}

bool isPriorRed(int rx, int ry, int bx, int by, int dir)
{
    if (dir == 0 && ry == by && rx < bx)
        return true;
    if (dir == 1 && ry == by && rx > bx)
        return true;
    if (dir == 2 && rx == bx && ry < by)
        return true;
    if (dir == 3 && rx == bx && ry > by)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for (int j = 0; j < m; j++)
        {
            board[i][j] = str[j];
            if (board[i][j] == 'R')
                rx = i, ry = j, board[i][j] = '.';
            if (board[i][j] == 'B')
                bx = i, by = j, board[i][j] = '.';
        }
    }

    chk[rx][ry][bx][by] = true;
    que.push({0, rx, ry, bx, by, -1});
    while (!que.empty())
    {
        Cell qf = que.front();
        que.pop();

        for (int i = 0; i < 4; i++)
        {
            if(qf.dir != -1 && qf.dir < 2 && i < 2)continue;
            if(qf.dir != -1 && qf.dir > 1 && i > 1)continue;

            bool isRedFirst = isPriorRed(qf.rx, qf.ry, qf.bx, qf.by, i);
            bool isRedGoal = false, isBlueGoal = false;

            int nrx = qf.rx, nry = qf.ry, nbx = qf.bx, nby = qf.by;

            if (isRedFirst)
            {
                move(nrx, nry, i, isRedGoal);
                move(nbx, nby, i, isBlueGoal);
                if (nrx == nbx && nry == nby && !isBlueGoal)
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            else
            {
                move(nbx, nby, i, isBlueGoal);
                move(nrx, nry, i, isRedGoal);
                if (nrx == nbx && nry == nby && !isRedGoal)
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
            }

            if (isRedGoal && !isBlueGoal)
            {
                cout << qf.cnt + 1;
                return 0;
            }

            if(chk[nrx][nry][nbx][nby])continue;

            if (!isBlueGoal && (qf.rx != nrx || qf.ry != nry || qf.bx != nbx || qf.by != nby))
            {
                chk[nrx][nry][nbx][nby] = true;
                que.push({qf.cnt + 1, nrx, nry, nbx, nby, i});
            }
        }
    }

    cout << "-1";
    return 0;
}
