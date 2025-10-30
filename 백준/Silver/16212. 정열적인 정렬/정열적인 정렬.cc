#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (auto &x : v) cin >> x;
    sort(v.begin(), v.end());
    for (auto x : v) cout << x << " ";

    return 0;
} 