#include <iostream>
#include <queue>

using namespace std;

int n, k;
pair<int, int> dp[140010]; // { 최단 시간, 경우의 수 }
queue<pair<int, int>> que; // { 시간, 위치 }

void init(){
    for(int i = 0; i < 140000; i++){
        dp[i] = {-1, 0};
    }
    dp[n] = {0, 1};
}

void bfs(){
    que.push({0, n});
    while(!que.empty()){
        pair<int, int> qf = que.front();
        que.pop();

        if(dp[k].second && dp[k].first < qf.first)break;

        int pos[] = {qf.second - 1, qf.second + 1, 2 * qf.second};

        for(auto i : pos){
            if(i < 0 || i >= 140000)continue;

            // 처음 방문
            if(dp[i].first == -1){
                dp[i] = {qf.first + 1, dp[qf.second].second};
                que.push({qf.first + 1, i});
            }
            // 같은 시간에 방문
            else if(dp[i].first == qf.first + 1){
                dp[i].second += dp[qf.second].second;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    init();

    if(n != k)bfs();

    cout << dp[k].first << "\n" << dp[k].second;

    return 0;
}