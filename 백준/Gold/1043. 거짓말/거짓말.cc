#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, a, b, ans;
bool known[55], chk;
vector<int> party[55], vec[55];
queue<int> que;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    
    while(k--){
        cin >> a;
        que.push(a);
        known[a] = true;
    }

    for(int i = 0; i < m; i++){
        cin >> k >> a;
        party[i].push_back(a);
        while(--k){
            cin >> b;
            party[i].push_back(b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
    }

    while(!que.empty()){
        int qf = que.front();
        que.pop();
        for(auto i : vec[qf]){
            if(known[i])continue;
            que.push(i);
            known[i] = true;
        }
    }

    for(int i = 0; i < m; i++){
        chk = true;
        for(auto j : party[i]){
            if(known[j]){
                chk = false;
                break;
            }
        }
        if(chk)ans++;
    }
    
    cout << ans;

    return 0;
}