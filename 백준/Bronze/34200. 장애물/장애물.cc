#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v) cin >> x;

    int ans = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (pos > v[i] - 1)
        {
            ans = -1;
            break;
        }
        ans += (v[i] - pos) / 2;

        pos = v[i] - 1;
        ans++;
        pos += 2;
    }
    cout << ans << "\n";

    return 0;
}