#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s, m;
vector<int> vol;
vector<bool> cur, nxt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s >> m;

    vol.resize(n + 1);
    cur.resize(m + 1, false);
    nxt.resize(m + 1, false);

    for(int i = 1; i <= n; i++)cin >> vol[i];

    cur[s] = true;

    for(int i = 1; i <= n; i++){
        fill(nxt.begin(), nxt.end(), false);

        for(int j = 0; j <= m; j++){
            if(cur[j]){
                if((j + vol[i]) <= m){
                    nxt[j + vol[i]] = true;
                }
                if((j - vol[i]) >= 0){
                    nxt[j - vol[i]] = true;
                }
            }
        }

        swap(cur, nxt);
    }

    int ans = -1;
    for(int i = m; i >= 0; i--){
        if(cur[i]){
            ans = i;
            break;
        }
    }

    cout << ans;

    return 0;
}