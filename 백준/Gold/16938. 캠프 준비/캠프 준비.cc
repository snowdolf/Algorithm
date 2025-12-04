#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, r, x;
    cin >> n >> l >> r >> x;

    vector<int> problems(n);
    for (auto &x : problems) cin >> x;
    sort(problems.begin(), problems.end());

    long long ans = 0;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0, cnt = 0, a = 1e9, b = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                sum += problems[j];
                cnt++;
                a = min(a, problems[j]);
                b = max(b, problems[j]);
            }
        }
        if (cnt >= 2 && l <= sum && sum <= r && (b - a) >= x) ans++;
    }

    cout << ans << "\n";

    return 0;
}