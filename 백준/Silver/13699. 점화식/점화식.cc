#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);
    v[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            v[i] += v[j] * v[i - 1 - j];
        }
    }
    cout << v[n];

    return 0;
}