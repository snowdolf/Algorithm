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

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b, bIdx, prevIdx(n, 0);
    b.push_back(a[0]);
    bIdx.push_back(0);
    prevIdx[0] = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > b.back())
        {
            b.push_back(a[i]);
            bIdx.push_back(i);
            prevIdx[i] = bIdx[b.size() - 2];
        }
        else
        {
            auto it = lower_bound(b.begin(), b.end(), a[i]);
            b[it - b.begin()] = a[i];
            bIdx[it - b.begin()] = i;
            prevIdx[i] = it - b.begin() > 0 ? bIdx[it - b.begin() - 1] : -1;
        }
    }

    cout << b.size() << "\n";

    vector<int> ans;
    for (int i = bIdx.back(); i != -1; i = prevIdx[i]) ans.push_back(i);
    reverse(ans.begin(), ans.end());

    for (int i : ans) cout << a[i] << " ";

    return 0;
}