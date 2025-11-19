#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long swapNum(long long x)
{
    long long ret = 0;

    while (x > 0)
    {
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }

    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> arr(n);
    for (auto &x : arr) cin >> x;

    vector<long long> vec;
    for (auto x : arr) vec.push_back(swapNum(x));

    sort(vec.begin(), vec.end());
    for (auto x : vec) cout << x << "\n";

    return 0;
}