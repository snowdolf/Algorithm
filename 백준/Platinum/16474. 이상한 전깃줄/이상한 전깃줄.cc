#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int ln, rn, k;
vector<int> lv, rv;
unordered_map<int, int> lmap, rmap;
vector<vector<int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> ln >> rn;
    lv.resize(ln);
    for (int i = 0; i < ln; i++)
    {
        cin >> lv[i];
        lmap[lv[i]] = i;
    }
    rv.resize(rn);
    for (int i = 0; i < rn; i++)
    {
        cin >> rv[i];
        rmap[rv[i]] = i;
    }

    cin >> k;
    v.resize(ln);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        l = lmap[l];
        r = rmap[r];
        v[l].push_back(r);
    }

    vector<int> dp(rn, 0);
    for (auto &l : v)
    {
        sort(l.begin(), l.end(), greater<int>());
        for (auto &r : l)
        {
            int tmp = r ? dp[r - 1] : 0;
            dp[r] = max(dp[r], tmp + 1);
        }
        for (int i = 1; i < rn; i++) dp[i] = max(dp[i], dp[i - 1]);
    }

    cout << k - dp[rn - 1] << '\n';

    return 0;
}