#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (a < b) swap(a, b);

    vector<int> v;

    while (b > 0)
    {
        v.push_back((a % 10) + (b % 10));
        a /= 10;
        b /= 10;
    }

    while (a > 0)
    {
        v.push_back(a % 10);
        a /= 10;
    }

    reverse(v.begin(), v.end());
    for (auto x : v) cout << x;

    return 0;
}