#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        v.insert(v.begin() + m, i);
    }

    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << " ";

    return 0;
}