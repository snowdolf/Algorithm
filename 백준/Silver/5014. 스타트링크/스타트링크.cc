#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int f, s, g, u, d;
vector<int> vec[1000010];
queue<pair<int, int>> que;
bool chk[1000010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> f >> s >> g >> u >> d;

    for(int i = 1; i <= f; i++){
        if(i + u <= f)vec[i].push_back(i + u);
        if(i - d >= 1)vec[i].push_back(i - d);
    }

    int ans = -1;

    que.push({s, 0});
    chk[s] = true;

    while(!que.empty()){
        pair<int, int> qf = que.front(); que.pop();
        if(qf.first == g){
            ans = qf.second;
            break;
        }
        for(auto i : vec[qf.first]){
            if(chk[i])continue;
            que.push({i, qf.second + 1});
            chk[i] = true;
        }
    }

    if(ans >= 0)cout << ans;
    else cout << "use the stairs";

    return 0;
}