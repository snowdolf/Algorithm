#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        vec.assign(n, {0, 0});
        for (int i = 0; i < n; i++)
            cin >> vec[i].first >> vec[i].second;
        sort(vec.begin(), vec.end());

        int ans = 1, cnt = vec[0].second;

        for (int i = 1; i < n; i++)
        {
            if (vec[i].second < cnt)
            {
                ans++;
                cnt = vec[i].second;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}