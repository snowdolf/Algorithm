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

    vector<int> lisTail;
    lisTail.push_back(v[0]);

    for (int i = 1; i < n; i++)
    {
        if (v[i] > lisTail.back())
        {
            lisTail.push_back(v[i]);
        }
        else
        {
            auto it = lower_bound(lisTail.begin(), lisTail.end(), v[i]);
            int idx = it - lisTail.begin();
            lisTail[idx] = v[i];
        }
    }

    cout << n - lisTail.size();

    return 0;
}