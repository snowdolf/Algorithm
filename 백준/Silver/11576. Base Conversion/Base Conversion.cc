#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, m;

    cin >> a >> b >> m;
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        sum *= a;
        sum += x;
    }

    vector<int> result;
    while (sum > 0)
    {
        result.push_back(sum % b);
        sum /= b;
    }
    reverse(result.begin(), result.end());

    for (auto x : result) cout << x << " ";

    return 0;
}