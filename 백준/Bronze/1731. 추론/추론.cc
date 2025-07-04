#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    if (v[1] - v[0] == v[2] - v[1])
    {
        cout << v[n - 1] + v[1] - v[0];
    }
    else
    {
        cout << v[n - 1] * (v[1] / v[0]);
    }

    return 0;
}