#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool cmp(pair<ll, int> x, pair<ll, int> y){
    if(x.first != y.first)return x.first > y.first;
    return x.second > y.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<pair<ll, int>> vec(n + 1);
        vector<ll> sum(n + 1, 0);

        for(int i = 1; i <= n; i++){
            cin >> vec[i].first;
            vec[i].second = i;
            sum[i] = sum[i - 1] + vec[i].first;
        }

        sort(vec.begin() + 1, vec.end(), cmp);

        int idx = 1;
        ll ans = 0;

        for(int i = 1; i <= n; i++){
            if(idx <= vec[i].second){
                ans += (vec[i].second - idx) * vec[i].first - (sum[vec[i].second - 1] - sum[idx - 1]);
                idx = vec[i].second + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}