#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, w, n, m;
    cin >> h >> w >> n >> m;

    cout << (1 + (h - 1) / (n + 1)) * (1 + (w - 1) / (m + 1)) << "\n";

    return 0;
}