#include <iostream>
#include <queue>

using namespace std;

int n, m, chz[105][105], sum, ans;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> chz[i][j];
            if(chz[i][j] == 1) sum++;
        }
    }

    while(sum){
        ans++;

        while(!q.empty()) q.pop();
        chz[0][0] = -1;
        q.push({0, 0});
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(chz[nx][ny] == 0){
                    chz[nx][ny] = -1;
                    q.push({nx, ny});
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(chz[i][j] == 1){
                    int cnt = 0;
                    for(int k = 0; k < 4; k++){
                        int nx = i + dx[k], ny = j + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(chz[nx][ny] == -1) cnt++;
                    }
                    if(cnt >= 2){
                        chz[i][j] = 0;
                        sum--;
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(chz[i][j] == -1) chz[i][j] = 0;
            }
        }
    }

    cout << ans;

    return 0;
}