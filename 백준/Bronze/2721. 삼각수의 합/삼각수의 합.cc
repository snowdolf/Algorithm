#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<long long> w(305, 0);
    for (int i = 1; i <= 300; i++)
    {
        w[i] = i * (i + 1) * (i + 2) / 2;
        w[i] += w[i - 1];
    }

    while (t--)
    {
        int n;
        cin >> n;
        cout << w[n] << "\n";
    }

    return 0;
}