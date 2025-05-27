#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)cin >> v[i];

    pair<int, int> ans = {INF, INF};
    for(int i = 0; i < n; i++){
        int idx = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
        if(idx >= 0 && idx < n && idx != i){
            if(abs(v[i] + v[idx]) < abs(ans.first + ans.second)){
                ans = {v[i], v[idx]};
            }
        }
        idx--;
        if(idx >= 0 && idx < n && idx != i){
            if(abs(v[i] + v[idx]) < abs(ans.first + ans.second)){
                ans = {v[i], v[idx]};
            }
        }
    }

    if(ans.first > ans.second)ans = {ans.second, ans.first};
    cout << ans.first << " " << ans.second;

    return 0;
}