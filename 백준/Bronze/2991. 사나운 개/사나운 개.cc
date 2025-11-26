#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, p, m, n;
    cin >> a >> b >> c >> d >> p >> m >> n;

    int ans = 0;
    if (p % (a + b) && p % (a + b) <= a) ans++;
    if (p % (c + d) && p % (c + d) <= c) ans++;
    cout << ans << "\n";

    ans = 0;
    if (m % (a + b) && m % (a + b) <= a) ans++;
    if (m % (c + d) && m % (c + d) <= c) ans++;
    cout << ans << "\n";

    ans = 0;
    if (n % (a + b) && n % (a + b) <= a) ans++;
    if (n % (c + d) && n % (c + d) <= c) ans++;
    cout << ans << "\n";

    return 0;
}