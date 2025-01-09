#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, ans;

bool cmp(const int &a, const int  &b){
    return a > b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++)cin >> vec[i];
    sort(vec.begin(), vec.end());

    vector<int> dist;
    for(int i = 0; i < n - 1; i++)dist.push_back(vec[i + 1] - vec[i]);
    sort(dist.begin(), dist.end(), cmp);

    ans = vec.back() - vec.front();

    for(int i = 0; i < min(n, k) - 1; i++)ans -= dist[i];

    cout << ans;

    return 0;
}