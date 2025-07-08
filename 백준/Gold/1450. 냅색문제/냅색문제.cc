#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

void calculatePrefixSum(int idx, ll sum, int c, const vector<int>& a, vector<ll>& prefixSum)
{
    if (idx >= a.size() / 2)
    {
        prefixSum.push_back(sum);
        return;
    }
    calculatePrefixSum(idx + 1, sum, c, a, prefixSum);
    if (sum + a[idx] <= c)
    {
        calculatePrefixSum(idx + 1, sum + a[idx], c, a, prefixSum);
    }
}

void solve(int idx, ll sum, int c, const vector<int>& a, const vector<ll>& prefixSum, ll& ans)
{
    if (idx >= a.size())
    {
        auto it = upper_bound(prefixSum.begin(), prefixSum.end(), c - sum);
        ans += it - prefixSum.begin();
        return;
    }
    solve(idx + 1, sum, c, a, prefixSum, ans);
    if (sum + a[idx] <= c)
    {
        solve(idx + 1, sum + a[idx], c, a, prefixSum, ans);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> prefixSum;
    calculatePrefixSum(0, 0, c, a, prefixSum);
    sort(prefixSum.begin(), prefixSum.end());

    ll ans = 0;
    solve(n / 2, 0, c, a, prefixSum, ans);

    cout << ans;

    return 0;
}