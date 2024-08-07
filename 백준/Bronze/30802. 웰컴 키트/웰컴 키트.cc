#include <iostream>

using namespace std;

int n, a[6], t, p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < 6; i++)cin >> a[i];
    cin >> t >> p;

    int ans = 0;
    for(int i = 0; i <  6; i++)ans += (a[i] + t - 1) / t;
    cout << ans << "\n";

    ans = 0;
    for(int i = 0; i < 6; i++)ans += a[i];
    cout << ans / p << " " << ans % p;

    return 0;
}