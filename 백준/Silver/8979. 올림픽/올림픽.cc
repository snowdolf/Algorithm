#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cty
{
    int g, s, b, idx;
};

bool cmp(Cty x, Cty y){
    if(x.g > y.g)return true;
    else if(x.g == y.g){
        if(x.s > y.s)return true;
        else if(x.s == y.s){
            if(x.b > y.b)return true;
        }
    }
    return false;
}

int n, k, ans;
vector<Cty> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    v.resize(n);
    for(int i = 0; i < n; i++)cin >> v[i].idx >> v[i].g >> v[i].s >> v[i].b;

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        if(v[i].idx == k){
            ans = i;
            break;
        }
    }

    for(int i = ans - 1; i >= 0; i--){
        if(v[i].g == v[ans].g && v[i].s == v[ans].s && v[i].b == v[ans].b)ans--;
        else break;
    }

    cout << ans + 1;

    return 0;
}