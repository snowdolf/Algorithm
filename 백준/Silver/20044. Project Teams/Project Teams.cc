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

    vector<int> w(2 * n);
    for (auto &x : w) cin >> x;
    sort(w.begin(), w.end());

    int ans = 200000;
    for (int i = 0; i < n; i++)
    {
        int tmp = w[i] + w[2 * n - 1 - i];
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
    

    return 0;
}