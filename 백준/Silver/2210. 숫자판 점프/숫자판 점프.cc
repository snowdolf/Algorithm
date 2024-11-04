#include <iostream>

using namespace std;

int map[5][5];
bool chk[1000000];

void dfs(int x, int y, int n, int k){
    if(k == 6){
        chk[n] = true;
        return;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for(int dir = 0; dir < 4; dir++){
        int nx = x + dx[dir], ny = y + dy[dir];
        if(0 <= nx && nx < 5 && 0 <= ny && ny < 5){
            dfs(nx, ny, 10 * n + map[nx][ny], k + 1);
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 5; i++)for(int j = 0; j < 5; j++)cin >> map[i][j];

    for(int i = 0; i < 5; i++)for(int j = 0; j < 5; j++)dfs(i, j, 0, 0);

    int ans = 0;
    for(int i = 0; i < 1000000; i++)if(chk[i])ans++;

    cout << ans;

    return 0;
}