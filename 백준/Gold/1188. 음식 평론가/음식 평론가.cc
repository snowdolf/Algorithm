#include <iostream>

using namespace std;

int cal(int f, int p)
{
    if (f == 0) return 0;
    if (f >= p) return cal(f % p, p);
    return f + cal(f, p - f);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    cout << cal(n, m) << "\n";

    return 0;
}