#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<float> vf;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vf.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vf[i];
    }

    sort(vf.begin(), vf.end());

    cout.precision(3);
    cout << fixed;

    for (int i = 0; i < 7; i++)
    {
        cout << vf[i] << "\n";
    }

    return 0;
}