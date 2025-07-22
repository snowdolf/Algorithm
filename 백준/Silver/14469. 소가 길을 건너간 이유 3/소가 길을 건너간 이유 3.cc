#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> cow(n);
    for (auto &x : cow) cin >> x.first >> x.second;
    sort(cow.begin(), cow.end());

    int t = 0;

    for (auto &x : cow)
    {
        if (t < x.first) t = x.first;
        t += x.second;
    }

    cout << t;

    return 0;
}