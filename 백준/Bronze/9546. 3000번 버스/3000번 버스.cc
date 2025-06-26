#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(31);
    v[1] = 1;
    for (int i = 2; i <= 30; i++) v[i] = 2 * v[i - 1] + 1;

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n] << '\n';
    }

    return 0;
}