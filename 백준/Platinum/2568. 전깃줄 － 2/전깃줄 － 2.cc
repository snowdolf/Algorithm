#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    v.resize(n);
    for (auto &x : v) cin >> x.first >> x.second;
    sort(v.begin(), v.end());

    vector<int> lisTail, lisIdx, lisPrevIdx(n, -1);
    lisTail.push_back(v[0].second);
    lisIdx.push_back(0);

    for (int i = 1; i < n; i++)
    {
        if (v[i].second > lisTail.back())
        {
            lisPrevIdx[i] = lisIdx.back();
            lisTail.push_back(v[i].second);
            lisIdx.push_back(i);
        }
        else
        {
            auto it = lower_bound(lisTail.begin(), lisTail.end(), v[i].second);
            int idx = it - lisTail.begin();
            lisPrevIdx[i] = idx ? lisIdx[idx - 1] : -1;
            lisTail[idx] = v[i].second;
            lisIdx[idx] = i;
        }
    }

    vector<int> lis;
    for (int i = lisIdx.back(); i != -1; i = lisPrevIdx[i]) lis.push_back(v[i].first);
    reverse(lis.begin(), lis.end());

    vector<int> ans;
    for (auto [x, _] : v) if (!binary_search(lis.begin(), lis.end(), x)) ans.push_back(x);

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";

    return 0;
}