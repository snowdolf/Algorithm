#include <iostream>

using namespace std;

int r, c, t, a[55][55], b[55][55], airCleaner;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            if(a[i][j] == -1){
                airCleaner = i;
            }
            b[i][j] = a[i][j];
        }
    }

    for(int i = 0; i < t; i++){
        // 미세먼지 확산
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                if(a[j][k] > 0){
                    int cnt = 0;
                    for(int l = 0; l < 4; l++){
                        int x = j + dx[l];
                        int y = k + dy[l];
                        if(x >= 0 && x < r && y >= 0 && y < c && a[x][y] != -1){
                            b[x][y] += a[j][k] / 5;
                            cnt++;
                        }
                    }
                    b[j][k] -= (a[j][k] / 5) * cnt;
                }
            }
        }

        // 공기청정기 작동
        for(int j = airCleaner - 1; j > 0; j--){
            b[j][0] = b[j - 1][0];
        }
        for(int j = 0; j < c - 1; j++){
            b[0][j] = b[0][j + 1];
        }
        for(int j = 0; j < airCleaner - 1; j++){
            b[j][c - 1] = b[j + 1][c - 1];
        }
        for(int j = c - 1; j > 0; j--){
            b[airCleaner - 1][j] = b[airCleaner - 1][j - 1];
        }
        b[airCleaner - 1][0] = -1;
        b[airCleaner - 1][1] = 0;

        for(int j = airCleaner; j < r - 1; j++){
            b[j][0] = b[j + 1][0];
        }
        for(int j = 0; j < c - 1; j++){
            b[r - 1][j] = b[r - 1][j + 1];
        }
        for(int j = r - 1; j > airCleaner; j--){
            b[j][c - 1] = b[j - 1][c - 1];
        }
        for(int j = c - 1; j > 0; j--){
            b[airCleaner][j] = b[airCleaner][j - 1];
        }
        b[airCleaner][0] = -1;
        b[airCleaner][1] = 0;

        // a 배열 갱신
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                a[j][k] = b[j][k];
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(a[i][j] > 0){
                ans += a[i][j];
            }
        }
    }
    cout << ans;

    return 0;
}