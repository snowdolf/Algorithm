#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, n;
    cin >> a >> b >> n;

    int ans = abs(b - a);
    while (n--)
    {
        int x;
        cin >> x;

        ans = min(ans, abs(b - x) + 1);
    }
    cout << ans << "\n";

    return 0;
}