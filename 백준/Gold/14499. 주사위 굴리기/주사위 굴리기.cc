#include <iostream>

using namespace std;

int n, m, x, y, k;
int arr[25][25], dice[6] = {0, 0, 0, 0, 0, 0};
// dice[] = { 위, 북, 동, 서, 남, 아래 }
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
//  d_[5] = {_, 동, 서, 북, 남};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cin >> arr[i][j];
    while(k--){
        int dir, cnt;
        cin >> dir;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;

        switch (dir)
        {
        case 1:
            // 동
            cnt = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = cnt;
            break;
        case 2:
            // 서
            cnt = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = cnt;
            break;
        case 3:
            // 북
            cnt = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = cnt;
            break;
        case 4:
            // 남
            cnt = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = cnt;
            break;
        default:
            break;
        }

        x = nx;
        y = ny;

        if(!arr[x][y])arr[x][y] = dice[5];
        else{
            dice[5] = arr[x][y];
            arr[x][y] = 0;
        }

        cout << dice[0] << "\n";
    }

    return 0;
}