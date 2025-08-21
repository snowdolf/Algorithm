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

    long long sum = 3*1e9;
    vector<int> ans(3);

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            long long cnt = v[i] + v[j];

            int k = lower_bound(v.begin() + j + 1, v.end(), -cnt) - v.begin();
            if (k < n && abs(cnt + v[k]) < abs(sum))
            {
                sum = cnt + v[k];
                ans = {i, j, k};
            }
            if (k - 1 > j && abs(cnt + v[k - 1]) < abs(sum))
            {
                sum = cnt + v[k - 1];
                ans = {i, j, k - 1};
            }
        }
    }

    for (auto x : ans) cout << v[x] << " "; 

    return 0;
}