#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());

    double ans = 0.0;
    for (auto x : v) ans += (x / 2.0);
    ans += (v.back() / 2.0);

    cout << ans;

    return 0;
}