#include <iostream>

using namespace std;

int n, m, k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    cout << k / m << " " << k % m;

    return 0;
}