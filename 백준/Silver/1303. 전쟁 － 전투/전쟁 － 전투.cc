#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> war(m);
    for(int i = 0; i < m; i++)cin >> war[i];

    int w = 0, b = 0;
    vector<vector<bool>> chk(m, vector<bool>(n, false));
    pair<int, int> dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!chk[i][j]){
                int cnt = 0;
                queue<pair<int, int>> que;

                que.push({i, j});
                chk[i][j] = true;
                cnt++;
                while(!que.empty()){
                    pair<int, int> qf = que.front();
                    que.pop();

                    for(int k = 0; k < 4; k++){
                        pair<int, int> p = {qf.first + dir[k].first, qf.second + dir[k].second};
                        if(p.first < 0 || p.first >= m || p.second < 0 || p.second >= n)continue;
                        if(chk[p.first][p.second])continue;
                        if(war[i][j] != war[p.first][p.second])continue;
                        que.push(p);
                        chk[p.first][p.second] = true;
                        cnt++;
                    }
                }

                if(war[i][j] == 'W')w += cnt * cnt;
                if(war[i][j] == 'B')b += cnt * cnt;
            }
        }
    }

    cout << w << " " << b;

    return 0;
}