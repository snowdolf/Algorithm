#include <iostream>
#include <queue>

using namespace std;

struct cell
{
    int cnt, rx, ry, bx, by;
};


int n, m, rx, ry, bx, by;
char board[15][15];
string str;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool isRedFirst, isRedGoal, isBlueGoal;

queue<cell> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < m; j++){
            board[i][j] = str[j];
            if(board[i][j] == 'R')rx = i, ry = j, board[i][j] = '.';
            if(board[i][j] == 'B')bx = i, by = j, board[i][j] = '.';
        }
    }

    que.push({0, rx, ry, bx, by});
    while(!que.empty()){
        cell qf = que.front();
        que.pop();

        if(qf.cnt == 10)break;
        for(int i = 0; i < 4; i++){
            isRedFirst = false;
            isRedGoal = false;
            isBlueGoal = false;

            if(i == 0 && qf.ry == qf.by && qf.rx < qf.bx)isRedFirst = true;
            if(i == 1 && qf.ry == qf.by && qf.rx > qf.bx)isRedFirst = true;
            if(i == 2 && qf.rx == qf.bx && qf.ry < qf.by)isRedFirst = true;
            if(i == 3 && qf.rx == qf.bx && qf.ry > qf.by)isRedFirst = true;

            int nrx = qf.rx, nry = qf.ry, nbx = qf.bx, nby = qf.by;

            if(isRedFirst){
                while(!isRedGoal){
                    nrx += dx[i];
                    nry += dy[i];
                    if(board[nrx][nry] == 'O'){
                        isRedGoal = true;
                    }
                    else if(board[nrx][nry] == '#'){
                        nrx -= dx[i];
                        nry -= dy[i];
                        break;
                    }
                }
                while(!isBlueGoal){
                    nbx += dx[i];
                    nby += dy[i];
                    if(board[nbx][nby] == 'O'){
                        isBlueGoal = true;
                    }
                    else if(board[nbx][nby] == '#' || (nrx == nbx && nry == nby)){
                        nbx -= dx[i];
                        nby -= dy[i];
                        break;
                    }
                }
            }
            else{
                while(!isBlueGoal){
                    nbx += dx[i];
                    nby += dy[i];
                    if(board[nbx][nby] == 'O'){
                        isBlueGoal = true;
                    }
                    else if(board[nbx][nby] == '#'){
                        nbx -= dx[i];
                        nby -= dy[i];
                        break;
                    }
                }
                while(!isRedGoal){
                    nrx += dx[i];
                    nry += dy[i];
                    if(board[nrx][nry] == 'O'){
                        isRedGoal = true;
                    }
                    else if(board[nrx][nry] == '#' || (nrx == nbx && nry == nby)){
                        nrx -= dx[i];
                        nry -= dy[i];
                        break;
                    }
                }
            }

            if(qf.rx == nrx && qf.ry == nry && qf.bx == nbx && qf.by == nby)continue;

            if(isRedGoal && !isBlueGoal){
                cout << "1";
                return 0;
            }
            else if(!isBlueGoal)que.push({qf.cnt + 1, nrx, nry, nbx, nby});
        }
    }

    cout << "0";

    return 0;
}