#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

pair<int, int> arr[500005], brr[500005];
ll n, ans, bit[500005], idx[500005];

long long sum(int i){
    long long res = 0;
    while(i > 0){
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += i & -i;
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> brr[i].first;
        brr[i].second = i;
    }

    sort(arr + 1, arr + n + 1);
    sort(brr + 1, brr + n + 1);

    for(int i = 1; i <= n; i++){
        idx[arr[i].second] = brr[i].second;
    }

    for(int i = 1; i <= n; i++){
        add(idx[i], 1);
        ans += i - sum(idx[i]);
    }

    cout << ans;

    return 0;
}
