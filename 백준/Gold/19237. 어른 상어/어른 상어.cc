#include <iostream>

using namespace std;

struct Cell{
    int smellNum, smellTime, sharkNum;
};

struct Shark{
    int x, y, curDir, priorDir[5][5];
    bool isDead = false;
};

int n, m, k, sharkCount, timeElapsed;
Cell grid[25][25];
Shark sharks[405];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void init(){
    cin >> n >> m >> k;
    sharkCount = m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j].sharkNum;
            if(grid[i][j].sharkNum){
                int sharkNum = grid[i][j].sharkNum;
                sharks[sharkNum].x = i;
                sharks[sharkNum].y = j;
                grid[i][j].smellNum = sharkNum;
                grid[i][j].smellTime = k;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        cin >> sharks[i].curDir;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= 4; j++){
            for(int d = 1; d <= 4; d++){
                cin >> sharks[i].priorDir[j][d];
            }
        }
    }
}

void moveShark(){
    for(int i = 1; i <= m; i++){
        if(sharks[i].isDead)continue;

        bool isMove = false;
        for(int d = 1; d <= 4; d++){
            int nx = sharks[i].x + dx[sharks[i].priorDir[sharks[i].curDir][d]];
            int ny = sharks[i].y + dy[sharks[i].priorDir[sharks[i].curDir][d]];

            if(nx < 1 || nx > n || ny < 1 || ny > n)continue;
            if(grid[nx][ny].smellTime)continue;

            sharks[i].x = nx;
            sharks[i].y = ny;
            sharks[i].curDir = sharks[i].priorDir[sharks[i].curDir][d];
            isMove = true;
            break;
        }

        if(isMove)continue;
        for(int d = 1; d <= 4; d++){
            int nx = sharks[i].x + dx[sharks[i].priorDir[sharks[i].curDir][d]];
            int ny = sharks[i].y + dy[sharks[i].priorDir[sharks[i].curDir][d]];

            if(nx < 1 || nx > n || ny < 1 || ny > n)continue;
            if(grid[nx][ny].smellNum != i)continue;

            sharks[i].x = nx;
            sharks[i].y = ny;
            sharks[i].curDir = sharks[i].priorDir[sharks[i].curDir][d];
            break;
        }
    }
}

void checkSharkNum(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            grid[i][j].sharkNum = 0;
        }
    }

    for(int i = 1; i <= m; i++){
        if(sharks[i].isDead)continue;
        if(grid[sharks[i].x][sharks[i].y].sharkNum){
            sharks[i].isDead = true;
            sharkCount--;
        }
        else grid[sharks[i].x][sharks[i].y].sharkNum = i;
    }
}

void spreadSharkSmell(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j].smellTime){
                grid[i][j].smellTime--;
            }
        }
    }

    for(int i = 1; i <= m; i++){
        if(sharks[i].isDead)continue;
        grid[sharks[i].x][sharks[i].y].smellNum = i;
        grid[sharks[i].x][sharks[i].y].smellTime = k;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    init();

    while(sharkCount != 1 && timeElapsed <= 1000){
        moveShark();
        checkSharkNum();
        spreadSharkSmell();
        timeElapsed++;
    }

    if(timeElapsed > 1000)timeElapsed = -1;
    cout << timeElapsed;

    return 0;
}