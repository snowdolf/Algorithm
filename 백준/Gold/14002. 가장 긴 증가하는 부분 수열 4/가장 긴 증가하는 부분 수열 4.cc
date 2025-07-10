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
    for (int &x : a) cin >> x;

    vector<int> lisTail, lisIdx, prevIdx(n, -1);
    lisTail.push_back(a[0]);
    lisIdx.push_back(0);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > lisTail.back())
        {
            prevIdx[i] = lisIdx.back();
            lisTail.push_back(a[i]);
            lisIdx.push_back(i);
        }
        else
        {
            auto it = lower_bound(lisTail.begin(), lisTail.end(), a[i]);
            int idx = it - lisTail.begin();
            prevIdx[i] = idx > 0 ? lisIdx[idx - 1] : -1;
            lisTail[idx] = a[i];
            lisIdx[idx] = i;
        }
    }

    cout << lisIdx.size() << "\n";

    vector<int> ans;
    for (int i = lisIdx.back(); i != -1; i = prevIdx[i]) ans.push_back(a[i]);
    reverse(ans.begin(), ans.end());

    for (int i : ans) cout << i << " ";

    return 0;
}