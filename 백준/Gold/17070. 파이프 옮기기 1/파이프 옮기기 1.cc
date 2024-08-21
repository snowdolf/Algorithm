#include <iostream>

using namespace std;

int n, dt[16][16][4];
// dt[i][j][0] : 입력
// dt[i][j][1] : 가로
// dt[i][j][2] : 세로
// dt[i][j][3] : 대각선

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)cin >> dt[i][j][0];

    for(int i = 1; i < n; i++){
        if(dt[0][i][0])break;
        dt[0][i][1] = 1;
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            if(!dt[i][j][0]){
                dt[i][j][1] = dt[i][j - 1][1] + dt[i][j - 1][3];
            }
            if(!dt[i][j][0]){
                dt[i][j][2] = dt[i - 1][j][2] + dt[i - 1][j][3];
            }
            if(!dt[i][j][0] && !dt[i - 1][j][0] && !dt[i][j - 1][0]){
                dt[i][j][3] = dt[i - 1][j - 1][1] + dt[i - 1][j - 1][2] + dt[i - 1][j - 1][3];
            }
        }
    }

    cout << dt[n - 1][n - 1][1] + dt[n - 1][n - 1][2] + dt[n - 1][n - 1][3];

    return 0;
}