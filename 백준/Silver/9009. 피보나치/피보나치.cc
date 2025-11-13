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

    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(2);
    while (1)
    {
        int next_fibo = fibo[fibo.size() - 1] + fibo[fibo.size() - 2];
        if (next_fibo > 1e9) break;
        fibo.push_back(next_fibo);
    }

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> result;

        while (n > 0)
        {
            int idx = upper_bound(fibo.begin(), fibo.end(), n) - fibo.begin() - 1;
            result.push_back(fibo[idx]);
            n -= fibo[idx];
        }

        reverse(result.begin(), result.end());
        for (auto &x : result) cout << x << " ";
        cout << "\n";
    }

    return 0;
}