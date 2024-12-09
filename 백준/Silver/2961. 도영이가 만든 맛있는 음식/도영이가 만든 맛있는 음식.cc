#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<pair<int, int>> taste;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    taste.resize(n);

    for(int i = 0; i < n; i++){
        cin >> taste[i].first >> taste[i].second;
    }

    int ans = 1e9;

    for(int i = 1; i < (1 << n); i++){
        int a = 1, b = 0;

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                a *= taste[j].first;
                b += taste[j].second;
            }
        }

        ans = min(ans, abs(a - b));
    }

    cout << ans;

    return 0;
}