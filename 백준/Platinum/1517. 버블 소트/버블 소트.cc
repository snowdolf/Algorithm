#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

pair<int, int> a[500005];
ll n, ans, bit[500005], aIndex[500005];

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
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        aIndex[a[i].second] = i;
    }

    for(int i = 1; i <= n; i++){
        add(aIndex[i], 1);
        ans += i - sum(aIndex[i]);
    }

    cout << ans;

    return 0;
}
