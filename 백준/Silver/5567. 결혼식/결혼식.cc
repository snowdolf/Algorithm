#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, a, b, ans;
vector<int> vec[505];
queue<pair<int, int>> que;
bool chk[505];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    while(m--){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    que.push({1, 0});
    chk[1] = true;
    while(que.size()){
        pair<int, int> qf = que.front(); que.pop();
        for(auto i : vec[qf.first]){
            if(!chk[i] && qf.second < 2){
                que.push({i, qf.second + 1});
                chk[i] = true;
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}