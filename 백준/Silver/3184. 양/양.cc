#include <iostream>
#include <queue>

using namespace std;

int r, c, s, w;
char yard[255][255];

void bfs(int x, int y){
    if(yard[x][y] == '#')return;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int sheep = yard[x][y] == 'o' ? 1 : 0;
    int wolf  = yard[x][y] == 'v' ? 1 : 0;

    queue<pair<int, int>> que;

    que.push({x, y});
    yard[x][y] = '#';

    while(que.size()){
        pair<int, int> p = que.front(); que.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = p.first + dx[dir], ny = p.second + dy[dir];
            if(0 <= nx && nx < r && 0 <= ny && ny < c && yard[nx][ny] != '#'){
                if(yard[nx][ny] == 'o')sheep++;
                if(yard[nx][ny] == 'v')wolf++;
                que.push({nx, ny});
                yard[nx][ny] = '#';
            }
        }
    }

    if(sheep && sheep > wolf)s += sheep;
    if(wolf && wolf >= sheep)w += wolf;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)for(int j = 0; j < c; j++)cin >> yard[i][j];

    for(int i = 0; i < r; i++)for(int j = 0; j < c; j++)bfs(i, j);

    cout << s << " " << w;

    return 0;
}