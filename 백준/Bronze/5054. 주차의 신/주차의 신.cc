#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for (auto &x : v) cin >> x;
        sort(v.begin(), v.end());
        cout << 2 * (v[n - 1] - v[0]) << "\n";
    }

    return 0;
}