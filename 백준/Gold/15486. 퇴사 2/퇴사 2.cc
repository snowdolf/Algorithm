#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, t, p;
int dt[1500010];
vector<pair<int, int>> v[1500010];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> t >> p;
        if (i + t - 1 <= n)
        {
            v[i + t - 1].push_back({t, p});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        dt[i] = dt[i - 1];
        for (int j = 0; j < v[i].size(); j++)
        {
            dt[i] = max(dt[i], dt[i - v[i][j].first] + v[i][j].second);
        }
    }

    cout << dt[n];

    return 0;
}