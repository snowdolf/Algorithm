#include <iostream>

using namespace std;

struct shark
{
    int s, d, z;
};

int r, c, m, ans;
shark sh[105][105];
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

void catchShark(int t){
    for(int i = 1; i <= r; i++){
        if(sh[i][t].z){
            ans += sh[i][t].z;
            sh[i][t] = {0, 0 ,0};
            break;
        }
    }
    return;
}

void moveShark(){
    shark sh2[105][105];
    for(int i = 1; i <= r; i++)for(int j = 1; j <= c; j++)sh2[i][j] = {0, 0 ,0};

    for(int i = 1; i <= r; i++)for(int j = 1; j <= c; j++){
        if(sh[i][j].z){
            int nx, ny, nd;
            nx = i + dx[sh[i][j].d] * sh[i][j].s;
            ny = j + dy[sh[i][j].d] * sh[i][j].s;
            nd = sh[i][j].d;

            while(1){
                if(nx < 1){
                    nx = 2 - nx;
                    nd = 2;
                }
                else if(nx > r){
                    nx = 2 * r - nx;
                    nd = 1;
                }
                else if(ny < 1){
                    ny = 2 - ny;
                    nd = 3;
                }
                else if(ny > c){
                    ny = 2 * c - ny;
                    nd = 4;
                }
                else{
                    break;
                }
            }

            if(sh2[nx][ny].z < sh[i][j].z)sh2[nx][ny] = {sh[i][j].s, nd, sh[i][j].z};
        }
    }

    for(int i = 1; i <= r; i++)for(int j = 1; j <= c; j++)sh[i][j] = sh2[i][j];

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        cin >> sh[x][y].s >> sh[x][y].d >> sh[x][y].z;
    }

    for(int i = 1; i <= c; i++){
        catchShark(i);
        moveShark();
    }

    cout << ans;

    return 0;
}
