#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, k, dt[100010];
set<int> s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= k; i++)dt[i] = 100000;

    for(int i = 0; i < n; i++){
        int cnt;
        cin >> cnt;
        s.insert(cnt);
        dt[cnt] = 1;
    }

    for(int i = 1; i <= k; i++){
        for(auto j : s){
            if(i <= j)continue;
            if(dt[i - j] == 100000)continue;
            dt[i] = min(dt[i], dt[i - j] + 1);
        }
    }

    if(dt[k] == 100000)cout << "-1";
    else cout << dt[k];

    return 0;
}
